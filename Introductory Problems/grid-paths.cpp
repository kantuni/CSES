#include <bits/stdc++.h>
using namespace std;

const int N = 7;
const int SR = 0, SC = 0, TR = N - 1, TC = 0;
string s;
int color[N][N];
int ans = 0;

void backtrack(int r, int c, int i) {
  // Reached the end of the command
  if (i == N * N - 1) {
    // The path ended on the target location
    if (r == TR and c == TC) {
      ans++;
    }
    return;
  }
  // The target location has been occupied ahead of time
  if (color[TR][TC] == 1) {
    return;
  }
  bool canGoUp = r - 1 >= 0 and color[r - 1][c] == 0;
  bool canGoDown = r + 1 < N and color[r + 1][c] == 0;
  bool canGoLeft = c - 1 >= 0 and color[r][c - 1] == 0;
  bool canGoRight = c + 1 < N and color[r][c + 1] == 0;
  // If at any moment we can only go left or right,
  // the path splits, i.e. we can't reach all the cells, and thus
  // that path is invalid.
  if (!canGoUp and !canGoDown and canGoLeft and canGoRight) {
    return;
  }
  if (canGoUp and canGoDown and !canGoLeft and !canGoRight) {
    return;
  }
  if (s[i] == 'U') {
    // Must go up
    if (r - 1 < 0 or color[r - 1][c] == 1) {
      return;
    }
    color[r - 1][c] = 1;
    backtrack(r - 1, c, i + 1);
    color[r - 1][c] = 0;
  } else if (s[i] == 'D') {
    // Must go down
    if (r + 1 == N or color[r + 1][c] == 1) {
      return;
    }
    color[r + 1][c] = 1;
    backtrack(r + 1, c, i + 1);
    color[r + 1][c] = 0;
  } else if (s[i] == 'L') {
    // Must go left
    if (c - 1 < 0 or color[r][c - 1] == 1) {
      return;
    }
    color[r][c - 1] = 1;
    backtrack(r, c - 1, i + 1);
    color[r][c - 1] = 0;
  } else if (s[i] == 'R') {
    // Must go right
    if (c + 1 == N or color[r][c + 1] == 1) {
      return;
    }
    color[r][c + 1] = 1;
    backtrack(r, c + 1, i + 1);
    color[r][c + 1] = 0;
  } else {
    if (canGoUp) {
      color[r - 1][c] = 1;
      backtrack(r - 1, c, i + 1);
      color[r - 1][c] = 0;
    }
    if (canGoDown) {
      color[r + 1][c] = 1;
      backtrack(r + 1, c, i + 1);
      color[r + 1][c] = 0;
    }
    if (canGoLeft) {
      color[r][c - 1] = 1;
      backtrack(r, c - 1, i + 1);
      color[r][c - 1] = 0;
    }
    if (canGoRight) {
      color[r][c + 1] = 1;
      backtrack(r, c + 1, i + 1);
      color[r][c + 1] = 0;
    }
  }
}

int main() {
  cin >> s;
  memset(color, 0, sizeof color);
  color[0][0] = 1;
  backtrack(SR, SC, 0);
  cout << ans << "\n";
  return 0;
}
