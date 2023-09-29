public class pattern_06 {

  public static void main(String[] args) throws InterruptedException {}

  public static void clearConsole() {
    try {
      final String os = System.getProperty("os.name");

      if (os.contains("Windows")) {
        // For Windows, you can use the "cls" command
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
      } else {
        // For Unix/Linux/Mac, use ANSI escape codes
        System.out.print("\033[H\033[2J");
        System.out.flush();
      }
    } catch (Exception e) {
      // Handle exceptions if any
      e.printStackTrace();
    }
  }
}
