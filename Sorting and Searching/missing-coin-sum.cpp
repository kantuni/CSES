#include <bits/stdc++.h>
using namespace std;

vector<long long> a;

bool find(long long x, vector<long long>::iterator end) {
  if (x == 0) {
    return true;
  }
  auto nxt = upper_bound(a.begin(), end, x);
  if (nxt == a.begin()) {
    return false;
  }
  auto it = prev(nxt);
  return find(x - *it, it);
}

int main() {
  int n;
  cin >> n;
  a.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 1;
  while (find(ans, a.end())) {
    ans++;
  }
  cout << ans << "\n";
  return 0;
}
