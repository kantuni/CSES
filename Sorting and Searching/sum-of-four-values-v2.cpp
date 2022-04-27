#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<long long, pair<int, int>> memo;
  bool found = false;
  for (int i = 0; !found and i < n - 1; i++) {
    for (int j = i + 1; !found and j < n; j++) {
      long long target = x - a[i] - a[j];
      if (memo.count(target) > 0) {
        auto [k, l] = memo[target];
        cout << i + 1 << " ";
        cout << j + 1 << " ";
        cout << k + 1 << " ";
        cout << l + 1 << "\n";
        found = true;
        break;
      }
    }
    for (int k = 0; !found and k < i; k++) {
      memo[a[k] + a[i]] = {k, i};
    }
  }
  if (!found) {
    cout << "IMPOSSIBLE" << "\n";
  }
  return 0;
}
