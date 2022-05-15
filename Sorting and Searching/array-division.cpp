#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> a;

bool works(long long limit) {
  vector<long long> p;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > limit) {
      return false;
    }
    if (sum + a[i] <= limit) {
      sum += a[i];
    } else {
      p.push_back(sum);
      sum = a[i];
    }
  }
  if (sum > limit) {
    return false;
  }
  if (sum > 0) {
    p.push_back(sum);
  }
  // NOTE: The crucial part is <= (not ==), because if we can make k parts
  // with max sum == limit, we can definitely make k - 1 parts.
  return p.size() <= k;
}

int main() {
  cin >> n >> k;
  a.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long low = 1;
  // NOTE: 0LL instead of 0.
  // Otherwise, you'll accumulate everything into an int.
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
