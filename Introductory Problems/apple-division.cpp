#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  long long sum = accumulate(p.begin(), p.end(), 0LL);
  long long ans = sum;
  for (int i = 0; i < (1 << n); i++) {
    bitset<32> b(i);
    // 0s in one group, 1s in the other.
    long long s1 = 0;
    for (int j = 0; j < n; j++) {
      if (b[j] == 1) {
        s1 += p[j];
      }
    }
    long long s2 = sum - s1;
    ans = min(ans, abs(s1 - s2));
  }
  cout << ans << "\n";
  return 0;
}
