#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  vector<int> p(n);
  set<int> s = {0, x};
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    s.insert(p[i]);
  }
  vector<int> ans;
  vector<int> tmp(s.begin(), s.end());
  int best = 0;
  for (int i = 0; i < (int) tmp.size(); i++) {
    best = max(best, tmp[i + 1] - tmp[i]);
  }
  ans.push_back(best);
  for (int i = n - 1; i > -1; i--) {
    auto before = prev(s.lower_bound(p[i]));
    auto after = s.upper_bound(p[i]);
    best = max(best, *after - *before);
    ans.push_back(best);
    s.erase(p[i]);
  }
  for (int i = n - 1; i > -1; i--) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
