import ctypes
import numpy as np
import matplotlib.pyplot as plt

# Load the shared library
lib = ctypes.CDLL('./func.so')

# Define the function signature for Mateigval
lib.Mateigval.argtypes = [ctypes.POINTER(ctypes.POINTER(ctypes.c_double))]
lib.Mateigval.restype = ctypes.POINTER(ctypes.POINTER(ctypes.c_double))

# Function to create a 2x2 matrix in C and return its eigenvalues
def get_eigenvalues(matrix):
    # Create a ctypes array for the matrix
    matrix_c = (ctypes.POINTER(ctypes.c_double) * 2)()
    for i in range(2):
        matrix_c[i] = (ctypes.c_double * 2)(*matrix[i])

    # Call the C function
    eigenvalues_c = lib.Mateigval(matrix_c)

    # Extract eigenvalues from the returned pointer
    eigenvalues = []
    for i in range(2):
        eigenvalues.append(eigenvalues_c[i][0])

    return eigenvalues

# Circle parameters
h, k = 0, -3  # Center of the circle
r = 4         # Radius

# Point to check
point = (1, 2)

# Calculate the distance from the point to the center of the circle
distance_squared = (point[0] - h) ** 2 + (point[1] - k) ** 2

# Determine if the point is inside or outside the circle
is_inside = distance_squared < r ** 2

# Create circle points
theta = np.linspace(0, 2 * np.pi, 100)
x_circle = h + r * np.cos(theta)
y_circle = k + r * np.sin(theta)

# Example 2x2 matrix to get eigenvalues
matrix = np.array([[4, 1], [2, 3]], dtype=np.float64)

# Get eigenvalues
eigenvalues = get_eigenvalues(matrix)
print("Eigenvalues:", eigenvalues)

# Plotting
plt.figure(figsize=(8, 8))
plt.plot(x_circle, y_circle, label='Circle', color='blue')
plt.scatter(*point, color='red', label='Point (1, 2)')

# Marking the point's status
status = "Inside" if is_inside else "Outside"
plt.text(point[0], point[1], f" {status}", fontsize=12, verticalalignment='bottom')

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

