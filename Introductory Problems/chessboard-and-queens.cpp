#include <bits/stdc++.h>
using namespace std;

const char FREE = '.', RESERVED = '*', QUEEN = 'Q';
const int N = 8;
char b[N][N];

vector<int> rows(N), cols(N), mdiags(2 * N), sdiags(2 * N);
long long ans = 0;

void backtrack(int n) {
  if (n == 0) {
    ans++;
    return;
  }
  for (int r = 0; r < N; r++) {
    if (rows[r] == 1) {
      continue;
    }
    for (int c = 0; c < N; c++) {
      if (cols[c] == 1) {
        continue;
      }
      bool c1 = b[r][c] == FREE;
      // 45º diagonals
      bool c2 = mdiags[r + c] == 0;
      // 135º diagonals
      bool c3 = sdiags[r - c + N] == 0;
      if (c1 and c2 and c3) {
        b[r][c] = QUEEN;
        rows[r] = cols[c] = mdiags[r + c] = sdiags[r - c + N] = 1;
        backtrack(n - 1);
        b[r][c] = FREE;
        rows[r] = cols[c] = mdiags[r + c] = sdiags[r - c + N] = 0;
      }
    }
  }
}

int main() {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cin >> b[r][c];
    }
  }
  backtrack(N);
  // 8! = 40320
  cout << ans / 40320 << "\n";
  return 0;
}
