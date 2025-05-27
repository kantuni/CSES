#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
      cout << "NO" << "\n";
      continue;
    }
    int z = n - (a + b);
    if (z == n - 1) {
      cout << "NO" << "\n";
      continue;
    }
    vector<int> ta, tb;
    for (int i = 1; i <= n; i++) {
      ta.push_back(i);
    }
    // Ties
    for (int i = 0; i < z; i++) {
      tb.push_back(ta[i]);
    }
    // B wins
    for (int i = n - b; i < n; i++) {
      tb.push_back(ta[i]);
    }
    // A wins
    for (int i = 0; i < a; i++) {
      tb.push_back(ta[z + i]);
    }
    // Verify
    int ac = 0, bc = 0;
    for (int i = 0; i < n; i++) {
      if (ta[i] > tb[i]) {
        ac++;
      } else if (tb[i] > ta[i]) {
        bc++;
      }
    }
    set<int> sa(ta.begin(), ta.end());
    set<int> sb(tb.begin(), tb.end());
    if (ac != a or bc != b or sa.size() != n or sb.size() != n) {
      cout << "NO" << "\n";
      continue;
    }
    cout << "YES" << "\n";
    for (auto tai: ta) {
      cout << tai << " ";
    }
    cout << "\n";
    for (auto tbi: tb) {
      cout << tbi << " ";
    }
    cout << "\n";
  }
  return 0;
}
