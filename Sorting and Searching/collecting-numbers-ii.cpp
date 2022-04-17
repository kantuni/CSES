#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  unordered_map<int, int> pos;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (pos[i] > pos[i + 1]) {
      ans++;
    }
  }
  while (m--) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    set<pair<int, int>> s;
    if (a[i] != 1) {
      s.insert({a[i] - 1, a[i]});
    }
    if (a[i] != n) {
      s.insert({a[i], a[i] + 1});
    }
    if (a[j] != 1) {
      s.insert({a[j] - 1, a[j]});
    }
    if (a[j] != n) {
      s.insert({a[j], a[j] + 1});
    }
    int d1 = 0;
    for (auto [x, y]: s) {
      if (pos[x] > pos[y]) {
        d1++;
      }
    }
    swap(pos[a[i]], pos[a[j]]);
    swap(a[i], a[j]);
    int d2 = 0;
    for (auto [x, y]: s) {
      if (pos[x] > pos[y]) {
        d2++;
      }
    }
    ans += d2 - d1;
    cout << ans + 1 << "\n";
  }
  return 0;
}
