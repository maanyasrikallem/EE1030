import ctypes
import numpy as np
import matplotlib.pyplot as plt

# Load the shared library
lib = ctypes.CDLL('./func.so')

# Circle parameters
h, k = 0, -3  # Center of the circle
r = 4         # Radius

# Point to check
point = (1, 2)

# Create circle points
theta = np.linspace(0, 2 * np.pi, 100)
x_circle = h + r * np.cos(theta)
y_circle = k + r * np.sin(theta)

# Plotting
plt.figure(figsize=(8, 8))
plt.plot(x_circle, y_circle, label='Circle', color='blue')
plt.scatter(*point, color='red', label='Point P')

# Marking the point as P
plt.text(point[0], point[1], ' P', fontsize=12, verticalalignment='bottom')

# Marking centre 
plt.scatter(h, k, color='green', label='Centre (C)')
plt.text(h, k, ' C', fontsize=12, verticalalignment='bottom', horizontalalignment='right', color='green') 

# Setting limits and labels
plt.xlim(-5, 5)
plt.ylim(-7, 5)
plt.axhline(0, color='black', lw=0.5, ls='--')
plt.axvline(0, color='black', lw=0.5, ls='--')
plt.title('Circle and Point Position')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.grid()
plt.legend()
plt.gca().set_aspect('equal')  # Equal aspect ratio
plt.show()

