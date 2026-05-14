import sys

def generate_testcase(N=2000):
    # Ensure N is within the problem's bounds
    assert 3 <= N <= 2000
    
    vertices = []
    
    # Vertex 1: (0, 0)
    # Placed at the peak of the parabola
    vertices.append((1, 0, 0))
    
    # Vertex 2: (-1, -1)
    # The only point to the left of the peak
    vertices.append((2, -1, -1))
    
    # Vertices 3 to N: (x, -x^2) where x ranges from 1 to N-2
    # These form the long right-side tail of the parabola
    for i in range(3, N + 1):
        x = i - 2
        y = -x * x
        vertices.append((i, x, y))
        
    # Output N
    print(N)
    
    # Output the coordinates in order of their vertex number (1 to N)
    for v in vertices:
        print(f"{v[1]} {v[2]}")
        
    # Generate a valid perimeter order for the convex polygon.
    # To form the polygon, we trace the parabola from left to right:
    # Starting at the leftmost point (Vertex 2), going to the peak (Vertex 1),
    # and then following the right tail (Vertices 3 through N).
    # The final edge naturally connects Vertex N back to Vertex 2.
    order = [2, 1] + list(range(3, N + 1))
    
    # Output the valid permutation
    print(" ".join(map(str, order)))

if __name__ == "__main__":
    # You can change this value to test smaller skewed polygons
    generate_testcase(2000)