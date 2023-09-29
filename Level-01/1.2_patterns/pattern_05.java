import java.util.Scanner;

public class pattern_05 {

  /*
  Sand Timer Clock Diamond Pattern

    ⇨ input: 9 [Input should be odd number]
    ⇨ Output:

             *  *  *  *  *  *  *  *  *  
                *                 * 
                   *           * 
                      *     * 
                         * 
                      *  *  * 
                   *  *  *  *  * 
                *  *  *  *  *  *  * 
             *  *  *  *  *  *  *  *  * 
     
*/

  public static void main(String[] args) {
    int n = _scanInt();
    _Q1(n);
  }

  private static void _Q1(int n) {
    int spaceAtBeginning = 0;
    int spaceAtEnd = n - 4;
    int starAtBeginning = n;
    int starAtEnd = 1;
    for (int i = 1; i <= n; i++) {
      _printSpace(spaceAtBeginning);

      _printStar(starAtBeginning);

      // [Only Run For Top Half] If we are in the top half of the diamond,
      // print additional spaces in middle and ending with a star.
      if (i > 1 && i <= n / 2) {
        _printSpace(spaceAtEnd);
        _printStar(starAtEnd);
        spaceAtEnd -= 2;
      }

      // Move to the next line
      _println();

      if (i <= n / 2) {
        starAtBeginning = 1;
        spaceAtBeginning++;
      } else {
        starAtBeginning += 2;
        spaceAtBeginning--;
      }
    }
  }

  public static void _printSpace(int space) {
    if (space <= 0) return;
    for (int sp = 0; sp < space; sp++) System.out.print("   ");
  }

  public static void _printStar(int space) {
    if (space <= 0) return;
    for (int sp = 0; sp < space; sp++) System.out.print(" * ");
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
