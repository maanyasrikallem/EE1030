import matplotlib.pyplot as plt

# Function to read coordinates from a text file
def read_coordinates(filename):
    coordinates = {}
    with open(filename, 'r') as file:
        for line in file:
            parts = line.strip().split(':')
            label = parts[0].strip()
            coords = parts[1].strip().strip('()').split(', ')
            coordinates[label] = (float(coords[0]), float(coords[1]))
    return coordinates

# Read coordinates from the file
coords = read_coordinates('coordinates.txt')

# Extract coordinates
xA, yA = coords['A']
xB, yB = coords['B']
xC, yC = coords['C']
xD, yD = coords['D']

# Plotting the points and the parallelogram
plt.figure(figsize=(8, 8))
plt.plot([xA, xB, xC, xD, xA], [yA, yB, yC, yD, yA], 'bo-', label='Parallelogram ABCD')

# Annotate the points
plt.text(xA, yA, 'A', fontsize=12, ha='right')
plt.text(xB, yB, 'B', fontsize=12, ha='right')
plt.text(xC, yC, 'C', fontsize=12, ha='right')
plt.text(xD, yD, 'D', fontsize=12, ha='right')

# Set labels and title
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Parallelogram ABCD')
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.grid(color='gray', linestyle='--', linewidth=0.5)
plt.legend()
plt.gca().set_aspect('equal', adjustable='box')

# Show plot
plt.show()


