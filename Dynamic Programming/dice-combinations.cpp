#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const int P = 1e9 + 7; 
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 8;
  dp[5] = 16;
  dp[6] = 32;
  for (int i = 7; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      dp[i] = (dp[i] + dp[i - j] % P) % P;
    }
  }
  cout << dp[n] << "\n";
  return 0;
}
