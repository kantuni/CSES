#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  // Maintain monotonic stack
  stack<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    while (!s.empty() and s.top().first >= a[i]) {
      s.pop();
    }
    if (s.empty()) {
      cout << 0 << " ";
    } else {
      cout << s.top().second << " ";
    }
    s.push({a[i], i + 1});
  }
  cout << "\n";
  return 0;
}
