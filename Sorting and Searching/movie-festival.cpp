#include <bits/stdc++.h>
using namespace std;

// Earliest to finish first.
bool cmp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second == p2.second) {
    return p1.first < p2.first;
  }
  return p1.second < p2.second;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> movies;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    movies.push_back({a, b});
  }
  sort(movies.begin(), movies.end(), cmp);
  int ans = 0, end = 0;
  for (auto [from, to]: movies) {
    if (from >= end) {
      end = to;
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
