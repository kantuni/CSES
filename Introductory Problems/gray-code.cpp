#include <bits/stdc++.h>
using namespace std;

map<string, int> color;

void dfs(string& s) {
  cout << s << endl;
  color[s] = 1;
  for (int i = 0; i < (int) s.size(); i++) {
    // flip the bit
    s[i] = (s[i] == '0') ? '1': '0';
    // check that we haven't been in that state before
    if (color.count(s) == 0) {
      dfs(s);
      return;
    }
    // if we have, restore the previous value
    s[i] = (s[i] == '0') ? '1' : '0';
  }
}

int main() {
  int n;
  cin >> n;
  string root = string(n, '0');
  dfs(root);
  return 0;
}
