

void tranglePatten(List<String> args) {
  /// ---------Trangle-----------
  ///                 x
  ///               x   x
  ///             x       x
  ///           x x x x x x x
  ///         x   x       x   x
  ///       x       x   x       x
  ///     x x x x x x x x x x x x x
  ///
  var size = 7;
  var dp = Matrix<String>(
    size % 2 == 0 ? size + 1 : size,
    column: (size * 1.8).ceil(),
    fill: ' ',
  );

  for (int i = 0; i < dp.row; i++) {
    dp.addAt(i, dp.columnCenter - i, 'x');
    dp.addAt(i, dp.columnCenter + i, 'x');
    dp.addAt(dp.rowlast, i, 'x');
    dp.addAt(dp.rowlast, i + dp.columnCenter, 'x');

    if (i < dp.rowCenter) {
      dp.addAt(dp.row - 1 - i, dp.columnCenter - i, 'x');
      dp.addAt(dp.row - 1 - i, dp.columnCenter + i, 'x');
    }

    dp.addAt(dp.rowCenter, i + dp.rowCenter, 'x');
    dp.addAt(dp.rowCenter, i + dp.rowCenter, 'x');
  }
  print(dp);
}

void heartStarPatten(List<String> args) {
  ///-------Heart Star Pattern---------
  ///
  ///        @ @ @       @ @ @
  ///      @       @   @       @
  ///      @         @         @
  ///        @               @
  ///          @           @
  ///            @       @
  ///              @   @
  ///                @

  var size = 6;
  var dp = Matrix<String>(
    (size * 1.3).round(),
    column: size * 2 - 1,
    fill: ' ',
  );
  var sp = (dp.row - size) - 1;
  var ep = sp + (size ~/ 2) - 1;
  for (var i = 0; i < dp.row; i++) {
    if (i < sp)
      for (var j = sp; j <= ep; j++) {
        dp.addAt(i, j, 'x');
        dp.addAt(i, dp.column - 1 - j, 'x');
      }
    if (sp < 1) {
      dp.addAt(i, ep, 'x');
      dp.addAt(i, dp.column - 1 - ep, 'x');
    }

    dp.addAt(i, sp, 'x');
    dp.addAt(i, dp.column - 1 - sp, 'x');
    if (ep < size - 1) {
      ep++;
      if (sp > 0) sp--;
    } else {
      sp++;
    }
  }
  print(dp);
}

void fillHeartStarPatten(List<String> args) {
  ///---------Heart Star Pattern---------
  ///   @ @ @       @ @ @
  /// @ @ @ @ @   @ @ @ @ @
  /// @ @ @ @ @ @ @ @ @ @ @
  ///   @ @ @ @ @ @ @ @ @
  ///     @ @ @ @ @ @ @
  ///       @ @ @ @ @
  ///         @ @ @
  ///           @
  var size = 6;
  var dp = Matrix<String>(
    (size * 1.3).round(),
    column: size * 2 - 1,
    fill: ' ',
  );
  var sp = (dp.row - size) - 1;
  var ep = sp + (size / 2) - 1;
  for (var i = 0; i < dp.row; i++) {
    for (var j = sp; j <= ep; j++) {
      dp.addAt(i, j, 'x');
      if (j != size - 1) dp.addAt(i, dp.column - 1 - j, 'x');
    }

    if (ep < size - 1) {
      ep++;
      if (sp > 0) sp--;
    } else {
      sp++;
    }
  }
  print(dp);
}

void jaiShriGanesh(List<String> args) {
  ///
  /// ------------Output---------
  /// @   @ @ @
  /// @   @
  /// @ @ @ @ @
  ///     @   @
  /// @ @ @   @
  ///
  var dp = Matrix<String>(5, fill: ' ');
  for (int i = dp.row; i >= 0; i--) {
    if (i == dp.rowlast) {
      for (int f = 0; f <= dp.rowCenter; f++) {
        dp.addAt(i, f, 'x');
        dp.addAt(f, dp.rowlast - i, 'x');
      }
    } else if (i == 0) {
      for (int f = dp.rowCenter; f < dp.rowlast; f++) {
        dp.addAt(i, f, 'x');
        dp.addAt(f, dp.rowlast - i, 'x');
      }
    } else {
      dp.addAt(i, dp.rowCenter, 'x');
      dp.addAt(dp.rowCenter, i, 'x');
    }
  }
  print(dp);
}

void cube(List<String> args) {
  ///----------Output---------
  ///     @
  ///   @   @
  /// @       @
  ///   @   @
  ///     @
  var dp = Matrix<String>(5, fill: ' ');
  int j = dp.rowCenter;
  for (int i = 0; i < dp.rowlast; i++) {
    dp.addAt(i, j, 'x');

    if (i != 0 && i != dp.columnlast)
      dp.addAt(dp.columnlast - i, dp.columnlast - j, 'x');

    if (i < dp.rowCenter) {
      j++;
    } else {
      j--;
    }
  }
  print(dp);
}

void inBoxCube(List<String> args) {
  /// -------------Output---------------
  /// @ @ @ @ @   @ @ @ @ @
  /// @ @ @ @       @ @ @ @
  /// @ @ @           @ @ @
  /// @ @               @ @
  /// @                   @
  /// @ @               @ @
  /// @ @ @           @ @ @
  /// @ @ @ @       @ @ @ @
  /// @ @ @ @ @   @ @ @ @ @

  var dp = Matrix(9, column: 11, fill: ' ');
  int objects = dp.column ~/ 2;
  for (var i = 0; i < dp.rowlast; i++) {
    for (int l = 0; l < objects; l++) {
      dp.addAt(i, l, 'x');
      dp.addAt(i, dp.column - l - 1, 'x');
    }
    if (i < dp.row ~/ 2) {
      objects--;
    } else {
      objects++;
    }
  }

  print(dp);
}

void fillCube(List<String> args) {
  /// ---------Output-------
  ///     @
  ///   @ @ @
  /// @ @ @ @ @
  ///   @ @ @
  ///     @
  ///
  var dp = Matrix<String>(5, fill: ' ');

  int objects = 1;
  int startIndex = dp.rowCenter;
  for (var raw = 0; raw < dp.rowlast; raw++) {
    for (int i = startIndex; i < startIndex + objects; i++) {
      dp.addAt(raw, i, 'x');
    }
    if (raw < dp.rowCenter) {
      startIndex--;
      objects += 2;
    } else {
      startIndex++;
      objects -= 2;
    }
  }
  print(dp);
}

void rightTrangle(List<String> args) {
  /// ---------Output-------
  ///         @
  ///       @ @
  ///     @ @ @
  ///   @ @ @ @
  /// @ @ @ @ @
  var dp = Matrix<String>(5, fill: ' ');
  for (var raw = 0; raw <= dp.rowlast; raw++) {
    var column = dp.rowlast;
    while (column >= dp.columnlast - raw) {
      dp.addAt(raw, column, 'x');
      column--;
    }
  }
  print(dp);
}


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
