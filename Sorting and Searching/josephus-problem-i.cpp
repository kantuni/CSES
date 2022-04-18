#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  auto it = s.begin();
  int k = 1;
  while (s.size() > 0) {
    for (int i = 0; i < k; i++) {
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
