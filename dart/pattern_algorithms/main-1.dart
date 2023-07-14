import 'matrix.dart';

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

  for (int i = 0; i < dp.raw; i++) {
    dp.addAt(i, dp.columnCenter - i, 'x');
    dp.addAt(i, dp.columnCenter + i, 'x');
    dp.addAt(dp.rowlast, i, 'x');
    dp.addAt(dp.rowlast, i + dp.columnCenter, 'x');

    if (i < dp.rawCenter) {
      dp.addAt(dp.raw - 1 - i, dp.columnCenter - i, 'x');
      dp.addAt(dp.raw - 1 - i, dp.columnCenter + i, 'x');
    }

    dp.addAt(dp.rawCenter, i + dp.rawCenter, 'x');
    dp.addAt(dp.rawCenter, i + dp.rawCenter, 'x');
  }
  print(dp);
}

/ Not Working
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
  var sp = (dp.raw - size) - 1;
  var ep = sp + (size ~/ 2) - 1;
  for (var i = 0; i < dp.raw; i++) {
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
  var sp = (dp.raw - size) - 1;
  var ep = sp + (size / 2) - 1;
  for (var i = 0; i < dp.raw; i++) {
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
  for (int i = dp.lastIndex; i >= 0; i--) {
    if (i == dp.lastIndex) {
      for (int f = 0; f <= dp.center; f++) {
        dp.addAt(i, f, 'x');
        dp.addAt(f, dp.lastIndex - i, 'x');
      }
    } else if (i == 0) {
      for (int f = dp.center; f < dp.length; f++) {
        dp.addAt(i, f, 'x');
        dp.addAt(f, dp.lastIndex - i, 'x');
      }
    } else {
      dp.addAt(i, dp.center, 'x');
      dp.addAt(dp.center, i, 'x');
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
  int j = dp.center;
  for (int i = 0; i < dp.length; i++) {
    dp.addAt(i, j, 'x');

    if (i != 0 && i != dp.lastIndex)
      dp.addAt(dp.lastIndex - i, dp.lastIndex - j, 'x');

    if (i < dp.center) {
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
  for (var i = 0; i < dp.length; i++) {
    for (int l = 0; l < objects; l++) {
      dp.addAt(i, l, 'x');
      dp.addAt(i, dp.column - l - 1, 'x');
    }
    if (i < dp.raw ~/ 2) {
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
  int startIndex = dp.center;
  for (var raw = 0; raw < dp.length; raw++) {
    for (int i = startIndex; i < startIndex + objects; i++) {
      dp.addAt(raw, i, 'x');
    }
    if (raw < dp.center) {
      startIndex--;
      objects += 2;
    } else {
      startIndex++;
      objects -= 2;
    }
  }
  print(dp);
}

void rightTrangle(List<String> args) {e
  /// ---------Output-------
  ///         @
  ///       @ @
  ///     @ @ @
  ///   @ @ @ @
  /// @ @ @ @ @
  var dp = Matrix<String>(5, fill: ' ');
  for (var raw = 0; raw <= dp.lastIndex; raw++) {
    var column = dp.lastIndex;
    while (column >= dp.lastIndex - raw) {
      dp.addAt(raw, column, 'x');
      column--;
    }
  }
  print(dp);
}
