import java.util.Scanner;

public class any_base_subtraction {

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    _print("Enter a first number : ");
    String number_1 = scan.nextLine();
    _print("Enter a second number : ");
    String number_2 = scan.nextLine();
    _print("Enter the base : ");
    int base = scan.nextInt();
    scan.close();

    try {
      String result = subtractInBase(number_1, number_2, base);
      _print(result);
    } catch (Exception e) {
      _print(e);
    }
    _println();
  }

  public static String subtractInBase(String num1, String num2, int base) {
    // Ensure that the base is within a valid range (between 2 and 36).
    if (base < 2 || base > 36) {
      throw new IllegalArgumentException("Base must be between 2 to 36.");
    }
    if (num1.charAt(0) == '-' || num2.charAt(0) == '-') {
      throw new IllegalArgumentException("Numbers shoud be positive.");
    }

    // Convert the input strings to uppercase for consistency.
    num1 = num1.toUpperCase();
    num2 = num2.toUpperCase();

    // Define a character set for the base.
    String charSet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Initialize variables to store the result and borrow.
    StringBuilder result = new StringBuilder();
    int borrow = 0;

    // Iterate from the rightmost digit (least significant) to the leftmost digit.
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0) {
      // Extract digits from the input strings or assume 0 if no digits are left.
      int digit1 = i >= 0 ? charSet.indexOf(num1.charAt(i)) : 0;
      int digit2 = j >= 0 ? charSet.indexOf(num2.charAt(j)) : 0;

      // Apply the borrow from the previous step.
      digit1 -= borrow;

      // If digit1 is negative, borrow from the next higher place value.
      if (digit1 < digit2) {
        digit1 += base;
        borrow = 1;
      } else {
        borrow = 0;
      }

      // Calculate the difference of digits.
      int difference = digit1 - digit2;

      // Append the current digit to the result as a character.
      result.insert(0, charSet.charAt(difference));

      // Move to the next digits (leftward).
      i--;
      j--;
    }

    return result.substring(1);
  }

  private static void _print(Object o) {
    System.out.print(o);
  }

  private static void _println() {
    System.out.println();
  }
}
