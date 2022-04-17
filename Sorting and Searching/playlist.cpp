#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<int> memo;
  int ans = 0;
  int i = 0, j = 0;
  while (j < n) {
    if (memo.count(a[j]) == 0) {
      memo.insert(a[j]);
      j++;
    } else {
      memo.erase(a[i]);
      i++;
    }
    ans = max(ans, j - i);
  }
  cout << ans << "\n";
  return 0;
}
