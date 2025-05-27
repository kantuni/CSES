#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<int> dp(x + 1, INF);
  for (int i = 0; i < n; i++) {
    if (c[i] <= x) {
      dp[c[i]] = 1;
    }
  }
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (i - c[j] < 0) {
        continue;
      }
      dp[i] = min(dp[i], 1 + dp[i - c[j]]);
    }
  }
  int ans = dp[x] == INF ? -1 : dp[x];
  cout << ans << "\n";
  return 0;
}
