import java.util.Scanner;

/*
  Problem Discussion :
   1) You are given n number of bulbs. They are all switched off. A weird fluctuation in voltage
      hits the circuit n times. In the 1st fluctuation, all bulbs are toggled, in the 2nd fluctuation
      every 2nd bulb is toggled, in the 3rd fluctuation, every 3rd bulb is toggled, and so on.
      You've to find which bulbs will be switched on after n fluctuations.
 
    2) Take as input a number n, representing the number of bulbs.
 
    3) Print all the bulbs that will be ON after the nth fluctuation in voltage.
 */
public class benjamin_bulbs {

  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n = scan.nextInt();
    scan.close();

    for (int i = 0; i * i < n; i++) {
      System.out.println(i * i);
    }
  }
}
