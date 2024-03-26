import 'dart:async';

import 'package:rxdart/rxdart.dart';

const _1s = Duration(seconds: 1);
const _2s = Duration(seconds: 2);
void main() async {
  StreamController<int> ctr = StreamController();

  Future.delayed(_1s, () => ctr.sink.add(2));
  Future.delayed(_2s, () => ctr.sink.add(3));
  Future.delayed(_1s + _2s, () => ctr.sink.add(4));
  Future.delayed(_2s + _2s, () => ctr.sink.add(6));

  ctr.stream.debounce((event) => TimerStream(event, Duration(milliseconds: 500))).listen(print);
}
