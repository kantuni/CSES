#include <bits/stdc++.h>
using namespace std;

set<int> digits(int n) {
  set<int> d;
  while (n > 0) {
    d.insert(n % 10);
    n /= 10;
  }
  return d;
}

int main() {
  const int INF = 1e9;
  int n;
  cin >> n;
  vector<int> memo(n + 1, INF);
  memo[0] = 0;
  for (int i = 0; i < n + 1; i++) {
    for (auto d: digits(i)) {
      if (d == 0 or i - d < 0) {
        continue;
      }
      memo[i] = min(memo[i], 1 + memo[i - d]);
    }
  }
  cout << memo[n] << "\n";
  return 0;
}
