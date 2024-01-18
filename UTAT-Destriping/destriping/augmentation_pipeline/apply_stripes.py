"""
apply_stripes.py.
Contains fucntions to load a 'ground truth' data cube and add stripes/noise
Author(s): 
"""

# Based on https://www.sciencedirect.com/science/article/pii/S0031320323005307?via%3Dihub, Section 3.1

# Imports
import numpy as np
from scipy.io import loadmat
import matplotlib.pyplot as plt
import os
import copy

def load_data_cube(mat_file_name, data_cube_name):
    '''
    Loads a data cube from a MAT file.

    Args:
        mat_file_name (str): Name of the MAT file.
        data_cube_name (str): Name of the data cube in the MAT file.

    Returns:
        numpy.ndarray: Loaded data cube.
    '''
    current_dir = os.path.dirname(os.path.realpath(__file__))
    mat_file_path = os.path.join(current_dir, '..', '..', 'datasets', mat_file_name)
    mat_contents = loadmat(mat_file_path)
    return np.array(mat_contents[data_cube_name]).astype(float)


def create_stripe_mask(data_cube, stripe_frequency):
    '''
    Creates a stripe mask for random sparse stripes.

    Args:
        data_cube (numpy.ndarray): Original data cube.
        stripe_frequency (float): Frequency of the stripes.

    Returns:
        numpy.ndarray: stripe mask with sparse stripes.
    '''
    stripe_mask = np.zeros((data_cube.shape[1], data_cube.shape[2]))
    for i in range(data_cube.shape[2]):
        is_noise = np.random.rand(data_cube.shape[1]) < stripe_frequency
        stripe_mask[is_noise, i] = 1
    return stripe_mask

def add_sparse_stripes(data_cube, stripe_intensity, stripe_frequency):
    '''
    Adds sparse stripes with given intensity and frequency to a data cube.

    Args:
        data_cube (numpy.ndarray): Original data cube.
        stripe_intensity (float): Intensity of the stripes.
        stripe_frequency (float): Frequency of the stripes.

    Returns:
        numpy.ndarray: Data cube with added stripes.
    '''
    striped_data_cube = copy.deepcopy(data_cube)
    stripe_mask=create_stripe_mask(data_cube,stripe_frequency)
    for i in range(data_cube.shape[2]):
        for j in range(data_cube.shape[1]):
            striped_data_cube[:,j,i] += stripe_mask[j,i]*stripe_intensity*(np.max(data_cube[:,:,i]) - np.min(data_cube[:,:,i]))
    return striped_data_cube

def add_gaussian_noise(data_cube, noise_intensity):
    '''
    Adds Gaussian noise with given intensity to a data cube.

    Args:
        data_cube (numpy.ndarray): Original data cube.
        noise_intensity (float): Intensity of the Gaussian noise.

    Returns:
        numpy.ndarray: Data cube with added Gaussian noise.
    '''
    striped_data_cube = copy.deepcopy(data_cube)
    for i in range(data_cube.shape[2]):
        gaussian_noise = np.random.normal(scale=noise_intensity * (np.max(data_cube[:,:,i]) - np.min(data_cube[:,:,i])), size=data_cube.shape[:2])
        striped_data_cube[:, :, i] += gaussian_noise
    return striped_data_cube

def show_modified_images(data_cube, spectral_index):
    '''
    Displays modified images with example various noise and stripe parameters.

    Args:
        data_cube (numpy.ndarray): Original data cube.
        spectral_index (int): Spectral index to display.

    Returns:
        None
    '''
    fig, axes = plt.subplots(3, 5, figsize=(15, 9))
    noise_intensities = [0, 0.05, 0.1]
    stripe_params = [(0, 0), (0.05, 0.25), (0.05, 0.50), (0.2, 0.25), (0.2, 0.50)]

    for i, noise_intensity in enumerate(noise_intensities):
        for j, (stripe_intensity, stripe_frequency) in enumerate(stripe_params):
            modified_data_cube = copy.deepcopy(data_cube)
            modified_data_cube = add_gaussian_noise(modified_data_cube, noise_intensity)
            modified_data_cube = add_sparse_stripes(modified_data_cube, stripe_intensity, stripe_frequency)

            axes[i, j].imshow(modified_data_cube[:, :, spectral_index], cmap="gray")
            axes[i, j].set_title(f'Noise: {noise_intensity}, Stripes: {stripe_intensity}, Freq: {stripe_frequency}')
            axes[i, j].axis('off')

    fig.suptitle(f'Modified Images for Spectral Index {spectral_index}')
    plt.tight_layout()
    plt.show()

# Loading the 100th spectral image
data_cube = load_data_cube('Indian_pines_corrected.mat', 'indian_pines_corrected')
show_modified_images(data_cube, 100)
