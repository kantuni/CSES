#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  while (n >= 5) {
    ans += n / 5;
    n /= 5;
  }
  cout << ans << "\n";
  return 0;
}
