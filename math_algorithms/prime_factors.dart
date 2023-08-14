///
/// A prime factor is a natural number, other than 1, whose only
///  factors are 1 and itself. The first few prime numbers are
///  actually 2, 3, 5, 7, 11, and so on.
///  [More]: https://www.geeksforgeeks.org/prime-factor/
///
///
void main(List<String> args) {
  // Testing
  var array = [315, 99, 64];
  array.forEach((e) {
    var p = primeFactor(e);
    var mult = p.reduce((v, e) => v * e);

    print('$p = $mult');
  });
}

List<int> primeFactor(int n) {
  var factors = <int>[];

  /// For all number divisible by 2
  while (n % 2 == 0) {
    factors.add(2);
    n = n ~/ 2;
  }

  /// For all number non-divisible by 2
  for (int i = 3; i <= n; i += 2) {
    while (n % i == 0) {
      factors.add(i);
      n = n ~/ i;
    }
  }

  return factors;
}
