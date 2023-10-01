/*
 * After finding minimum and maximum values of the array, we will print their difference
 * (maximum value - minimum value) which is the span of the array.
 */

public class array_operations {

  public static void main(String[] args) {
    MyArray array = new MyArray(new int[] { 8, 9, 5, 8, 5, 7 });

    _print("Span : " + array.span());
    _println();
    _print("Find 43 : " + array.find(43));
    _println();
  }

  private static void _print(Object o) {
    System.out.print(o);
  }

  private static void _println() {
    System.out.println();
  }
}

class MyArray {

  final int[] array;

  MyArray(int[] array) {
    this.array = array;
  }

  public int span() {
    int max = array[0];
    int min = array[0];
    for (int i = 0; i < array.length - 1; i++) {
      if (max < array[i + 1]) max = array[i + 1];
      if (min > array[i + 1]) min = array[i + 1];
    }
    return max - min;
  }

  public int find(int n) {
    for (int i = 0; i < array.length; i++) {
      if (array[i] == n) return i;
    }
    return -1;
  }

  @Override
  public String toString() {
    StringBuffer str = new StringBuffer();
    for (int i = 0; i < array.length; i++) str.append(array[i] + ", ");
    return str.toString();
  }
}
