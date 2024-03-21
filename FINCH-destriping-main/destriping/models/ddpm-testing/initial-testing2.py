import os
from PIL import Image
from torchvision import transforms
import torch
from denoising_diffusion_pytorch import Unet, GaussianDiffusion, Trainer

folder_path = 'C:/Users/hecto/Documents/GitHub/FINCH-destriping-main/destriping/models/ddpm-testing/noisy2'
file_count = len([name for name in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, name))])
print("Number of files in folder:", file_count)

transform = transforms.Compose([
    transforms.Resize((128, 128)),
    transforms.ToTensor()
])

model = Unet(
    dim=64,
    dim_mults=(1, 2, 4, 8),
    flash_attn=True
)

diffusion = GaussianDiffusion(
    model,
    image_size=128,
    timesteps=10    # number of steps
)

trainer = Trainer(
    diffusion,
    folder_path,
    train_batch_size=20,
    train_lr=1e-4,
    train_num_steps=1000,
    gradient_accumulate_every=4,
    ema_decay=0.999,
    amp=True,
    calculate_fid=False
)

trainer.train()

checkpoint_path = 'C:/Users/hecto/Documents/GitHub/FINCH-destriping-main/destriping/models/ddpm-testing/model_checkpoint.pth'
torch.save({'model_state_dict': diffusion.state_dict()}, checkpoint_path)

# Reload the trained model
checkpoint = torch.load(checkpoint_path)
diffusion.load_state_dict(checkpoint['model_state_dict'])
diffusion.eval()

# Load or generate a single noisy image
noisy_image_path = 'C:/Users/hecto/Documents/GitHub/FINCH-destriping-main/destriping/models/ddpm-testing/noisy2/1s.jpg'
noisy_image = Image.open(noisy_image_path)
noisy_image_tensor = transform(noisy_image).unsqueeze(0)  # Add batch dimension

# Generate clean image from noisy image
with torch.no_grad():
    clean_image = diffusion.p_sample_q(noisy_image_tensor)
    
# Convert clean image tensor to PIL image
clean_image_pil = transforms.ToPILImage()(clean_image.squeeze(0).cpu())

# Define the path to save the clean image
clean_image_path = 'C:/Users/hecto/Documents/GitHub/FINCH-destriping-main/destriping/models/ddpm-testing/clean_image.jpg'

# Save the clean image
clean_image_pil.save(clean_image_path)

# Alternatively, if you want to display the clean image
clean_image_pil.show()
