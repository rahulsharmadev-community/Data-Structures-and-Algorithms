import java.util.Scanner;
import java.util.Stack;

public class balanced_brackets_checker {

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    _println(
      "Enter a input for testing balanced of brackets. eg (2+3) x ((2-1)])"
    );
    String input = scan.nextLine();
    scan.close();
    boolean result = isBalancedBrackets(input.toCharArray());

    _println("Input have balanced brackets: " + result);
  }

  public static boolean isBalancedBrackets(char[] chars) {
    Stack<Character> stack = new Stack<>();

    for (Character ch : chars) {
      if (ch == ')') {
        if (stack.empty()) return false;

        // Pop characters until an opening bracket is found
        while (stack.peek() != '(') stack.pop();
        stack.pop(); // Pop the opening bracket
      } else if (ch == ']') {
        if (stack.empty()) return false;

        // Pop characters until an opening bracket is found
        while (stack.peek() != '[') stack.pop();
        stack.pop(); // Pop the opening bracket
      } else if (ch == '}') {
        if (stack.empty()) return false;

        // Pop characters until an opening bracket is found
        while (stack.peek() != '{') stack.pop();
        stack.pop(); // Pop the opening bracket
      } else {
        // Push non-bracket characters onto the stack
        stack.push(ch);
      }
    }

    return stack.empty(); // No duplicate brackets found
  }

  static boolean _contain(char[] chars, char ch) {
    for (char c : chars) {
      return c == ch;
    }
    return false;
  }

  static int _indexOf(char[] chars, char ch) {
    for (int i = 0; i < chars.length; i++) {
      if (ch == chars[i]) return i;
    }
    return -1;
  }

  private static void _println(Object o) {
    System.out.println(o);
  }
}
