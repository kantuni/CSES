#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int y, x;
    cin >> y >> x;
    long long n = 1;
    int d = max(y, x);
    for (int r = 1; r < d; r++) {
      n += 2 * r;
    }
    if (d % 2 == 0) {
      while (x < d) {
        n++;
        x++;
      }
      while (y < d) {
        n--;
        y++;
      }
    } else {
      while (x < d) {
        n--;
        x++;
      }
      while (y < d) {
        n++;
        y++;
      }
    }
    cout << n << "\n";
  }
  return 0;
}
