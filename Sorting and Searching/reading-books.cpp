#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t.begin(), t.end());
  long long a = 0, b = 0;
  int i = 0, j = n - 1;
  while (i <= j) {
    if (a < b) {
      a += t[i];
      i++;
    } else {
      b += t[j];
      j--;
    }
  }
  long long ans = a + b;
  // If a read all the books except the last one,
  // and still has to wait for b to finish.
  if (a < b and j == n - 2) {
    long long wait = abs(b - a);
    ans += wait;
  }
  cout << ans << "\n";
  return 0;
}
