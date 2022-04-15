#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  int i = 0;
  while (i < n and ans + 1 >= a[i]) {
    ans += a[i];
    i++;
  }
  cout << ans + 1 << "\n";
  return 0;
}
