#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i] - 1] = i;
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (pos[i] > pos[i + 1]) {
      ans++;
    }
  }
  while (m--) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    set<pair<int, int>> changed;
    if (a[i] != 1) {
      changed.insert({a[i] - 1, a[i]});
    }
    if (a[i] != n) {
      changed.insert({a[i], a[i] + 1});
    }
    if (a[j] != 1) {
      changed.insert({a[j] - 1, a[j]});
    }
    if (a[j] != n) {
      changed.insert({a[j], a[j] + 1});
    }
    int d1 = 0;
    for (auto [x, y]: changed) {
      if (pos[x - 1] > pos[y - 1]) {
        d1++;
      }
    }
    swap(pos[a[i] - 1], pos[a[j] - 1]);
    swap(a[i], a[j]);
    int d2 = 0;
    for (auto [x, y]: changed) {
      if (pos[x - 1] > pos[y - 1]) {
        d2++;
      }
    }
    ans += d2 - d1;
    cout << ans + 1 << "\n";
  }
  return 0;
}
