/// Palindromic Substrings
/// A string is a palindrome when it reads the same backward as forward.
/// A substring is a contiguous sequence of characters within the string.
///
/// Q- Given a string s, return the palindromic substrings in it.
///
/// Input: s = "aba"
/// Output: [a, b, c, aba]
///
/// [more]: https://leetcode.com/problems/palindromic-substrings
///

void main(List<String> args) {
  /// Testing
  var array = ['abc', 'aba', 'abccbc'];
  array.forEach((e) {
    var par = palindromeSubStrings(e);
    print('$e:- $par ');
  });
}

List<String> palindromeSubStrings(String input) {
  List<String> substrings = <String>[];

  /// Create Array
  var dp = List.generate(input.length, (i) {
    return List.filled(input.length, false, growable: true);
  });

  for (int g = 0; g < input.length; g++) {
    for (int i = 0, j = g; j < dp.length; i++, j++) {
      /// For when gap = 0
      if (g == 0) {
        dp[i][j] = true;
      }

      /// For when gap = 1
      else if (g == 1) {
        // true only if starting and ending char. are equal
        dp[i][j] = input[i] == input[j];
      }

      /// For remaing all gaps
      else {
        dp[i][j] = (input[i] == input[j] && dp[i + 1] == dp[j - 1]);
      }

      /// Add all substrings
      if (dp[i][j]) {
        //use j+1 because index start from 0
        substrings.add(input.substring(i, j + 1));
      }
    }
  }
  return substrings;
}
