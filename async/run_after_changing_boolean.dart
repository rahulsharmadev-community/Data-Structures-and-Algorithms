import 'dart:async';

void main() async {
  // Initialize the boolean value
  bool downloading = false;

  // Create a timer that toggles the boolean value every 2 seconds
  var timer = Timer.periodic(Duration(seconds: 2), (timer) {
    downloading = !downloading;
    print('Toggled: $downloading');
  });

  // Wait until the toggle value becomes true
  await waitForDownloading(() => downloading);
  timer.cancel();
  print('Toggle value is now true');
}

Future<void> waitForDownloading(bool Function() condition) async {
  while (!condition()) {
    print('wait for 100ms');
    await Future.delayed(
        Duration(milliseconds: 100)); // Adjust the delay as needed
  }
}
