#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, x;
  cin >> n >> x;
  vector<long long> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int ans = 0;
  int i = 0, j = n - 1;
  while (p[j] > x) {
    ans++;
    j--;
  }
  while (i <= j) {
    if (p[i] + p[j] <= x) {
      ans++;
      i++, j--;
    } else {
      ans++;
      j--;
    }
  }
  cout << ans << "\n";
  return 0;
}
