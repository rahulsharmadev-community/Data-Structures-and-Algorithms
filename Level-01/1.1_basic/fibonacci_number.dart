/// Q - Print first n Fibonacci Numbers
///
void main(List<String> args) {
  /// Testing
  var array = [6, 15, 19, 16];
  array.forEach((element) => print(fibonacci(element)));
}

List<int> fibonacci(int n) {
  var series = <int>[];
  int a = 0, b = 1;
  for (int i = 0; i < n; i++) {
    series.add(a);
    int c = a + b;
    a = b;
    b = c;
  }
  return series;
}
