#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    a[i] = {num, i};
  }
  sort(a.begin(), a.end());
  bool found = false;
  for (int i = 0; !found and i < n - 3; i++) {
    int ti = x - a[i].first;
    pair<int, int> pi = {ti, INT_MAX};
    auto upper = upper_bound(a.begin() + i, a.end(), pi);
    int max_j = upper - a.begin();
    for (int j = i + 1; !found and j < max_j; j++) {
      int tj = ti - a[j].first;
      pair<int, int> pj = {tj, INT_MAX};
      auto upper = upper_bound(a.begin() + j, a.end(), pj);
      auto max_k = upper - a.begin();
      for (int k = j + 1; !found and k < max_k; k++) {
        int target = x - a[i].first - a[j].first - a[k].first;
        pair<int, int> p = {target, INT_MIN};
        auto lower = lower_bound(a.begin() + k + 1, a.end(), p);
        if (lower != a.end() and (*lower).first == target) {
          int l = lower - a.begin();
          cout << a[i].second + 1 << " ";
          cout << a[j].second + 1 << " ";
          cout << a[k].second + 1 << " ";
          cout << a[l].second + 1 << "\n";
          found = true;
          break;
        }
      }
    }
  }
  if (!found) {
    cout << "IMPOSSIBLE" << "\n";
  }
  return 0;
}
