#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> m1, pair<int, int> m2) {
  auto [l1, r1] = m1;
  auto [l2, r2] = m2;
  if (r1 == r2) {
    return l1 < l2;
  }
  return r1 < r2;
}
 
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> ms(n);
  set<pair<int, int>> es;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ms[i] = { a, b };
  }
  sort(ms.begin(), ms.end(), cmp);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto [from, to] = ms[i];
    auto lower = es.lower_bound({ -from, INT_MIN });
    if (lower == es.end()) {
      if (k > 0) {
        es.insert({ -to, es.size() });
        ans++;
        k--;
      }
      continue;
    }
    es.insert({ -to, lower->second });
    es.erase(lower);
    ans++;
  }
  cout << ans << "\n";
  return 0;
}
