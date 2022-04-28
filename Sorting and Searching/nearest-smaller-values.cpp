#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
map<pair<int, int>, int> memo;

int rmq(int l, int r);
int remember(int l, int r);

// range min query
int rmq(int l, int r) {
  if (l < 0 or r > n - 1) {
    return 0;
  }
  if (l == r) {
    return a[l];
  }
  int m = (l + r) / 2;
  return min(remember(l, m), remember(m + 1, r));
}

int remember(int l, int r) {
  pair<int, int> p = {l, r};
  if (memo.count(p) == 0) {
    memo[p] = rmq(l, r);
  }
  return memo[p];
}

int main() {
  cin >> n;
  a.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int mn = a[i];
    int r = i, l = r - 1;
    for (int p = 0; true; p++) {
      l = max(0, r - (1 << p));
      int res = rmq(l, r);
      if (res < mn) {
        mn = res;
        break;
      }
      if (l == 0) {
        break;
      }
    }
    // no value before a[i] is less than a[i]
    if (mn == a[i]) {
      cout << 0 << " ";
      continue;
    }
    while (l < r) {
      int m = (l + r) / 2;
      if (rmq(l, m) > mn) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    cout << l + 1 << " ";
  }
  cout << "\n";
  return 0;
}
