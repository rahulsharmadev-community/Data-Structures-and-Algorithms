import java.util.Stack;

public class next_greater_element {

  public static void main(String[] args) {
    int[] test1 = { 1, 43, 15, 7, 0, 25, 8, 21, 99 };
    int[] result = getNextGreaterElement(test1);

    for (int i = 0; i < result.length; i++) {
      Object object = result[i] == -1 ? "Not Available" : result[i];
      _println("Next greater for " + test1[i] + " is " + object);
    }
  }

  static int[] getNextGreaterElement(int[] array) {
    int[] nge = new int[array.length];

    // Create a stack to keep track of elements in descending order.
    Stack<Integer> stack = new Stack<>();

    // Push the last element into the stack as there are no elements to its right.
    stack.push(array[array.length - 1]);

    // Initialize the last element's next greater element as -1.
    nge[array.length - 1] = -1;

    for (int i = array.length - 2; i >= 0; i--) {
      int _n = array[i];

      // While the stack is not empty and the top element of the stack is less than or
      // equal to the current element, pop elements from the stack.
      while (!stack.empty() && stack.peek() <= _n) stack.pop();

      // If the stack is empty, there is no greater element to the right of the current element.
      // Otherwise, the top element of the stack is the next greater element.
      nge[i] = stack.empty() ? -1 : stack.peek();

      // Push the current element into the stack for future comparisons.
      stack.push(_n);
    }
    return nge;
  }

  static void _println(Object n) {
    System.out.println(n);
  }
}
