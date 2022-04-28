#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  // day, 1 for check in / 2 for check out, index
  vector<tuple<int, int, int>> events;
  for (int i = 0; i < n; i++) {
    int from, to;
    cin >> from >> to;
    events.push_back({from, 1, i});
    events.push_back({to, 2, i});
  }
  sort(events.begin(), events.end());
  queue<int> q;
  vector<int> rooms(n);
  int cnt = 1;
  for (auto [day, type, index]: events) {
    if (type == 1) {
      // check in
      if (q.empty()) {
        q.push(cnt);
        cnt++;
      }
      rooms[index] = q.front();
      q.pop();
    } else {
      // check out
      q.push(rooms[index]);
    }
  }
  cout << cnt - 1 << "\n";
  for (auto key: rooms) {
    cout << key << " ";
  }
  cout << "\n";
  return 0;
}
