import ctypes
import matplotlib.pyplot as plt

# Load the shared library
slope = ctypes.CDLL('./slope.so')

# Define the argument and return types of the C function
slope.findFourthVertex.argtypes = [ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.c_double, ctypes.POINTER(ctypes.c_double), ctypes.POINTER(ctypes.c_double)]

def find_fourth_vertex(x1, y1, x2, y2, x3, y3):
    x4 = ctypes.c_double()
    y4 = ctypes.c_double()
    slope.findFourthVertex(x1, y1, x2, y2, x3, y3, ctypes.byref(x4), ctypes.byref(y4))
    return x4.value, y4.value

# Coordinates of the three vertices
x1, y1 = 1, 3
x2, y2 = -1, 2
x3, y3 = 2, 5

# Calculate the fourth vertex
x4, y4 = find_fourth_vertex(x1, y1, x2, y2, x3, y3)

# Print the fourth vertex
print(f"The coordinates of the fourth vertex are ({x4:.2f}, {y4:.2f})")

# Plot the parallelogram
plt.figure()
plt.plot([x1, x2, x3, x4, x1], [y1, y2, y3, y4, y1], 'bo-')  # Blue line with circle markers
plt.fill([x1, x2, x3, x4], [y1, y2, y3, y4], 'lightgray', alpha=0.5)  # Fill with light gray
plt.text(x1, y1, 'A', fontsize=12, ha='right')
plt.text(x2, y2, 'B', fontsize=12, ha='right')
plt.text(x3, y3, 'C', fontsize=12, ha='right')
plt.text(x4, y4, 'D', fontsize=12, ha='right')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Parallelogram')
plt.grid(True)
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.gca().set_aspect('equal', adjustable='box')
plt.show()

