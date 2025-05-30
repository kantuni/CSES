#include <bits/stdc++.h>
using namespace std;

int main() {
  const int P = 1e9 + 7;
  int n, x;
  cin >> n >> x;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<int> memo(x + 1);
  // This is the same as doing memo[c[i]] = 1
  memo[0] = 1;
  for (int i = 0; i < x + 1; i++) {
    for (int j = 0; j < n; j++) {
      if (i - c[j] < 0) {
        continue;
      }
      memo[i] += memo[i - c[j]];
      memo[i] %= P;
    }
  }
  cout << memo[x] << "\n";
  return 0;
}
