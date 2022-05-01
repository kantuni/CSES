#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long x;
  cin >> n >> x;
  // Adding 0 because the whole interval can be selected.
  map<long long, long long> memo = {{0, 1}};
  long long ps = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    ps += num;
    ans += memo[ps - x];
    // Updating the count should come before calculating
    // the answer. Otherwise, x = 0 scenarios will
    // produce an incorrect answer.
    memo[ps]++;
  }
  cout << ans << "\n";
  return 0;
}
