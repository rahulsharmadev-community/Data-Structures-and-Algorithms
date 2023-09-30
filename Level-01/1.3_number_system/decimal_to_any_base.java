import java.util.Scanner;

public class decimal_to_any_base {

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    _print("Enter a decimal number (0-9) : ");
    long numberString = scan.nextLong();
    _print("Convert into base : ");
    int base = scan.nextInt();
    scan.close();
    try {
      String number = convertInBase(numberString, base);
      _print("Number in base " + base + " : " + number);
    } catch (Exception e) {
      _print(e);
    }
    _println();
  }

  public static String convertInBase(long number, int base) {
    // Ensure that the base is within a valid range (between 2 and 36),
    // which allows for a combination of up to 10 digits and 26 alphabetic.
    if (base < 2 || base > 36) {
      throw new IllegalArgumentException("Base must be b/w 2 to 36.");
    }
    if (number == 0) return "0"; // Handle the special case of 0.

    StringBuffer str = new StringBuffer();

    // Characters order is very importent
    char[] charSet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();

    // For negative numbers, add a minus sign and work with the absolute value.
    if (number < 0) {
      str.append('-');
      number = Math.abs(number);
    }

    while (number > 0) {
      long rem = number % base;
      str.insert(0, charSet[(int) rem]);

      number /= base;
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
