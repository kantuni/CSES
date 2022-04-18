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
  vector<int> tmp(s.begin(), s.end());
  int best = 0;
  for (int i = 0; i < (int) tmp.size(); i++) {
    best = max(best, tmp[i + 1] - tmp[i]);
  }
  vector<int> ans = {best};
  for (int i = n - 1; i > -1; i--) {
    // lower_bound will always point to p[i],
    // hence prev will point to the previous element.
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

