#include <bits/stdc++.h>
using namespace std;

const char FREE = '.', RESERVED = '*', QUEEN = 'Q';
const int N = 8;
char b[N][N];

map<int, int> cols, mdiags, sdiags;
long long ans = 0;

void backtrack(int n, int r) {
  if (n == 0) {
    ans++;
    return;
  }
  for (int c = 0; c < N; c++) {
    if (cols[c] == 1) {
      continue;
    }
    bool c1 = b[r][c] == FREE;
    // 45º diagonals
    bool c2 = mdiags[r + c] == 0;
    // 135º diagonals
    bool c3 = sdiags[r - c] == 0;
    if (c1 and c2 and c3) {
      b[r][c] = QUEEN;
      cols[c] = mdiags[r + c] = sdiags[r - c] = 1;
      backtrack(n - 1, r + 1);
      b[r][c] = FREE;
      cols[c] = mdiags[r + c] = sdiags[r - c] = 0;
    }
  }
}

int main() {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cin >> b[r][c];
    }
  }
  backtrack(N, 0);
  cout << ans << "\n";
  return 0;
}
