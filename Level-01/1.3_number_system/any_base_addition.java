import java.util.Scanner;

public class any_base_addition {

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
      String result = addInBase(number_1, number_2, base);
      _print("Result : " + result);
    } catch (Exception e) {
      _print(e);
    }
    _println();
  }

  private static String addInBase(String num1, String num2, int base) {
    // Ensure that the base is within a valid range (between 2 and 36),
    // which allows for a combination of up to 10 digits and 26 alphabetic.
    if (base < 2 || base > 36) {
      throw new IllegalArgumentException("Base must be between 2 to 36.");
    }

    if (num1.charAt(0) == '-' || num2.charAt(0) == '-') {
      throw new IllegalArgumentException("Numbers shoud be positive.");
    }

    // Convert the input strings to uppercase for consistency.
    num1 = num1.toUpperCase();
    num2 = num2.toUpperCase();

    StringBuffer str = new StringBuffer();

    // Characters order is very importent
    String charSet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int carry = 0;

    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
      int lst1 = i >= 0 ? charSet.indexOf(num1.charAt(i)) : 0;
      int lst2 = j >= 0 ? charSet.indexOf(num2.charAt(j)) : 0;
      int sum = lst1 + lst2 + carry;

      carry = sum / base;
      // Update the carry
      str.insert(0, charSet.charAt(sum % base));
      i--;
      j--;
    }

    return str.toString();
  }

  private static void _print(Object o) {
    System.out.print(o);
  }

  private static void _println() {
    System.out.println();
  }
}
