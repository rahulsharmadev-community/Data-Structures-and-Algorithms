import java.util.Scanner;

public class pattern_01 {

  public static void main(String[] args) {
    _02();
  }

  /**
   *  input: 4
   *
   *    ---Output--
   *
   *       *
   *       *  *
   *       *  *  *
   *       *  *  *  *
   *
   */
  public static void _01() {
    int scan = _scan();
    int n = scan;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        System.out.print(" * ");
      }
      System.out.println();
    }
  }

  /**
   *  input: 4
   *
   *    ---Output--
   *
   *      *  *  *  *
   *      *  *  *
   *      *  *
   *      *
   *
   */
  public static void _02() {
    int n = _scan();
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        System.out.print(" * ");
      }
      System.out.println();
    }
  }

  public static int _scan() {
    Scanner _scan = new Scanner(System.in);
    int _n = _scan.nextInt();
    _scan.close();
    return _n;
  }
}
