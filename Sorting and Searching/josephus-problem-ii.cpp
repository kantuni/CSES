#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

int main() {
  int n, k;
  cin >> n >> k;
  rope<int> r;
  for (int i = 1; i <= n; i++) {
    r.push_back(i);
  }
  int pos = 0;
  while (r.size() > 0) {
    pos = (pos + k) % r.size();
    cout << r.at(pos) << " ";
    r.erase(pos, 1);
  }
  cout << "\n";
  return 0;
}
