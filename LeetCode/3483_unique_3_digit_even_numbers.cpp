// Online C++ compiler to run C++ program online
#include <array>
#include <iostream>
#include <string>

using namespace std;

int runner(string s) {
  array<int, 256> arr;
  arr.fill(-1);

  // Biggest substring faced
  int biggest = 0;

  // Length of input
  int n = s.length();

  int right = 0;
  for (int left = 0; left < n; left++) {
    // Current iteration substring
    int current = left > 0 ? right - left : 0;

    // Easy out case, impossible to have longer strings ahead when
    // remaining substring + current substring is already less than
    // biggest substring
    if (biggest > (current + n - left)) {
      break;
    }

    while (right < n) {
      char thisChar = s[right];
      cout << current << "\t" << left << "\t" << right << "\t" << thisChar
           << "\t" << arr[thisChar] << endl;

      // Calculation is needed only if current is empty
      if (current != 0) {
        int index = arr[thisChar];
        // If the char is in our sliding window
        if (index != -1 && index >= left && index <= right) {
          // Special case for repeating chars
          if (right + 1 < n && s[right] == s[right + 1]) {
              int offsetCounter = 2;
              while (right + offsetCounter < n && s[right] == s[right + offsetCounter]) {
                  offsetCounter++;
              }

              // offsetCounter should be at a non unique char or out of bounds, reset window and start loop again.
              right += offsetCounter - 1;
              left = right - 1; // counter for loop increment
              break;
          }

          // Update window L and char map
          left = index; // -1 ensures to counter the loop increment
          arr[thisChar] = right++;
          break;
        }
      }

      // Update current and char map
      current += thisChar;
      arr[thisChar] = right;
      right++;
    }

    // If current is bigger than biggest, update.
    if (current > biggest) {
      biggest = current;
    }
  }

  return biggest;
}

int main() {
  cout << runner("bbba");

  return 0;
}
