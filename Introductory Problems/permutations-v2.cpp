#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 2 or n == 3) {
    cout << "NO SOLUTION" << "\n";
    return 0;
  }
  for (int i = 1; i < n; i += 2) {
    cout << i + 1 << " ";
  }
  for (int i = 0; i < n; i += 2) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  return 0;
}
