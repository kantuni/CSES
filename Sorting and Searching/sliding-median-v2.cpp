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
  set<pair<int, int>> ls, rs;
  for (int i = 0; i < k; i++) {
    ls.insert({a[i], i});
  }
  while (ls.size() > (k - 1) / 2 + 1) {
    auto lmx = *ls.rbegin();
    rs.insert(lmx);
    ls.erase(lmx);
  }
  int i = 0, j = k;
  while (j <= n) {
    auto m = *ls.rbegin();
    cout << m.first << " ";
    // insert a[j]
    pair<int, int> aj = {a[j], j};
    if (aj > m) {
      rs.insert(aj);
    } else {
      ls.insert(aj);
    }
    // erase a[i]
    pair<int, int> ai = {a[i], i};
    if (ls.count(ai) > 0) {
      ls.erase(ai);
    } else {
      rs.erase(ai);
    }
    // rebalance (ls -> rs)
    while (ls.size() > (k - 1) / 2 + 1) {
      auto lmx = *ls.rbegin();
      rs.insert(lmx);
      ls.erase(lmx);
    }
    // rebalance (rs -> ls)
    while (rs.size() > k / 2) {
      auto rmn = *rs.begin();
      ls.insert(rmn);
      rs.erase(rmn);
    }
    i++, j++;
  }
  cout << "\n";
  return 0;
}
