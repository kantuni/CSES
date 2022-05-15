#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, 
                         tree_order_statistics_node_update>;

int main() {
  int n, k;
  cin >> n >> k;
  // HACK: Allocate more space to avoid going out of bounds.
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ordered_set<pair<int, int>> s;
  for (int i = 0; i < k; i++) {
    s.insert({a[i], i});
  }
  int i = 0, j = k;
  while (j <= n) {
    int mid = k / 2 - (k % 2 == 0);
    auto it = s.find_by_order(mid);
    auto [median, _] = *it;
    cout << median << " ";
    s.erase({a[i], i});
    s.insert({a[j], j});
    i++, j++;
  }
  cout << "\n";
  return 0;
}
