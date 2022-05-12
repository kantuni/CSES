#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> memo;
  long long ans = 0;
  int i = 0, j = 0;
  while (i < n) {
    while (j < n and memo.size() <= k) {
      memo[a[j]]++;
      j++;
    }
    if (memo.size() <= k) {
      ans += j - i;
    } else {
      ans += j - 1 - i;
    }
    memo[a[i]]--;
    if (memo[a[i]] == 0) {
      memo.erase(a[i]);
    }
    i++;
  }
  cout << ans << "\n";
  return 0;
}
