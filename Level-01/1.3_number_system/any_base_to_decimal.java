import java.util.Scanner;

public class any_base_to_decimal {

  /*

    ⇨ input: 
            Enter a number : ABC
            Enter the base : 16

    ⇨ Output:
            Decimal equivalent: 3258

     */
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    _print("Enter a number : ");
    String numberString = scan.nextLine();
    _print("Enter the base : ");
    int base = scan.nextInt();
    scan.close();
    try {
      int decimal = convertToDecimal(numberString, base);
      _print("Decimal equivalent: " + decimal);
    } catch (Exception e) {
      _print(e);
    }
    _println(); // For better readability
  }

  private static int convertToDecimal(String number, int base) {
    int decimal = 0;
    int power = 0;

    // Ensure that the base is within a valid range (between 2 and 36),
    // which allows for a combination of up to 10 digits and 26 alphabetic.
    if (base < 2 || base > 36) {
      throw new IllegalArgumentException("Base must be between 2 to 36.");
    }

    for (int i = 0; i < number.length(); i++) {
      char ch = Character.toLowerCase(number.charAt(i));

      boolean isDigit = Character.isDigit(ch);

      // Convert alphabet to number
      int value = isDigit ? ch - '0' : ch - 'a' + 10;

      if (value < 0 || value >= base) {
        throw new IllegalArgumentException("Invalid digit found.");
      }
      decimal += value * Math.pow(base, power++);
    }

    return decimal;
  }

  private static void _print(Object o) {
    System.out.print(o);
  }

  private static void _println() {
    System.out.println();
  }
}
