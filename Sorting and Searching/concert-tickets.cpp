#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  multiset<int> h;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    h.insert(p);
  }
  vector<int> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < m; i++) {
    auto nxt = h.upper_bound(t[i]);
    if (nxt == h.begin()) {
      cout << -1 << "\n";
      continue;
    }
    auto it = prev(nxt);
    cout << *it << "\n";
    h.erase(it);
  }
  return 0;
}
