#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> indexed_set;

int main() {
  int n, k;
  cin >> n >> k;
  indexed_set s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  auto it = s.begin();
  int offset = 0;
  while (s.size() > 0) {
    offset = (offset + k) % s.size();
    it = s.find_by_order(offset);
    cout << *it << " ";
    auto tmp = it;
    if (next(it) == s.end()) {
      it = s.begin();
      offset = 0;
    } else {
      it++;
      offset++;
    }
    offset = (offset - 1 + s.size()) % s.size();
    s.erase(tmp);
  }
  cout << "\n";
  return 0;
}
