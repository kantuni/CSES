#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> memo;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[a[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (memo[i + 1] < memo[i]) {
      ans++;
    }
  }
  cout << ans + 1 << "\n";
  return 0;
}
