#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, int> memo;
  for (auto c: s) {
    memo[c]++;
  }
  if (s.size() % 2 == 0) {
    // all letter counts must be even
    bool ok = true;
    for (auto [c, cnt]: memo) {
      if (cnt % 2 == 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      string s1, s2;
      for (auto [c, cnt]: memo) {
        for (int i = 0; i < cnt / 2; i++) {
          s1.push_back(c);
          s2.push_back(c);
        }
      }
      // s1 + reverse(s2) = palindrome
      reverse(s2.begin(), s2.end());
      cout << s1 + s2 << "\n";
    } else {
      cout << "NO SOLUTION" << "\n";
    }
  } else {
    // all letter counts except one must be even
    bool ok = false;
    char mid;
    for (auto [c, cnt]: memo) {
      if (cnt % 2 == 1) {
        if (!ok) {
          ok = true;
          mid = c;
        } else {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      string s1, s2;
      for (auto [c, cnt]: memo) {
        for (int i = 0; i < cnt / 2; i++) {
          s1.push_back(c);
          s2.push_back(c);
        }
      }
      // s1 + mid + reverse(s2) = palindrome
      reverse(s2.begin(), s2.end());
      cout << s1 + mid + s2 << "\n";
    } else {
      cout << "NO SOLUTION" << "\n";
    }
  }
  return 0;
}
