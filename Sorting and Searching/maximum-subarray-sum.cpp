#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long global = INT_MIN, local = 0;
  for (int i = 0; i < n; i++) {
    local = max(a[i], local + a[i]);
    global = max(global, local);
  }
  cout << global << "\n";
  return 0;
}
