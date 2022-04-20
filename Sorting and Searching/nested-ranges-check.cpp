#include <bits/stdc++.h>
using namespace std;

// increasing second, decreasing first
bool isdf(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first > b.first;
  }
  return a.second < b.second;
}

void contains_range(vector<pair<int, int>> p) {
  vector<pair<int, int>> ps(p);
  sort(ps.begin(), ps.end(), isdf);
  map<pair<int, int>, int> memo;
  set<int> xs;
  for (auto [x, y]: ps) {
    auto lower = xs.lower_bound(x);
    memo[make_pair(x, y)] = lower != xs.end();
    xs.insert(x);
  }
  for (int i = 0; i < (int) p.size(); i++) {
    cout << memo[p[i]] << " ";
  }
  cout << "\n";
}

// increasing first, decreasing second
bool ifds(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

void inside_range(vector<pair<int, int>> p) {
  vector<pair<int, int>> ps(p);
  sort(ps.begin(), ps.end(), ifds);
  map<pair<int, int>, int> memo;
  set<int> ys;
  for (auto [x, y]: ps) {
    auto lower = ys.lower_bound(y);
    memo[make_pair(x, y)] = lower != ys.end();
    ys.insert(y);
  }
  for (int i = 0; i < (int) p.size(); i++) {
    cout << memo[p[i]] << " ";
  }
  cout << "\n";
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p.push_back({x, y});
  }
  contains_range(p);
  inside_range(p);
  return 0;
}
