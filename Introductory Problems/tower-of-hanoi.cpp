#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;
vector<stack<int>> s(3);

void mv(int from, int to) {
  if (s[from].size() == 0) {
    return;
  }
  if (s[to].size() == 0 or s[to].top() > s[from].top()) {
    ans.push_back({from, to});
    s[to].push(s[from].top());
    s[from].pop();
  }
}

void solve(int n, int from, int aux, int to) {
  if (n == 1) {
    mv(from, to);
    return;
  }
  solve(n - 1, from, to, aux);
  mv(from, to);
  solve(n - 1, aux, from, to);
}

int main() {
  int n;
  cin >> n;
  for (int i = n; i > 0; i--) {
    s[0].push(i);
  }
  solve(n, 0, 1, 2);
  cout << ans.size() << "\n";
  for (auto [from, to]: ans) {
    cout << from + 1 << " " << to + 1 << "\n";
  }
  return 0;
}

