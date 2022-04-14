#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, x;
  cin >> n >> x;
  map<long long, int> memo;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    long long target = x - a;
    if (memo.count(target) > 0) {
      cout << i + 1 << " " << memo[target] + 1 << "\n";
      ok = true;
      break;
    }
    memo[a] = i;
  }
  if (!ok) {
    cout << "IMPOSSIBLE" << "\n";
  }
  return 0;
}
