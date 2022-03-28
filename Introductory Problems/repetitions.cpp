#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int global = 0, local = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == s[i + 1]) {
      local++;
    } else {
      local = 0;
    }
    global = max(global, local);
  }
  cout << global + 1 << "\n";
  return 0;
}
