#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  vector<int> p(n);
  set<int> s = {0, x};
  multiset<int> d = {x};
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    auto before = prev(s.lower_bound(p[i]));
    auto after = s.upper_bound(p[i]);
    auto it = d.find(*after - *before);
    d.erase(it);
    d.insert(*after - p[i]);
    d.insert(p[i] - *before);
    s.insert(p[i]);
    int ans = *prev(d.end());
    cout << ans << " ";
  }
  cout << "\n";
  return 0;
}
