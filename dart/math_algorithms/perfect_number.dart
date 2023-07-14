///
/// A perfect number is a positive integer that is equal
/// to the sum of its positive divisors, excluding the number
/// itself.
/// For instance, 6 has divisors 1, 2 and 3
/// and 1 + 2 + 3 = 6, so 6 is a perfect number.
/// [more]: https://en.wikipedia.org/wiki/Perfect_number
///
void main(List<String> args) {
  /// Testing
  var array = [35, 28, 496, 4, 7, 6];
  array.forEach((e) {
    var result = isPerfectNumber(e);
    print(result ? '$e is Perfect no.' : '$e is not Perfect no.');
  });
}

isPerfectNumber(int n) {
  var sum = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }
  return sum == n;
}
