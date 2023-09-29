import java.util.Scanner;

public class pattern_02 {

  public static void main(String[] args) {
    int n = _scanInt();
    Q1(n);
    _println();
    Q2(n);
    _println();
    Q3(n);
    _println();
    Q4(n);
    _println();
    Q5(n);
    _println();
    Q6(n);
  }

  /*
  Diagonal Pattern Top Left to Bottom Right

    ⇨ input: 5
    ⇨ Output:
              * 
                 * 
                    * 
                       * 
                          * 
  
*/

  private static void Q1(int n) {
    for (int i = 0; i < n; i++) {
      _printSpace(i);
      _printStar(1);
      _println();
    }
  }

  /*
  Diagonal Pattern Bottom Left to Top Right

    ⇨ input: 5
    ⇨ Output:
                          * 
                       *    
                    *       
                 *          
              *             
  
*/

  private static void Q2(int n) {
    for (int i = n; i > 0; i--) {
      _printSpace(i);
      _printStar(1);
      _println();
    }
  }

  /*
  Cross Pattern

    ⇨ input: 7 [Input should be odd number]
    ⇨ Output:

            *                 *
               *           *
                  *     *
                     *
                  *     *
               *           *
            *                 *
  
*/

  private static void Q3(int n) {
    int sp1 = 0;
    int sp2 = n - 2;
    for (int i = 1; i <= n; i++) {
      _printSpace(sp1);
      _printStar(1);
      _printSpace(sp2);
      if (sp2 > 0) _printStar(1);
      _println();
      if (i <= n / 2) {
        sp1++;
        sp2 -= 2;
      } else {
        sp1--;
        sp2 += 2;
      }
    }
  }

  /*
  Diamond Pattern

    ⇨ input: 5 [Input should be odd number]
    ⇨ Output:

                *
             *  *  *
          *  *  *  *  *
             *  *  *
                *

   */
  private static void Q4(int n) {
    int sp = n / 2;
    int st = 1;
    for (int i = 1; i <= n; i++) {
      _printSpace(sp);
      _printStar(st);
      _println();

      if (i <= n / 2) {
        sp--;
        st += 2;
      } else {
        sp++;
        st -= 2;
      }
    }
  }

  /*
  Inverse Diamond Pattern

  ⇨ input: 7 [Input should be odd number]
  ⇨ Output:

       *  *  *  *     *  *  *  *
       *  *  *           *  *  *
       *  *                 *  *
       *                       *
       *  *                 *  *
       *  *  *           *  *  *
       *  *  *  *     *  *  *  *
   
   */
  private static void Q5(int n) {
    int sp = 1;
    int st = n / 2 + 1;
    for (int i = 1; i <= n; i++) {
      _printStar(st);
      _printSpace(sp);
      _printStar(st);
      _println();
      if (i <= n / 2) {
        st--;
        sp += 2;
      } else {
        st++;
        sp -= 2;
      }
    }
  }

  /*
  Diamond Border Pattern

  ⇨ input: 7 [Input should be odd number]
  ⇨ Output:

                * 
             *     * 
          *           * 
       *                 * 
          *           * 
             *     * 
                * 
   
   */
  private static void Q6(int n) {
    int sp1 = (int) n / 2;
    int sp2 = -1;
    for (int i = 1; i <= n; i++) {
      _printSpace(sp1);
      _printStar(1);
      _printSpace(sp2);
      if (!(i == 1 || i == n)) _printStar(1);
      _println();
      if (i <= n / 2) {
        sp1--;
        sp2 += 2;
      } else {
        sp1++;
        sp2 -= 2;
      }
    }
  }

  public static void _printSpace(int space) {
    if (space <= 0) return;
    for (int sp = 0; sp < space; sp++) System.out.print("   ");
  }

  public static void _printStar(int star) {
    if (star <= 0) return;
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
