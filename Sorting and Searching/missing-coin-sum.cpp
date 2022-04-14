#include <bits/stdc++.h>
using namespace std;

map<long long, int> memo;

bool find(long long x) {
  if (x == 0) {
    return true;
  }
  bool ok = false;
  for (auto [num, cnt]: memo) {
    if (num > x) {
      break;
    }
    if (memo[num] > 0) {
      memo[num]--;
      ok = ok or find(x - num);
      memo[num]++;
    }
  }
  return ok;
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[a[i]]++;
  }
  long long ans = 1;
  while (find(ans)) {
    ans++;
  }
  cout << ans << "\n";
  return 0;
}
