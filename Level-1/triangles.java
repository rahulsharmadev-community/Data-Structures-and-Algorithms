import java.lang.Math;
import java.util.*;

public class triangles {

  static double a, b, c;

  public static void main(String[] args) {
    // Input side lengths from the user
    scan();

    // Check if it's a right-angled triangle and print the result
    println("Right Angle Triangle: " + isRightAngleTriangle(a, b, c));

    // Check if it's an isosceles triangle and print the result
    println("Isosceles Triangle: " + isIsoscelesTriangle(a, b, c));

    // Calculate and print the angles of the triangle
    double[] angles = anglesOfTriangle(a, b, c);
    println("Angles of Triangle: ");
    for (int i = 0; i < angles.length; i++) println(angles[i]);
  }

  // Calculate angles of a triangle given its sides
  public static double[] anglesOfTriangle(double x, double y, double z) {
    double _x = (double) Math.round(
      _findAngleFromCosine(-(x * x - (y * y + z * z)) / (2 * y * z))
    );
    double _y = (double) Math.round(
      _findAngleFromCosine(-(y * y - (x * x + z * z)) / (2 * x * z))
    );
    double _z = 180 - _x - _y;
    return new double[] { _x, _y, _z };
  }

  // Check if it's an isosceles triangle
  public static boolean isIsoscelesTriangle(double x, double y, double z) {
    return x == y || y == z || z == x;
  }

  // Check if it's an equilateral triangle
  public static boolean isEquilateral(double x, double y, double z) {
    return x == y && y == z && z == x;
  }

  // Check if it's a right-angled triangle
  public static boolean isRightAngleTriangle(double x, double y, double z) {
    // Make x the largest side
    if (y > x) {
      double temp = x;
      x = y;
      y = temp;
    }
    if (z > x) {
      double temp = z;
      x = z;
      z = temp;
    }

    return x * x == y * y + z * z;
  }

  // Input side lengths from the user
  public static void scan() {
    Scanner scn = new Scanner(System.in);
    a = scn.nextDouble();
    b = scn.nextDouble();
    c = scn.nextDouble();
    scn.close();
  }

  // Print an object
  private static void println(Object s) {
    System.out.println(s);
  }

  // Find the angle in degrees from its cosine value
  private static double _findAngleFromCosine(double cosineC) {
    if (cosineC >= -1.0 && cosineC <= 1.0) {
      double angleInRadians = Math.acos(cosineC);
      double angleInDegrees = Math.toDegrees(angleInRadians);
      return angleInDegrees;
    } else {
      // Handle the case where the input is not within the valid range for cosine (-1 to 1).
      throw new IllegalArgumentException(
        "Invalid cosine value. It must be between -1 and 1."
      );
    }
  }
}
