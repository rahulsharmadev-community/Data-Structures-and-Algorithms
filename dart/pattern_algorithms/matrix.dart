class Matrix<T> {
  final int row, column;
  final List<List<T?>> _array;

  Matrix(this.row, {int? column, T? fill})
      : column = column ?? row,
        _array = List.generate(row, (i) {
          return List.filled(column ?? row, fill, growable: true);
        });

  int get columnlast => column - 1;
  int get rowlast => row - 1;
  int get rowCenter => row ~/ 2;
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
