#include <bits/stdc++.h>
using namespace std;

// Returns the maximum number of products made in s seconds.
long long makes(vector<long long>& t, long long s) {
  long long ans = 0;
  for (auto ti: t) {
    ans += s / ti;
  }
  return ans;
}

int main() {
  long long n, p;
  cin >> n >> p;
  vector<long long> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  sort(t.begin(), t.end());
  long long low = 0, high = t.front() * p;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (makes(t, mid) < p) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << low << "\n";
  return 0;
}
