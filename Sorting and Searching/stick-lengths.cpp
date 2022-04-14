#include <bits/stdc++.h>
using namespace std;

long long cost(vector<long long>& p, long long len) {
  long long ans = 0;
  for (auto pi: p) {
    ans += abs(len - pi);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<long long> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  long long mid = p[p.size() / 2];
  long long ans = cost(p, mid);
  cout << ans << "\n";
  return 0;
}
