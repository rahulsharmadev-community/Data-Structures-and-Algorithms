import java.util.Scanner;

public class pattern_03 {

  public static void main(String[] args) {
    int n = _scanInt();
    _01(n);
  }

  /*
  
  Diagonal Pattern
 
    * 
       * 
          * 
             * 
                * 
  
*/

  private static void _01(int n) {
    for (int i = 0; i < n; i++) {}
  }

  public static void _printSpace(int space) {
    for (int sp = 0; sp < space; sp++) System.out.print("   ");
  }

  public static void _printStar(int star) {
    for (int st = 0; st < star; st++) System.out.print(" * ");
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
