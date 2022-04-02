#include <bits/stdc++.h>
using namespace std;

map<char, int> memo;
vector<string> ans;
string cur;

void backtrack(int n) {
  if (n == 0) {
    ans.push_back(cur);
    return;
  }
  for (auto [c, cnt]: memo) {
    if (cnt > 0) {
      cur.push_back(c);
      memo[c]--;
      backtrack(n - 1);
      cur.pop_back();
      memo[c]++;
    }
  }
}

int main() {
  string s;
  cin >> s;
  for (auto c: s) {
    memo[c]++;
  }
  int n = s.size();
  backtrack(n);
  cout << ans.size() << endl;
  for (auto ns: ans) {
    cout << ns << endl;
  }
  return 0;
}
