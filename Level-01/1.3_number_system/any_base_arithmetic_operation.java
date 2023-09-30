public class any_base_arithmetic_operation {}

class ArithmeticOperation {

  final String num1;
  final String num2;
  final int base;

  ArithmeticOperation(String n1, String n2, int b) {
    // Ensure that the base is within a valid range (between 2 and 36).
    if (b < 2 || b > 36) {
      throw new IllegalArgumentException("Base must be between 2 to 36.");
    }

    num1 = n1.toUpperCase();
    num2 = n2.toUpperCase();
    base = b;
  }
}
