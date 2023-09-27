import java.util.*;

public class prime_factorization {

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int num = scn.nextInt();
    scn.close();
    for (int div = 2; div * div <= num; div++) {
      while (num % div == 0) {
        num = num / div;
        print(div);
      }
    }
    if (num != 1) {
      print(num);
    }
  }

  private static void print(int s) {
    System.out.println(s);
  }
}
