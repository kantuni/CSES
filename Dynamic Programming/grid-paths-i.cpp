#include <bits/stdc++.h>
using namespace std;

int main() {
  const int P = 1e9 + 7;
  int n;
  cin >> n;
  char g[n][n];
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cin >> g[r][c];
    }
  }
  int memo[n][n];
  memset(memo, 0, sizeof memo);
  if (g[n - 1][n - 1] != '*') {
    memo[n - 1][n - 1] = 1;
  }
  for (int r = n - 1; r > -1; r--) {
    for (int c = n - 1; c > -1; c--) {
      if (g[r][c] == '*') {
        continue;
      }
      if (r + 1 < n and g[r + 1][c] != '*') {
        memo[r][c] += memo[r + 1][c];
        memo[r][c] %= P;
      }
      if (c + 1 < n and g[r][c + 1] != '*') {
        memo[r][c] += memo[r][c + 1];
        memo[r][c] %= P;
      }
    }
  }
  cout << memo[0][0] << "\n";
  return 0;
}
