#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans(n, -1);
  for (int i = 1; i < n; i++) {
    if (a[i - 1] < a[i]) {
      ans[i] = i - 1;
    } else {
      int j = i - 1;
      while (ans[j] != -1 and a[ans[j]] >= a[i]) {
        j = ans[j];
      }
      ans[i] = ans[j];
    }
  }
  for (auto index: ans) {
    cout << index + 1 << " ";
  }
  cout << "\n";
  return 0;
}
