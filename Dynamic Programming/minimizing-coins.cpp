#include <bits/stdc++.h>
using namespace std;

int main() {
  const int INF = 1e9;
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<int> memo(x + 1, INF);
  for (int i = 0; i < n; i++) {
    if (c[i] <= x) {
      memo[c[i]] = 1;
    }
  }
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (i - c[j] < 0) {
        continue;
      }
      memo[i] = min(memo[i], 1 + memo[i - c[j]]);
    }
  }
  int ans = memo[x] == INF ? -1 : memo[x];
  cout << ans << "\n";
  return 0;
}
