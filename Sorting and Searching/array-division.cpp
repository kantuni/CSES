#include <bits/stdc++.h>
using namespace std;
 
int n, k;
vector<long long> a;
 
bool works(long long limit) {
  int cnt = 1;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (sum + a[i] > limit) {
      cnt++;
      sum = 0;
    }
    sum += a[i];
  }
  // NOTE: The crucial part is <= (not ==), because if we can make k - 1 parts
  // with max sum == limit, we can definitely make k parts.
  return cnt <= k;
}
 
int main() {
  cin >> n >> k;
  a.assign(n, 0);
  long long mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  long long low = mx;
  // IMPORTANT: 0LL instead of 0.
  // Otherwise, it'll accumulate everything into an int.
  long long high = accumulate(a.begin(), a.end(), 0LL);
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    if (works(mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << low << "\n";
  return 0;
}
