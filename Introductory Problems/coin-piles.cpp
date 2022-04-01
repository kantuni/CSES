#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      swap(a, b);
    }
    // Find max k where
    // a - 2 * k <= b - k
    int k = a - b;
    a -= 2 * k;
    b -= k;
    // a and b are now equal
    // We need to solve the following
    // system of equations:
    // 2x + y = a
    // 2y + x = a
    // which yields 3y = a.
    // Thus a must divide 3 evenly.
    if (a >= 0 and a % 3 == 0) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}
