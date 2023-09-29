import java.util.Scanner;

public class pattern_04 {

  public static void main(String[] args) {
    int n = _scanInt();
    _Q1(n);
    _println();
    _Q2(n);
  }

  /*

  Symmetrical Diamond Number Pattern
  
  The numbers on both sides of the central number increase by one until they reach the
  widest point of the diamond. Then, the numbers start decreasing in a symmetrical fashion.
  The pattern continues to expand and contract until it forms the diamond shape you've shown.

    ⇨ input: 7 [Input should be odd number]
    ⇨ Output:
 
                1 
             2  3  2 
          3  4  5  4  3 
       4  5  6  7  6  5  4 
          3  4  5  4  3 
             2  3  2 
                1 

 */

  private static void _Q1(int n) {
    int space = n / 2;
    int star = 1;
    int firstValue = 1;
    for (int i = 1; i <= n; i++) {
      _printSpace(space); //print Space first

      int value = firstValue;
      for (int j = 1; j <= star; j++) {
        _print(value);

        if (j <= star / 2) value++; else value--;
      }
      _println();

      if (i <= n / 2) {
        space--;
        star += 2;
        firstValue++;
      } else {
        space++;
        star -= 2;
        firstValue--;
      }
    }
  }

  /*

  Special Number Pattern

    ⇨ input: 7 
    ⇨ Output:
 
          1                       1
          1 2                   2 1
          1 2 3               3 2 1
          1 2 3 4           4 3 2 1
          1 2 3 4 5       5 4 3 2 1
          1 2 3 4 5 6   6 5 4 3 2 1
          1 2 3 4 5 6 7 6 5 4 3 2 1

 */

  private static void _Q2(int n) {
    int space = n * 2 - 3; // Calculate the initial number of spaces
    int value = 1; // Starting from `1`

    for (int i = 1; i <= n; i++) {
      // Print numbers in ascending order
      for (int j = 1; j <= value; j++) {
        _print(j);
      }

      // Print spaces b/w numbers
      _printSpace(space);

      if (i == n) value--; // Avoid repeating the middle number

      // Print numbers in descending order
      for (int j = value; j >= 1; j--) {
        _print(j);
      }

      space -= 2; // Reduce the number of spaces for the next row
      value++; // Increase the value for the next row
      _println(); // Move to the next line
    }
  }

  public static void _printSpace(int space) {
    if (space <= 0) return;
    for (int sp = 0; sp < space; sp++) System.out.print("   ");
  }

  public static void _print(Object o) {
    System.out.print(" " + o + " ");
  }

  public static void _println() {
    System.out.println();
  }

  public static int _scanInt() {
    Scanner _scan = new Scanner(System.in);
    int _n = _scan.nextInt();
    _scan.close();
    return _n;
  }
}
