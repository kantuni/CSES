#include <bits/stdc++.h>
using namespace std;

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
  set<int> xs;
  vector<int> ans(p.size());
  for (auto [x, y, i]: ps) {
    auto lower = xs.lower_bound(x);
    ans[i] = lower != xs.end();
    xs.insert(x);
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
  set<int> ys;
  vector<int> ans(p.size());
  for (auto [x, y, i]: ps) {
    auto lower = ys.lower_bound(y);
    ans[i] = lower != ys.end();
    ys.insert(y);
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
