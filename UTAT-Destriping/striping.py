import numpy as np
import matplotlib.pyplot as plt
import copy
from scipy.io import loadmat


# ASK ABOUT THIS
# https://www.sciencedirect.com/science/article/pii/S0031320323005307?via%3Dihub, 3.2







# References
# https://www.mdpi.com/2072-4292/6/11/11082, Section 2.1
# https://www.sciencedirect.com/science/article/pii/S0031320323005307, Section 3.1
# https://www.mdpi.com/2072-4292/13/24/5126, Section 2


# Striping Magnitude: Sensor Independent (Additive). Types: Gaussian, Binary Mask
# Stripe Direction: Parallel to direction of motion.

def gaussian_stripe(data_cube, noise_level):
    # Reference: https://www.mdpi.com/2072-4292/6/11/11082, Section 2.1
    # Direction: invariant per scene or within a short time span (Parallel to direction of motion)
        # Noise is additive
    # Magnitude: Sensor independent White Gaussian Noise (0 mean and specific standard deviations)
        # Dark current varies Gaussianly
        #  0 Mean, 1 Standard Deviation. Rescaled later
        # four different striping scenarios, scales are standard deviations of 0.1%, 0.5%, 1% and 5% of individual band's range
    data=copy.deepcopy(data_cube)
    for i in range(data.shape[2]):
        mean=0
        range_value=np.max(data[:,:,i])-np.min(data[:,:,i])
        std_dev=np.array([0.001, 0.005, 0.01, 0.05])*range_value
        # Choose std_dev
        deviation=std_dev[noise_level]
        noise=np.random.normal(mean, deviation, data.shape[1])
        noise=np.tile(noise, (data.shape[0],1))
        data[:,:,i]+=noise
    return data



def binary_stripe(data_cube, stripe_frequency, noise_range_scaling):
    # Stripe is there or it isn't.
    data=copy.deepcopy(data_cube)
    for i in range(data.shape[2]):
        stripe_intensity=(np.max(data[:,:,i])-np.min(data[:,:,i]))*noise_range_scaling
        # Half frequency positive. Half frequency negative.

        # Positive Stripes
        is_noise=np.random.rand(data.shape[1])<stripe_frequency/2
        noise=np.tile(np.where(is_noise, stripe_intensity, 0), (data.shape[0],1))

        # Negative Stripes
        is_noise=np.random.rand(data.shape[1])<stripe_frequency/2
        noise+=np.tile(np.where(is_noise, -stripe_intensity, 0), (data.shape[0],1))
        data[:,:,i]+=noise

    return data

def show_images(data_cube, stripe_func1=gaussian_stripe, stripe_func2=binary_stripe):
    max_index = data_cube.shape[2]
    index = np.random.randint(0, max_index - 1)

    original_image = data_cube[:, :, index]

    # Display the original image
    plt.figure(figsize=(12, 12))

    plt.subplot(3, 3, 1)
    plt.imshow(original_image, cmap="gray")
    plt.title("Original Image")
    plt.axis('off')

    # Loop through different levels of Gaussian striping
    for i, noise_level in enumerate([0, 1, 2, 3]):
        # Apply Gaussian stripe
        striped_image = stripe_func1(data_cube, noise_level)[:, :, index]
        plt.subplot(3, 3, i + 2)
        plt.imshow(striped_image, cmap="gray")
        plt.title(f"Gaussian Stripe {noise_level}")
        plt.axis('off')

    # Loop through different values of binary striping
    for i, stripe_frequency in enumerate([0.2, 0.4, 0.6]):
        # Apply binary stripe
        striped_image = stripe_func2(data_cube, stripe_frequency, 0.2)[:, :, index]
        plt.subplot(3, 3, i + 6)
        plt.imshow(striped_image, cmap="gray")
        plt.title(f"Binary Stripe {stripe_frequency}")
        plt.axis('off')

    plt.show()

# Example usage:
mat_file_path = 'C:/Users/hecto/Downloads/Indian_pines_corrected.mat'
mat_contents = loadmat(mat_file_path)
random_cube = np.array(mat_contents['indian_pines_corrected']).astype(float)

# Show images with different striping levels
show_images(random_cube)
show_images(random_cube)
show_images(random_cube)
show_images(random_cube)



### UTAT Space Systems
# - UTAT Space Systems: Weekly Meetings (Saturday 3:10-4:00PM, BA2165)
# - FINCH (Field Imaging Nanosatellite for Crop residue Hyperspectral mapping) Mission
# 	- Hyperspectral Image: Data cube where each image pixel has a spectrum (Wavelength vs Intensity Graph).
# 	- Pushbroom Scanner: Linear array of sensor perpendicular to motion


