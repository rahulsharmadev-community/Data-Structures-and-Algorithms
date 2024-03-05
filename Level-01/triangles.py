def find_angle_from_cosine(cosine_value):
    """
    Calculate the angle (in degrees) given its cosine value.
    """
    return math.degrees(math.acos(cosine_value))

def angles_of_triangle(x, y, z):
    """
    Calculate angles of a triangle given its sides.
    """
    _x = round(find_angle_from_cosine(-(x * x - (y * y + z * z)) / (2 * y * z)))
    _y = round(find_angle_from_cosine(-(y * y - (x * x + z * z)) / (2 * x * z)))
    _z = 180 - _x - _y
    return _x, _y, _z

def is_isosceles_triangle(x, y, z):
    """
    Check if it's an isosceles triangle.
    """
    return x == y or y == z or z == x

def is_right_angle_triangle(x, y, z):
    """
    Check if it's a right-angled triangle.
    """
    # Make x the largest side
    if y > x:
        x, y = y, x
    if z > x:
        x, z = z, x

    return x * x == y * y + z * z

def main():
    # Input side lengths from the user
    a, b, c = map(float, input("Enter the 3 side of trangle (space-separated): ").split())

    # Check if it's a right-angled triangle and print the result
    print(f"Right Angle Triangle: {is_right_angle_triangle(a, b, c)}")

    # Check if it's an isosceles triangle and print the result
    print(f"Isosceles Triangle: {is_isosceles_triangle(a, b, c)}")

    # Calculate and print the angles of the triangle
    angles = angles_of_triangle(a, b, c)
    print("Angles of Triangle:")
    for angle in angles:
        print(angle)

if __name__ == "__main__":
    import math
    main()
