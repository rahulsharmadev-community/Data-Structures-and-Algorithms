import java.util.Scanner;

public class pattern_01 {

  public static void main(String[] args) {
    int n = _scanInt();
    Q1(n);
    _println();
    Q2(n);
    _println();
    Q3(n);
    _println();
    Q4(n);
  }

  /*
    ⇨ input: 4
    ⇨ Output:
   
          *
          *  *
          *  *  *
          *  *  *  *
   
   */
  public static void Q1(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        System.out.print(" * ");
      }
      System.out.println();
    }
  }

  /*
    ⇨ input: 4
    ⇨ Output:
   
         *  *  *  *
         *  *  *
         *  *
         *
   
   */
  public static void Q2(int n) {
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        System.out.print(" * ");
      }
      System.out.println();
    }
  }

  /*
    ⇨ input: 4
    ⇨ Output:
   
            *  *  *  *
               *  *  *
                  *  *
                     *
   
   */
  public static void Q3(int n) {
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        System.out.print("   ");
      }
      for (int j = i; j < n; j++) {
        System.out.print(" * ");
      }

      System.out.println();
    }
  }

  /*
    ⇨ input: 4
    ⇨ Output:
   
                   *
                *  *
             *  *  *
          *  *  *  *
   
   */
  public static void Q4(int n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        System.out.print("   ");
      }
      for (int j = i; j < n; j++) {
        System.out.print(" * ");
      }

      System.out.println();
    }
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
