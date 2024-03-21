from PIL import Image
import os

# Function to crop images to central 128x128 pixels
def crop_to_central_128x128(image_path, output_folder):
    # Open the image
    img = Image.open(image_path)
    
    # Get dimensions of the image
    width, height = img.size
    
    # Calculate the cropping coordinates
    left = (width - 128) // 2
    top = (height - 128) // 2
    right = left + 128
    bottom = top + 128
    
    # Crop the image
    cropped_img = img.crop((left, top, right, bottom))
    
    # Save the cropped image
    cropped_img.save(os.path.join(output_folder, os.path.basename(image_path)))

# Path to the folder containing images
input_folder = r'C:\Users\hecto\Documents\GitHub\FINCH-destriping-main\destriping\models\ddpm-testing\noisy'

# Output folder to save cropped images
output_folder = r'C:\Users\hecto\Documents\GitHub\FINCH-destriping-main\destriping\models\ddpm-testing\noisy2'

# Ensure the output folder exists
os.makedirs(output_folder, exist_ok=True)

# Iterate over each image in the input folder
for filename in os.listdir(input_folder):
    if filename.endswith('.jpg') or filename.endswith('.png'):
        # Full path to the image
        image_path = os.path.join(input_folder, filename)
        
        # Crop the image and save it to the output folder
        crop_to_central_128x128(image_path, output_folder)
