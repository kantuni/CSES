#include <bits/stdc++.h>
using namespace std;

long long solve(long long n);
long long remember(long long n);

map<long long, long long> memo;

long long solve(long long n) {
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 6;
  }
  if (n == 3) {
    return 28;
  }
  // There are 3 pieces that attack 2 cells in the last row or column.
  long long s1 = 3 * (n * n - 1 - 2);
  // There are 4 pieces that attack 3 cells.
  long long s2 = 4 * (n * n - 1 - 3);
  // The rest of the pieces in the last row or column, i.e. (2 * n - 1 - 3 - 4) attack 4 cells.
  long long s3 = (2 * n - 1 - 3 - 4) * (n * n - 1 - 4);
  // There are (a + b) / 2 combinations where both knights are 
  // on the last row or column.
  // a = 4 * (2 * n - 1 - 1)
  // There are 4 cells where both knights are 
  // on the last row or column and attack each other, thus there are only
  // (2 * n - 1 - 1) cells available for the next knight.
  // b = (2 * n - 1 - 4) * (2 * n - 1 - 2)
  // For all other cells in the last row or column
  // (except the above 4) there are (2 * n - 1 - 2) cells 
  // available for the next knight.
  // And since we counted the order of knights, we have to divide 
  // the sum by 2.
  // Thus, there are (n - 1) * (2 * n - 5) + 2 * (2 * n - 3) combinations
  // counted twice.
  long long d = (n - 1) * (2 * n - 5) + 2 * (2 * n - 3);
  return remember(n - 1) + s1 + s2 + s3 - d;
}

long long remember(long long n) {
  if (memo.count(n) == 0) {
    memo[n] = solve(n);
  }
  return memo[n];
}

int main() {
  long long n;
  cin >> n;
  for (int k = 1; k <= n; k++) {
    long long ans = solve(k);
    cout << ans << "\n";
  }
  return 0;
}
