import java.util.Scanner;
import java.util.Stack;

public class duplicate_brackets_checker {

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    _println(
      "Enter a input for testing duplicate of brackets. eg (2+3) x ((2-1))"
    );
    String input = scan.nextLine();
    scan.close();
    boolean result = isduplicateBrackets(input.toCharArray());

    _println("Duplicate of brackets: " + result);
  }

  /**
   * Checks if the given character array contains duplicate brackets.
   *
   * @param chars The character array to check.
   * @return true if duplicate brackets are found, false otherwise.
   */
  public static boolean isduplicateBrackets(char[] chars) {
    Stack<Character> stack = new Stack<>();
    for (Character ch : chars) {
      if (ch == ')') {
        if (stack.empty()) throw new IllegalArgumentException(
          "Formate Exception"
        );
        // Found a pair of duplicate brackets
        if (stack.peek() == '(') return true;

        // Pop characters until an opening bracket is found
        while (stack.peek() != '(') stack.pop();
        stack.pop(); // Pop the opening bracket
      } else {
        // Push non-bracket characters onto the stack
        stack.push(ch);
      }
    }

    return false; // No duplicate brackets found
  }

  private static void _println(Object o) {
    System.out.println(o);
  }
}
