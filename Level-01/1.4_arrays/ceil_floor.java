public class ceil_floor {

  public static void main(String[] args) {
    int[] test_1 = { 10, 20, 30, 40, 50, 80, 100 }; // ascending
    int[] test_2 = { 100, 95, 80, 70, 40, 5, 1 }; // descending

    Range result_1 = findRange(test_1, 22);
    _printArray("Input 22 in", test_1);
    _println("Output: " + result_1);

    Range result_2 = findRange(test_2, 44);
    _printArray("Input 44 in", test_2);
    _println("Output: " + result_2);
  }

  // Range ⇔ [ceil, floor]
  private static Range findRange(int[] array, int n) {
    int ceil = Integer.MAX_VALUE;
    int floor = Integer.MIN_VALUE;

    int start = 0;
    int end = array.length - 1;
    // Check if the array is in ascending order
    boolean isAscending = array[start] < array[end];

    while (start <= end) {
      int mid = (start + end) / 2;
      // If the target element is found, return its index
      if (n == array[mid]) {
        ceil = floor = array[mid];
        break;
      }
      if (isAscending) {
        // When the array is in ascending order
        if (n > array[mid]) {
          start = mid + 1;
          floor = array[mid];
        } else {
          end = mid - 1;
          ceil = array[mid];
        }
      } else {
        // When the array is in descending order
        if (n < array[mid]) {
          start = mid + 1;
          ceil = array[mid];
        } else {
          end = mid - 1;
          floor = array[mid];
        }
      }
    }

    return new Range(ceil, floor);
  }

  private static void _println(Object n) {
    System.out.println(n);
  }

  private static void _printArray(String before, int[] array) {
    System.out.print(before + " [");
    for (int e : array) System.out.print(e + ", ");
    System.out.print("]\n");
  }
}

class Range {

  final int ceil, floor;

  Range(int ceil, int floor) {
    this.ceil = ceil;
    this.floor = floor;
  }

  @Override
  public String toString() {
    return "Floor: " + floor + ", Ceil: " + ceil;
  }
}
