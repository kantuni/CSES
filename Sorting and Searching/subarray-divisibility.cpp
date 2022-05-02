#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  map<long long, long long> memo = {{0, 1}};
  long long ps = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    ps += num;
    long long mn = memo.begin()->first;
    long long mnn = (mn / n) * n;
    // The current prefix sum might be the largest,
    // but we haven't pushed it into the map yet.
    long long mx = max(ps, prev(memo.end())->first);
    long long mxn = (mx / n) * n;
    for (long long k = mnn; k <= mxn; k += n) {
      ans += memo[ps - k];
    }
    memo[ps]++;
  }
  cout << ans << "\n";
  return 0;
}
