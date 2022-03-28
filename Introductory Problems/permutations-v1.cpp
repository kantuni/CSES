#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 2 or n == 3) {
    cout << "NO SOLUTION" << "\n";
    return 0;
  }
  int turn = 0;
  int l = 1, r = n / 2 + 1;
  while (l <= n / 2 or r <= n) {
    if (turn % 2 == 0) {
      cout << r << " "; 
      r++;
    } else {
      cout << l << " ";
      l++;
    }
    turn++;
  }
  cout << "\n";
  return 0;
}
