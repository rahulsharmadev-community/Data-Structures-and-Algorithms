import 'dart:async';

void main() {
  // Initialize the boolean value
  bool toggleValue = false;

  // Create a timer that toggles the boolean value every 2 seconds
  Timer.periodic(Duration(seconds: 2), (timer) {
    toggleValue = !toggleValue;
    print('Toggled: $toggleValue');
  });

  // Wait until the toggle value becomes true
  waitForToggleValue(toggleValue).then((_) {
    print('Toggle value is now true');
  });
}

Future<void> waitForToggleValue(bool targetValue) async {
  while (true) {
    if (targetValue) {
      break;
    }
    await Future.delayed(Duration(milliseconds: 100)); // Adjust the delay as needed
  }
}
