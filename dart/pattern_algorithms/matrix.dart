class Matrix<T> {
  final int raw, column;
  final List<List<T?>> _array;

  Matrix(this.raw, {int? column, T? fill})
      : column = column ?? raw,
        _array = List.generate(raw, (i) {
          return List.filled(column ?? raw, fill, growable: true);
        });

  int get columnlast => column - 1;
  int get rowlast => raw - 1;
  int get rawCenter => raw ~/ 2;
  int get columnCenter => column ~/ 2;

  bool equalTo(int r, int c, T data) {
    return _array[r][c] == data;
  }

  void addAt(int raw, int column, T data) {
    _array[raw][column] = data;
  }

  @override
  String toString() {
    return _array.join('\n').replaceAll(RegExp(r'[\],[]'), '');
  }
}
