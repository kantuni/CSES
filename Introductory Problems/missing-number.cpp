#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long s = 0;
  for (int i = 0; i < n - 1; i++) {
    long long a;
    cin >> a;
    s += a;
  }
  long long ans = n * (n + 1) / 2 - s;
  cout << ans << "\n";
  return 0;
}
