import os
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
from torchvision import transforms
from PIL import Image
import matplotlib.pyplot as plt  # Importing Matplotlib

class DenoisingModel(nn.Module):
    def __init__(self):
        super(DenoisingModel, self).__init__()
        self.encoder = nn.Sequential(
            nn.Conv2d(3, 32, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(32, 32, kernel_size=3, padding=1),
            nn.ReLU(inplace=True),
            nn.Conv2d(32, 3, kernel_size=3, padding=1)
        )

    def forward(self, x):
        return self.encoder(x)

class CustomDataset(Dataset):
    def __init__(self, root_dir, transform=None):
        self.root_dir = root_dir
        self.transform = transform
        self.noisy_image_paths = [os.path.join(root_dir, "noisy", f) for f in os.listdir(os.path.join(root_dir, "noisy"))]
        self.clean_image_paths = [os.path.join(root_dir, "clean", f) for f in os.listdir(os.path.join(root_dir, "clean"))]

    def __len__(self):
        return min(len(self.noisy_image_paths), len(self.clean_image_paths))

    def __getitem__(self, idx):
        clean_img = Image.open(self.clean_image_paths[idx]).convert('RGB')
        noisy_img = Image.open(self.noisy_image_paths[idx]).convert('RGB')

        if self.transform:
            clean_img = self.transform(clean_img)
            noisy_img = self.transform(noisy_img)

        return noisy_img, clean_img


def train_model(model, criterion, optimizer, dataloader, num_epochs=10):
    print("Training started...")
    for epoch in range(num_epochs):
        print(f"Epoch [{epoch+1}/{num_epochs}]")
        for batch_idx, (noisy_images, clean_images) in enumerate(dataloader):
            optimizer.zero_grad()
            outputs = model(noisy_images)
            loss = criterion(outputs, clean_images)
            loss.backward()
            optimizer.step()
            if (batch_idx + 1) % 10 == 0:
                print(f'Batch [{batch_idx+1}/{len(dataloader)}], Loss: {loss.item()}')
    print("Training completed.")

def save_model(model, path="destriping/models/ddpm-testing/denoising_model.pth"):
    print(f"Saving trained model to {path}...")
    torch.save(model, path)
    print("Trained model saved.")

def load_model(path="destriping/models/ddpm-testing/denoising_model.pth"):
    try:
        print(f"Loading pre-trained model from {path}...")
        model = torch.load(path)
        print("Pre-trained model loaded.")
        return model
    except FileNotFoundError:
        print(f"No pre-trained model found at {path}. Training a new model...")
        return None

def denoise_image(model, noisy_image_path, transform):
    noisy_img = Image.open(noisy_image_path).convert('RGB')
    noisy_img = transform(noisy_img).unsqueeze(0)  
    with torch.no_grad():
        clean_img = model(noisy_img)
    return clean_img.squeeze(0)  

if __name__ == "__main__":
    load_pretrained_model = False  # Set this to True if you want to load a pre-trained model

    transform = transforms.Compose([
        transforms.CenterCrop((200, 200)),  # Crop the central 200x200 region
        transforms.ToTensor(),  
    ])

    root_dir = "destriping/models/ddpm-testing"

    dataset = CustomDataset(root_dir, transform=transform)
    dataloader = DataLoader(dataset, batch_size=32, shuffle=True)

    model = DenoisingModel()

    if load_pretrained_model:
        model = load_model()
        if model is None:
            # No pre-trained model found, so train a new one
            criterion = nn.MSELoss()
            optimizer = optim.Adam(model.parameters(), lr=0.001)
            train_model(model, criterion, optimizer, dataloader)
            save_model(model)
    else:
        criterion = nn.MSELoss()
        optimizer = optim.Adam(model.parameters(), lr=0.001)
        train_model(model, criterion, optimizer, dataloader)
        save_model(model)

    noisy_image_path = "destriping/models/ddpm-testing/noisy/2s.png"
    clean_img = denoise_image(model, noisy_image_path, transform)

    clean_img_pil = transforms.ToPILImage()(clean_img)

    # Open original noisy image
    noisy_img_pil = Image.open(noisy_image_path)

    # Crop both images to 200x200
    noisy_img_pil = noisy_img_pil.crop((50, 50, 250, 250))
    clean_img_pil = clean_img_pil.crop((50, 50, 250, 250))

    # Plot both images side by side
    fig, axes = plt.subplots(1, 2, figsize=(10, 5))
    axes[0].imshow(noisy_img_pil)
    axes[0].set_title('Noisy Image')
    axes[0].axis('off')

    axes[1].imshow(clean_img_pil)
    axes[1].set_title('Denoised Image')
    axes[1].axis('off')

    plt.show()