# [jipperspippers/FINCH-destriping: The destriping project repository. (github.com)](https://github.com/jipperspippers/FINCH-destriping)

# - Goal: Removing push broom scanner striping artefacts

# Methodology
# - Start with ground images and add striped noise
# 	- 
# - Train machine learning on clear/noisy pairs to remove noise
# - Denoising, inpainting, super-resolution of hyperspectral image data with CNNs/Diffusion Models


# - Causes of striping
# 	- Sensor independent: Thermally induced dark current, causing random movement of electrons (Sensors work when photons excite electrons, photoelectric effect)
# 		- Variations are Gaussian distributed (Gaussian White Noise) and sensor independent
# 	- Change in Sensor Gains: Sensor Sensitivity




# one pixel, changes by dark current. line parallel to time axis. point in spectral/space axis

# - Questions
# 	- What exactly causes stripes and where exactly do they occur (what direction on the cube)
# 		- Will the noise only be across the images perpendicular to the motion of the satellite
# 		- Do the stripes occur at the same places for different frequencies are are they all independently striped
# 	- Does the denoising process remove all stripes/artefacts through all 3 dimension of the image cube?
# 		- Stripe along time dimension: individual sensor for a wavelength breaks for a long time
# 		- Stripe along space dimension: all sensor for a wavelength break briefly
# 		- Stripe along spectral dimension: all wavelengths blocked for a sensor briefly
# 	- Does the denoising process take into account the data from similar frequencies or only within one frequency
# 		- 2D vs 3D Convolutions
# 	- Which papers are we following right now?
# 		- What process are we trying to do? just anything?

# - Neural Networks
# 	- Input Layer
# 		- Array of Input Values
# 	- Hidden Layers
# 		- Weights matrix $W$ with input vector $a^{(i-1)}$ plus bias vector $b$
# 			- Inputs get multiplied by first row in matrix and summed plus first value in bias vector > Output of first node/neuron in hidden layer
# 		- Pass through activation function $\sigma$ for output (Adds nonlinearity)
# 		- $a^{(i)}=\sigma(Wa^{(i-1)}+b)$
# 	- Output Layer
# 		- Array of output values (Multiple Neurons: Classification, Single Neuron: Prediction)
# 		- Forward Pass: Prediction compared to true value
# 			- Cost/Loss Function. Sum of squares of difference of output values and true values.
# 			- Average of all loss functions over all images is a measure of the neural network's quality
# 				- Cost function takes in vector of all weights and biases $C(W, b)$. 'Gradient Descent'
# 		- Backpropagation: Work backwards in layers to correct values that contribute most to error
# 			- Change W by factor of $-\nabla C(W, b)$ (Nudge weights/biases towards area of minimum cost with calculus)
# 			- Gradient Descent: Optimization of network weights by looking for local minima
# 				- Get differences between output and required
# 					-  $a^{(i)}=\sigma(Wa^{(i-1)}+b)$
# 					- Nudge bias towards direction.  $b$
# 					- Nudge weights towards direction (proportional to the output from previous layer it multiplies) $W$
# 					- Nudge previous output towards direction (proportional to weight) by repeating process for previous layer neurons
# 					- Nudges for all neurons from all outputs are added and implemented proportional by how much it needs to change
# 			- Divide data into mini-batches and do a step for each batch for faster computation (Stochastic gradient descent)
# 	- Convolutional Neural Networks
# 		- Convolution: Applying a kernel across an image array
# 			- Kernels that slide across data to detect desired patterns
# 			- Kernel matrix Hadamard product chunks of data matrix to get desired patterns
# 				- Symmetric kernels can blur images
# 				- Asymmetric kernels can detect asymmetry in images
# 		- Convolutions: Addition of probability density functions
# 			- $[f*g](s)=\int_{-\infty}^{\infty} f(x)g(s-x)dx$. s is the sum of the input of f and g
# 			- Graph of z=f(x)g(y) across slice y=s-x
# 			- Central Limit Theorem: Convoluting a (finite variance) distribution function with itself several times will approach the normal curve
# 		- Input Layer: Image
# 		- Feature Extraction (Abstraction): Smaller image size, more nodes/features
# 			- Convolution Layer: Random Convolution of the Image
# 				- Increases the number of nodes
# 			- Pooling Layer: Only keep most important convolutions
# 				- Shrinks size of images
# 		- Output Layer: Large amount of nodes each one pixel of information
# 		- Put output layer into traditional neural network
# - Diffusion Models
# 	- Add gaussian noise via Markov Chain (current step only depends on previous step)
# 	- Learning how to reverse process, to get clear images from noise
# 		- Reverse process uses CNNs to use more noisy image to get less noisy image
# 		- CNNs. Abstract noisy image the expand image to obtain less noisy image


