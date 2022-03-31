#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long sum = n * (n + 1) / 2;
  if (sum % 2 == 0) {
    cout << "YES" << "\n";
    vector<int> s1, s2;
    int l = 1, r = n;
    if (n % 2 == 1) {
      s2.push_back(r);
      r--;
    }
    int turn = 0;
    while (l < r) {
      if (turn % 2 == 0) {
        s1.push_back(l);
        s1.push_back(r);
      } else {
        s2.push_back(l);
        s2.push_back(r);
      }
      l++, r--;
      turn++;
    }
    cout << s1.size() << "\n";
    for (auto num: s1) {
      cout << num << " ";
    }
    cout << "\n";
    cout << s2.size() << "\n";
    for (auto num: s2) {
      cout << num << " ";
    }
    cout << "\n";
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}
