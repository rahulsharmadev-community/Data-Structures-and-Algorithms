
import java.util.*;

/**
 * Greatest Common Divisor (GCD) or Highest Common Factor (HCF)
 * of two positive integers is the largest positive integer that
 * divides both numbers without remainder.
 * [more]: https://www.idomaths.com/hcflcm.php#findhcf
 *
 * Least Common Multiple (LCM) of two integers is the smallest
 * integer that is a multiple of both numbers.
 * [more]: https://www.idomaths.com/hcflcm.php#findlcm
 */

public class gcd_hcf_lcm {
    public static void main(String[] args) {
        List<GCD_LCM> array = new ArrayList<GCD_LCM>();
        array.add(new GCD_LCM(126, 48));
        array.add(new GCD_LCM(393, 135));
        array.add(new GCD_LCM(894, 564));

        for (GCD_LCM item : array) {
            System.out.println(item);
        }
    }
}

public class GCD_LCM {
    int n1, n2;

    GCD_LCM(int num1, int num2) {
        n1 = num1;
        n2 = num2;
    };

    public int getGCD() {
        int temp1 = n1;
        int temp2 = n2;
        while (temp1 % temp2 != 0) {
            var remainder = temp1 % temp2;
            temp1 = temp2;
            temp2 = remainder;
        }
        return temp2;
    }

    // LCM (Lowest Common Multiple)
    // By using GCD
    public int getLCM() {
        return (n1 * n2) / getGCD();
    }

    public String toString() {
        return n1 + "," + n2 + "| GCD = " + getGCD() + ",| LCM = " + getLCM();
    }
}
