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
  vector<long long> ps(n + 1);
  partial_sum(a.begin(), a.end(), next(ps.begin()));
  map<long long, vector<int>> memo;
  for (int i = 0; i < n + 1; i++) {
    memo[ps[i]].push_back(i);
  }
  long long ans = 0;
  for (auto [ps1, js]: memo) {
    long long ps2 = ps1 - x;
    if (memo.count(ps2) == 0) {
      continue;
    }
    vector<int> is = memo[ps2];
    for (auto j: js) {
      auto upper = upper_bound(is.begin(), is.end(), j - 1);
      // We want to find the number of indices that are < j - 1.
      // Why? Because in the naive solution we would have counted
      // all intervals such that i + 1 < j (+1 to find the actual
      // starting index - not the prefix sum index.
      int cnt = upper - is.begin();
      ans += cnt; 
    }
  }
  cout << ans << "\n";
  return 0;
}
