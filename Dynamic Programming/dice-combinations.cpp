#include <bits/stdc++.h>
using namespace std;

int main() {
  const int P = 1e9 + 7;
  int n;
  cin >> n;
  vector<int> memo(max(7, n + 1));
  memo[0] = 1;
  memo[1] = 1;
  memo[2] = 2;
  memo[3] = 4;
  memo[4] = 8;
  memo[5] = 16;
  memo[6] = 32;
  for (int i = 7; i < n + 1; i++) {
    for (int j = 1; j < 7; j++) {
      memo[i] += memo[i - j];
      memo[i] %= P;
    }
  }
  cout << memo[n] << "\n";
  return 0;
}
