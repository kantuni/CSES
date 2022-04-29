#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int i = 0, j = 0;
  long long sum = 0, ans = 0;
  while (i < n) {
    if (sum == x) {
      ans++;
    }
    if (sum <= x) {
      if (j == n) {
        break;
      }
      sum += a[j];
      j++;
    } else {
      sum -= a[i];
      i++;
    }
  }
  cout << ans << "\n";
  return 0;
}
