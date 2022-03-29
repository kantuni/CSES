#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int y, x;
    cin >> y >> x;
    long long d = max(y, x);
    // 1 + 2 + 4 + 6 + 8 + ... + d - 1 =
    // 1 + 2 * (1 + 2 + 3 + 4 + ... + d - 1) =
    // 1 + 2 * (1 + d - 1) * (d - 1) / 2 =
    // 1 + d * (d - 1)
    long long n = 1 + d * (d - 1);
    if (d % 2 == 0) {
      if (x < d) {
        n += d - x;
      }
      if (y < d) {
        n -= d - y;
      }
    } else {
      if (x < d) {
        n -= d - x;
      }
      if (y < d) {
        n += d - y;
      }
    }
    cout << n << "\n";
  }
  return 0;
}
