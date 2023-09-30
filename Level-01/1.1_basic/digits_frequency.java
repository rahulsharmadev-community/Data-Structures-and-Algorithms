import java.util.Scanner;

public class digits_frequency {

  public static void main(String[] args) {
    // Create a Scanner object to read input from the user
    Scanner scan = new Scanner(System.in);

    _print("Enter a number (longer numbers are preferable) : ");

    long num = scan.nextLong();

    _print("Select a digit: ");

    int k = scan.nextInt();

    scan.close(); // free up resources

    // Count the frequency of the selected digit in the number
    int count = countNumber(k, num);

    // Display the digit frequency to the user
    _print("Digit Frequency: " + count);

    _println(); // For better readability
  }

  // This method counts the frequency of a digit 'k' in a long number 'num'
  private static int countNumber(int k, long num) {
    int count = 0;
    while (num > 0) {
      int last = (int) num % 10; // Extract the last digit

      // Check if the last digit matches the selected digit 'k'
      if (last == k) count++;

      num = num / 10; // Remove the last digit
    }
    return count;
  }

  // This method is used to print a string without a newline
  private static void _print(String string) {
    System.out.print(string);
  }

  // This method is used to print a newline
  private static void _println() {
    System.out.println();
  }
}
