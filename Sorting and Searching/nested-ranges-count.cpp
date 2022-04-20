#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, 
                         tree_order_statistics_node_update>;

// increasing second, decreasing first
bool isdf(tuple<int, int, int> a, tuple<int, int, int> b) {
  auto [x1, y1, i] = a;
  auto [x2, y2, j] = b;
  if (y1 == y2) {
    return x1 > x2;
  }
  return y1 < y2;
}

void contains_range(vector<tuple<int, int, int>>& p) {
  vector<tuple<int, int, int>> ps(p);
  sort(ps.begin(), ps.end(), isdf);
  ordered_set<pair<int, int>> xs;
  vector<int> ans(p.size());
  int tmp = 0;
  for (auto [x, y, i]: ps) {
    int lower = xs.order_of_key({x, 0});
    ans[i] = xs.size() - lower;
    xs.insert({x, tmp});
    tmp++;
  }
  for (auto [x, y, i]: p) {  
    cout << ans[i] << " ";
  }
  cout << "\n";
}

// increasing first, decreasing second
bool ifds(tuple<int, int, int> a, tuple<int, int, int> b) {
  auto [x1, y1, i] = a;
  auto [x2, y2, j] = b;
  if (x1 == x2) {
    return y1 > y2;
  }
  return x1 < x2;
}

void inside_range(vector<tuple<int, int, int>>& p) {
  vector<tuple<int, int, int>> ps(p);
  sort(ps.begin(), ps.end(), ifds);
  ordered_set<pair<int, int>> ys;
  vector<int> ans(p.size());
  int tmp = 0;
  for (auto [x, y, i]: ps) {
    int lower = ys.order_of_key({y, 0});
    ans[i] = ys.size() - lower;
    ys.insert({y, tmp});
    tmp++;
  }
  for (auto [x, y, i]: p) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  int n;
  cin >> n;
  vector<tuple<int, int, int>> p(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y, i};
  }
  contains_range(p);
  inside_range(p);
  return 0;
}
