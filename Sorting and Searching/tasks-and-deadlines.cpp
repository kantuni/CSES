#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<long long, long long>> tasks;
  for (int i = 0; i < n; i++) {
    long long d, e;
    cin >> d >> e;
    tasks.push_back({d, e});
  }
  sort(tasks.begin(), tasks.end());
  long long ans = 0, t = 0;
  for (auto [d, e]: tasks) {
    t += d;
    ans += (e - t);
  }
  cout << ans << "\n";
  return 0;
}
