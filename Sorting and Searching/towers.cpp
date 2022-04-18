#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  multiset<int> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    auto it = s.upper_bound(a);
    if (it == s.end()) {
      s.insert(a);
      ans++;
    } else {
      s.erase(it);
      s.insert(a);
    }
  }
  cout << ans << "\n";
  return 0;
}
