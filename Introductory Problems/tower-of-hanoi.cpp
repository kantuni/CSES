#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ans;

void solve(int n, int from, int aux, int to) {
  if (n == 1) {
    ans.push_back({from, to});
    return;
  }
  solve(n - 1, from, to, aux);
  solve(1, from, aux, to);
  solve(n - 1, aux, from, to);
}

int main() {
  int n;
  cin >> n;
  solve(n, 1, 2, 3);
  cout << ans.size() << endl;
  for (auto [from, to]: ans) {
    cout << from << " " << to << "\n";
  }
  return 0;
}

