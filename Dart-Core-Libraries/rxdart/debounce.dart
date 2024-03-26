import 'dart:async';

import 'package:jars_core/jars_core.dart';
import 'package:rxdart/rxdart.dart';
import 'package:test/test.dart';

const _1s = Duration(seconds: 1);
Stream<int> count() async* {
  for (var i = 0; i < 6; i++) {
    yield i;

    await Future.delayed(_1s);
  }
}

Future withDelay(int ms, Function() fun) {
  return Future.delayed(Duration(milliseconds: ms), fun);
}

void main() async {
  StreamController controller = StreamController();

  controller.stream.debounce((event) {
    return TimerStream(event, 1.seconds);
  }).listen(print);

  await withDelay(100, () => controller.sink.add(1));
  await withDelay(300, () => controller.sink.add(2));
  await withDelay(800, () => controller.sink.add(3));
  await withDelay(1000, () => controller.sink.add(4));

  controller.stream.debounceTime(200.milliseconds).listen(print);

  await withDelay(0, () => controller.sink.add(1));
  await withDelay(200, () => controller.sink.add(2));
  await withDelay(200, () => controller.sink.add(3));
  await withDelay(200, () => controller.sink.add(4));
  await withDelay(200, () => controller.sink.add(5));

  controller.stream.throttleTime(200.milliseconds).listen(print);

  await withDelay(0, () => controller.sink.add(1));
  await withDelay(200, () => controller.sink.add(2));
  await withDelay(200, () => controller.sink.add(3));
  await withDelay(150, () => controller.sink.add(4));
  await withDelay(40, () => controller.sink.add(5));
}
