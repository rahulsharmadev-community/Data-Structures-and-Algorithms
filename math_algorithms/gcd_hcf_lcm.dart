///
/// Greatest Common Divisor (GCD) or Highest Common Factor (HCF)
/// of two positive integers is the largest positive integer that
/// divides both numbers without remainder.
/// [more]: https://www.idomaths.com/hcflcm.php#findhcf
///
/// Least Common Multiple (LCM) of two integers is the smallest
/// integer that is a multiple of both numbers.
/// [more]: https://www.idomaths.com/hcflcm.php#findlcm
///

void main(List<String> args) {
  /// Testing
  var array = [
    GCD_LCM(126, 48),
    GCD_LCM(393, 135),
    GCD_LCM(894, 564),
  ];

  for (GCD_LCM item in array) {
    print('${item.n1},${item.n2}'
        ' |GCD = ${item.getGCD}, '
        'LCM =  ${item.getLCM}');
  }
}

class GCD_LCM {
  final int n1, n2;
  const GCD_LCM(this.n1, this.n2);

  /// GCD (Greatest Common Divison)
  int get getGCD {
    var temp1 = n1;
    var temp2 = n2;
    // By using division method
    while (temp1 % temp2 != 0) {
      var remainder = temp1 % temp2;
      temp1 = temp2;
      temp2 = remainder;
    }
    return temp2;
  }

  /// LCM (Lowest Common Multiple)
  /// By using GCD
  int get getLCM {
    return (n1 * n2) ~/ getGCD;
  }
}
