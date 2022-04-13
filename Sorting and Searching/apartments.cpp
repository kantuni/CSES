#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = 0;
  int i = 0, j = 0;
  while (i < n and j < m) {
    int x = a[i], y = b[j];
    if (x - k <= y and y <= x + k) {
      ans++;
      i++, j++;
    }
    if (x - k > y) {
      j++;
    }
    if (y > x + k) {
      i++;
    }
  }
  cout << ans << "\n";
  return 0;
}
