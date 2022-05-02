#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  map<long long, long long> memo = {{0, 1}};
  long long ps = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    ps += num;
    long long rem = ps % n;
    if (rem < 0) {
      rem += n;
    }
    ans += memo[rem];
    memo[rem]++;
  }
  cout << ans << "\n"; 
  return 0;
}

