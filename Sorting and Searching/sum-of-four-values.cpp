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
    for (int j = i + 1; !found and j < n - 2; j++) {
      for (int k = j + 1; !found and k < n - 1; k++) {
        if (k > j + 1 and a[k].first == a[k - 1].first) {
          continue;
        }
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
