import java.util.Stack;

public class stack_operation {

  public static void main(String[] args) {
    Stack<Integer> stack = new Stack<>();

    stack.push(1);
    stack.push(2);
    stack.push(3);
    _println("Stack items : " + stack);
    _println("Stack size : " + stack.size() + ", Stack peek : " + stack.peek());
    stack.pop();
    _println("Stack (1)pop : " + stack);
    stack.push(13);
    _println("Stack 13 push : " + stack);
    stack.empty();
    _println("Use Stack empty() : " + stack);
  }

  private static void _println(Object o) {
    System.out.println(o);
  }
}
