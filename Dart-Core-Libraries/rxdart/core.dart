import 'package:jars_core/jars_core.dart';
import 'package:rxdart/rxdart.dart';

Stream<int> count() async* {
  for (var i = 0; i < 6; i++) {
    yield i;

    await Future.delayed(1.seconds);
  }
}

void main() {
  // Buffer example
  // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  // [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
  // One common use case is when multiple network requests arrive rapidly.
  // It's beneficial to implement a short-time buffer of 50-100 milliseconds to aggregate
  // these requests before sending a single request comprising all received requests.
  // Stream.periodic(100.milliseconds, (i) => i).buffer(Stream.periodic(1.seconds)).listen(print);

  // ConcatStream([
  //   Stream.periodic(200.milliseconds, (i) => 'Stream 2:${i * 3}').take(30),
  //   Stream.periodic(100.milliseconds, (i) => 'Stream 1:${i * 2}').take(30),
  // ]).listen(print);

  // MergeStream([
  //   Stream.periodic(200.milliseconds, (i) => 'Stream 2:${i * 3}').take(30),
  //   Stream.periodic(100.milliseconds, (i) => 'Stream 1:${i * 2}').take(30),
  // ]).listen(print);


  
}
