#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
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
  cout << ans + 1 << "\n";
  return 0;
}
