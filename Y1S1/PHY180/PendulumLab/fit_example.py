# Sample Python code to run the fit_black_box Python code relatively easily

import fit_black_box as bb
import numpy as np

# First, define the function you want to fit. Here it's a linear function.
# It is critical that the independant variable ("t") is first in the list of function variables.

# def linear(t, m, b):
#     return m*t + b

# Next, generate your data and errorbars. One way is to manually insert it here.

# x = bb.np.array([0,1,2,3,4,5,6])
# y = bb.np.array([0.1,0.9,2.1,2.9,4.1,4.9,6.1])
# xerr = 0.05
# yerr = bb.np.array([0.01,0.02,0.03,0.04,0.05,0.06,0.07])

# Note that xerr and yerr can either be an array of the same length as x&y, or a single value


# Now we make the plot, displayed on screen and saved in the directory, and print the best fit values

# bb.plot_fit(linear, x, y, xerr, yerr)


# Let's try again, this time loading from a file like a CSV file.
# NOTE: The CSV file should not have commas to separate things! Spaces or tabs are fine.

# Again, start with a fitting function. This time it is quadratic.

def power(t, q, w, d, a, b, c):
    return q*t**5+w*t**4+d*t**3+a*t**2 + b*t + c

def sinusoidal(t, init_angle, time_constant, period, phi):
    return init_angle*np.exp(-t/time_constant)*np.cos(2*np.pi*t/period+phi)


def exponential(t, k, n):
    return k*t**n

def lin(t, c,d):
    return c*(t) + d

# Now load the data from the file. The file should be in the same directory as this Python code.
# Some chance you will need an absolute path: "C:\\Users\\Brian\\Python\\mydata_fake.txt"

filename="C:\\Users\\hecto\\Downloads\\PendulumLab\\data.txt"
x, y, xerr, yerr = bb.load_data(filename)

# This time, let's use every single possible option available to bb.plot_fit()

# init_guess = (0.4, 25, 1.1, 1.4)
# font_size = 20
# xlabel = "Time (s)"
# ylabel = "Angle (rad)"

# init_guess = (0,0,0, 0,0,0)
# font_size = 20
# xlabel = "Release Angle (rad)"
# ylabel = "Period (s)"

# init_guess = (2, 0.5)
# font_size = 20
# xlabel = "Length (m)"
# ylabel = "Period (s)"

init_guess = (60, 220)
font_size = 20
xlabel = "Length (m)"
ylabel = "Q Factor"

# init_guess = (0.5, 0.2)
# font_size = 20
# xlabel = "log(Length) log(m)"
# ylabel = "log(Period) log(s)"

# Now we make the plot, displayed on screen and saved in the directory, and print the best fit values
# bb.plot_fit(sinusoidal, x, y, xerr, yerr, init_guess=init_guess, font_size=font_size,
#         xlabel=xlabel, ylabel=ylabel)

# bb.plot_fit(power, x, y, xerr, yerr, init_guess=init_guess, font_size=font_size,
#             xlabel=xlabel, ylabel=ylabel)

# bb.plot_fit(exponential, x, y, xerr, yerr, init_guess=init_guess, font_size=font_size,
#         xlabel=xlabel, ylabel=ylabel)

bb.plot_fit(lin, x, y, xerr, yerr, init_guess=init_guess, font_size=font_size,
            xlabel=xlabel, ylabel=ylabel)

# Note: for sinusoidal functions, guessing the period correctly with init_guess is critical

