#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  // HACK: Allocate more space to avoid going out of bounds.
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<pair<long long, int>> ls, rs;
  long long L = 0, R = 0;
  for (int i = 0; i < k; i++) {
    ls.insert({a[i], i});
    L += a[i];
  }
  // rebalance (ls -> rs)
  while (ls.size() > k / 2 + k % 2) {
    auto lmx = *ls.rbegin();
    rs.insert(lmx);
    R += lmx.first;
    ls.erase(lmx);
    L -= lmx.first;
  }
  auto cost = [&](long long median) {
    return (median * ls.size() - L) + (R - median * rs.size());
  };
  int i = 0, j = k;
  while (j <= n) {
    auto m = *ls.rbegin();
    long long c = cost(m.first);
    // if k is even - try both medians
    if (k % 2 == 0) {
      auto ma = *rs.begin();
      long long ca = cost(ma.first);
      c = min(c, ca);
    }
    cout << c << " ";
    // insert a[j]
    pair<long long, int> aj = {a[j], j};
    if (aj > m) {
      rs.insert(aj);
      R += a[j];
    } else {
      ls.insert(aj);
      L += a[j];
    }
    // erase a[i]
    pair<long long, int> ai = {a[i], i};
    if (ls.count(ai) > 0) {
      ls.erase(ai);
      L -= a[i];
    } else {
      rs.erase(ai);
      R -= a[i];
    }
    // rebalance (ls -> rs)
    while (ls.size() > k / 2 + k % 2) {
      auto lmx = *ls.rbegin();
      rs.insert(lmx);
      R += lmx.first;
      ls.erase(lmx);
      L -= lmx.first;
    }
    // rebalance (rs -> ls)
    while (ls.size() < k / 2 + k % 2) {
      auto rmn = *rs.begin();
      ls.insert(rmn);
      L += rmn.first;
      rs.erase(rmn);
      R -= rmn.first;
    }
    i++, j++;
  }
  cout << "\n";
  return 0;
}
