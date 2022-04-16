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
    if (pos[i + 1] < pos[i]) {
      ans++;
    }
  }
  while (m--) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    // (i - 1, i) -> (i - 1, j)
    if (i - 1 >= 0) {
      if (pos[i - 1] > pos[i] and pos[i - 1] < pos[j]) {
        ans--;
      }
      if (pos[i - 1] < pos[i] and pos[i - 1] > pos[j]) {
        ans++;
      }
    }
    // (i, i + 1) -> (j, i + 1)
    if (i + 1 < n) {
      if (pos[i] > pos[i + 1] and pos[j] < pos[i + 1]) {
        ans--;
      }
      if (pos[i] < pos[i + 1] and pos[j] > pos[i + 1]) {
        ans++;
      }
    }
    // (j - 1, j) -> (j - 1, i)
    if (j - 1 >= 0) {
      if (pos[j - 1] > pos[j] and pos[j - 1] < pos[i]) {
        ans--;
      }
      if (pos[j - 1] < pos[j] and pos[j - 1] > pos[i]) {
        ans++;
      }
    }
    // (j, j + 1) -> (i, j + 1)
    if (j + 1 < n) {
      if (pos[j] > pos[j + 1] and pos[i] < pos[j + 1]) {
        ans--;
      }
      if (pos[j] < pos[j + 1] and pos[i] > pos[j + 1]) {
        ans++;
      }
    }
    swap(pos[a[i] - 1], pos[a[j] - 1]);
    swap(a[i], a[j]);
    cout << ans + 1 << "\n";
  }
  return 0;
}
