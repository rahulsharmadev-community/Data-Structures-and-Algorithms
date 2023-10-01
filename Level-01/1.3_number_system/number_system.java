public class number_system {

  public static void main(String[] args) {
    NumberSystem base16 = new NumberSystem("-10AB", 16);
    NumberSystem base8 = new NumberSystem("76154", 8);

    _print(base8 + " + " + base16 + " = " + base8.add(base16));
    _println();
    _print(base16 + " - " + base8 + " = " + base16.subtract(base8));
    _println();
    _print(base16 + " ⇌ " + base16.convertToBase(25));
    _println();
  }

  private static void _print(Object o) {
    System.out.print(o);
  }

  private static void _println() {
    System.out.println();
  }
}

class NumberSystem {

  final String number;
  final int base;

  NumberSystem(String number, int base) {
    _validBase(base);
    this.number = number;
    this.base = base;
  }

  int toDecimal() {
    return baseToDecimal(number, base);
  }

  NumberSystem convertToBase(int newBase) {
    return new NumberSystem(decimalToBase(toDecimal(), newBase), newBase);
  }

  public NumberSystem add(NumberSystem obj) {
    int a = toDecimal();
    int b = obj.toDecimal();
    return new NumberSystem(decimalToBase(a + b, base), base);
  }

  public NumberSystem subtract(NumberSystem obj) {
    int a = toDecimal();
    int b = obj.toDecimal();
    return new NumberSystem(decimalToBase(a - b, base), base);
  }

  @Override
  public String toString() {
    char[] _syntex = { '₀', '₁', '₂', '₃', '₄', '₅', '₆', '₇', '₈', '₉' };
    int temp = base;
    StringBuffer res = new StringBuffer();
    while (temp > 0) {
      res.insert(0, _syntex[temp % 10]);
      temp /= 10;
    }

    return "(" + number + ")" + res;
  }

  @Override
  public boolean equals(Object obj) {
    // Same object reference, so they are equal
    if (this == obj) return true;
    // Object is null or of a different class, so they are not equal
    if (obj == null || getClass() != obj.getClass()) return false;
    NumberSystem other = (NumberSystem) obj; // Cast the Object to NumberSystem
    return this.base == other.base && this.number.equals(other.number);
  }

  static final String _charSet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  static String decimalToBase(int n, int b) {
    _validBase(b);
    if (n == 0) return "0";
    StringBuffer str = new StringBuffer();

    boolean isNegative = n < 0;
    if (isNegative) n = -n;

    while (n > 0) {
      int last = n % b;
      str.insert(0, _charSet.charAt(last));
      n /= b;
    }

    return (isNegative ? "-" : "") + str;
  }

  static int baseToDecimal(String n, int b) {
    _validBase(b);
    if (b == 10) return Integer.parseInt(n);

    boolean isNegative = n.charAt(0) == '-';
    if (isNegative) n = n.substring(1);

    int decimal = 0;
    int power = 0;
    char[] _number = n.toUpperCase().toCharArray();

    for (int i = _number.length - 1; i >= 0; i--) {
      int digit = _charSet.indexOf(_number[i]);
      if (digit == -1) {
        throw new IllegalArgumentException("Invalid digit found.");
      }
      decimal += digit * Math.pow(b, power++);
    }

    return isNegative ? -decimal : decimal;
  }

  private static void _validBase(int base) {
    // Ensure that the base is within a valid range (between 2 and 36).
    if (base < 2 || base > 36) {
      throw new IllegalArgumentException("Base must be between 2 to 36.");
    }
  }
}
