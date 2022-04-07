#include <bits/stdc++.h>
using namespace std;

long long pow10(long long exp) {
  long long ans = 1;
  while (exp--) {
    ans *= 10;
  }
  return ans;
}

int solve(long long k) {
  if (k < 10) {
    return (int) k;
  }
  long long cur = 10;
  long long d = 2;
  while (true) {
    long long nxt = cur + 9 * d * pow10(d - 1);
    if (nxt > k) {
      break;
    }
    cur = nxt;
    d++;
  }
  long long f = (k - cur) / d;
  long long exact = cur + f * d;
  long long offset = k - exact;
  string num = to_string(pow10(d - 1) + f);
  return num[offset] - '0';
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;
    int ans = solve(k);
    cout << ans << "\n";
  }
  return 0;
}
