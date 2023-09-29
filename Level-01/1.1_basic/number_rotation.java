/*

   Given two numbers n and k, we have to rotate the number n by k digits. If k is positive,
   right rotate the number i.e. remove k rightmost digits and make them leftmost.Else for
   negative values of k, left rotate the number, i.e. remove k digits from left and make them
   rightmost digits.
  
   Eg) Rotating 562984 by +2 will give 846529, whereas rotating it by -2 will give 652984.
  
   Note: k can be larger than the number of digits in number n. In that case,
   we will ignore rotations of the whole number and left/rotate only the rotations left after reduction.
  
   Eg) If we are asked to rotate 562984 by +9, then we will ignore rotation of +6 (number of digits) and
   rotate it by +3, i.e. 984562.
   
 */

import java.util.*;

public class number_rotation {

  public static void main(String[] args) {
    // Create a Scanner object to read inputs from the user
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int k = scn.nextInt();
    scn.close(); // Close the scanner to free up resources

    // Calculate the length of the input number
    int length = length(n);

    // Adjust the rotation count if it's negative or exceeds the length
    if (k < 0) k = length + k;
    k = k % length;

    // Initialize div (divisor) and mult (multiplier)
    int div = 1;
    int mult = 1;

    // Calculate div and mult based on the rotation count (k)
    for (int i = 1; i <= length; i++) {
      if (i <= k) {
        div = div * 10;
      } else {
        mult = mult * 10;
      }
    }

    // Perform the rotation by splitting and reassembling the number
    int q = n / div; // Quotient (left part)
    int r = n % div; // Remainder (right part)

    int output = r * mult + q; // Combine the parts to get the rotated number

    // Print the rotated number
    println(output);
  }

  /**
   * Calculate the number of digits in an integer.
   *
   * @param _num The integer whose length is to be calculated.
   * @return The number of digits in the input integer.
   */
  private static int length(int _num) {
    int count = 0;
    while (_num > 0) {
      _num = _num / 10;
      count++;
    }
    return count;
  }

  private static void println(int s) {
    System.out.println(s);
  }
}
