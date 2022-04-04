#include <bits/stdc++.h>
using namespace std;

void backtrack(int);
void mv(int, int, int);

vector<pair<int, int>> ans, cur;
vector<stack<int>> s(3);
int l = 0, m = 1, r = 2;

void backtrack(int n) {
  if (n == 0) {
    // all disks are in the right bucket
    if (s[l].size() + s[m].size() == 0) {
      ans = cur;
    }
    return;
  }
  mv(l, m, n);
  mv(m, l, n);
  mv(l, r, n);
  mv(r, l, n);
  mv(m, r, n);
  mv(r, m, n);
}

void mv(int from, int to, int n) {
  if (s[from].size() == 0) {
    return;
  }
  if (s[to].size() == 0 or s[to].top() > s[from].top()) {
    cur.push_back({from, to});
    s[to].push(s[from].top());
    s[from].pop();
    backtrack(n - 1);
    cur.pop_back();
    s[from].push(s[to].top());
    s[to].pop();
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = n; i > 0; i--) {
    s[l].push(i);
  }
  // min number of moves is 2^n - 1
  backtrack((1 << n) - 1);
  cout << ans.size() << "\n";
  for (auto [from, to]: ans) {
    cout << from + 1 << " " << to + 1 << "\n";
  }
  return 0;
}
