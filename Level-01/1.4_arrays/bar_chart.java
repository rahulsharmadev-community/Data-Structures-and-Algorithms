import java.util.Scanner;

public class bar_chart {

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    _print("Enter Size of Bar Chart: ");
    int k = scan.nextInt();
    _print("Enter " + k + " element of Chart \n");
    int[] elements = new int[k];

    int max = 0;

    for (int i = 0; i < k; i++) {
      int value = scan.nextInt();
      elements[i] = value;
      if (max < value) max = value;
    }

    scan.close();

    for (int i = max; i > 0; i--) {
      for (int j = 1; j <= elements.length; j++) {
        if (elements[j - 1] >= i) _print(" * "); else _print("   ");
      }
      _println();
    }
  }

  private static void _print(Object o) {
    System.out.print(o);
  }

  private static void _println() {
    System.out.println();
  }
}
