#include <bits/stdc++.h>
using namespace std;

template <typename T>
using max_heap = priority_queue<T, vector<T>, greater<T>>;

int main() {
  int n;
  cin >> n;
  // left, right, index
  vector<tuple<int, int, int>> events;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    events.push_back({l, r, i});
  }
  sort(events.begin(), events.end());
  // right, key
  max_heap<pair<int, int>> pq;
  pq.push({0, 1});
  vector<int> ans(n);
  int nxt = 2;
  for (auto [l, r, i]: events) {
    auto [mxr, k] = pq.top();
    int key = -1;
    if (l > mxr) {
      key = k;
      pq.pop();
    } else {
      key = nxt;
      nxt++;
    }
    ans[i] = key;
    pq.push({r, key});
  }
  cout << nxt - 1 << "\n";
  for (auto key: ans) {
    cout << key << " ";
  }
  cout << "\n";
  return 0;
}
