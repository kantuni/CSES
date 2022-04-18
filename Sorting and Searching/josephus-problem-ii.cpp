#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  auto it = s.begin();
  while (s.size() > 0) {
    for (int i = 0; i < (int) k % s.size(); i++) {
      if (next(it) == s.end()) {
        it = s.begin();
      } else {
        it++;
      }
    }
    cout << *it << " ";
    auto rmit = it;
    if (next(it) == s.end()) {
      it = s.begin();
    } else {
      it++;
    }
    s.erase(rmit);
  }
  cout << "\n";
  return 0;
}
