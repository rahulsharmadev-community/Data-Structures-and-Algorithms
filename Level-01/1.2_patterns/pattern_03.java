import java.util.Scanner;

public class pattern_03 {

  public static void main(String[] args) {
    int n = _scanInt();
    Q1(n);
    _println();
    Q2(n);
  }

  /*
  
  Triangle of Fibonacci sequence numbers

      0
      1       1
      2       3       5
      8       13      21      34
      55      89      144     233     377
  
*/

  private static void Q1(int n) {
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        _print(a + "\t");

        int c = a + b;
        a = b;
        b = c;
      }
      _println();
    }
  }

  /*
  
  Triangle of numbers

          1
          1       1
          1       2       1
          1       3       3       1
          1       4       6       4       1
          1       5       10      10      5       1
        ——————————————————————————————————————————————
hint: ⇨  ⁰C₀           
hint: ⇨  ¹C₀     ¹C₁  
hint: ⇨  ²C₀     ²C₁     ²C₂   
hint: ⇨  ³C₀     ³C₁     ³C₂     ³C₃   
hint: ⇨  ⁴C₀     ⁴C₁     ⁴C₂     ⁴C₃     ⁴C₄
hint: ⇨  ⁵C₀     ⁵C₁     ⁵C₂     ⁵C₃     ⁵C₄     ⁵C₅     
  
*/
  private static void Q2(int n) {
    for (int i = 0; i < n; i++) {
      int iCj = 1;
      for (int j = 0; j <= i; j++) {
        _print(iCj + "\t");
        iCj = (iCj * (i - j)) / (j + 1);
      }
      _println();
    }
  }

  public static void _print(Object o) {
    System.out.print(o);
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
