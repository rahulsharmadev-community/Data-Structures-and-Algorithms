/*

Binary search is an algorithm to find a specific item in a sorted list
efficiently. It assumes the list is sorted, and it repeatedly splits
the list in half until it finds the item or exhausts the search.
It's fast, with a time complexity of O(log n), but it only works
with sorted data and requires random access to elements.

- Input array -
    The input array must be sorted in ascending or descending order.

*/

public class binary_search {

  public static void main(String[] args) {
    int[] test_1 = { 10, 20, 30, 40, 50, 80, 100 }; // ascending
    int[] test_2 = { 100, 95, 80, 70, 40, 5, 1 }; // descending

    int result_1 = indexByBinarySearch(test_1, 80);
    _printArray("Find 80 in", test_1);
    _println("Index: " + result_1);

    int result_2 = indexByBinarySearch(test_2, 95);
    _printArray("Find 95 in", test_2);
    _println("Index: " + result_2);
  }

  public static int indexByBinarySearch(int[] array, int n) {
    int start = 0;
    int end = array.length - 1;

    // Check if the array is in ascending order
    boolean isAscending = array[start] < array[end];

    while (start <= end) {
      int mid = (start + end) / 2;

      // If the target element is found, return its index
      if (n == array[mid]) return mid;

      if (isAscending) {
        // When the array is in ascending order
        if (n > array[mid]) start = mid + 1; else end = mid - 1;
      } else {
        // When the array is in descending order
        if (n < array[mid]) start = mid + 1; else end = mid - 1;
      }
    }

    return -1;
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
