#include <bits/stdc++.h>
using namespace std;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  min_heap<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    pq.push({a[i], i});
    if (pq.empty() or pq.top().first >= a[i]) {
      cout << 0 << " ";
      continue;
    }
    vector<pair<int, int>> tmp;
    while (!pq.empty()) {
      auto [num, index] = pq.top();
      if (num >= a[i]) {
        break;
      }
      pq.pop();
      tmp.push_back({num, index});
    }
    int pos = -1;
    for (auto [num, index]: tmp) {
      pos = max(pos, index);
      pq.push({num, index});
    }
    cout << pos + 1 << " ";
  }
  cout << "\n";
  return 0;
}
