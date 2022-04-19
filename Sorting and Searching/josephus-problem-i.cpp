#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  list<int> nums;
  for (int i = 1; i <= n; i++) {
    nums.push_back(i);
  }
  auto it = nums.begin();
  while (nums.size() > 0) {
    if (next(it) == nums.end()) {
      it = nums.begin();
    } else {
      it++;
    }
    cout << *it << " ";
    auto tmp = it;
    if (next(it) == nums.end()) {
      it = nums.begin();
    } else {
      it++;
    }
    nums.erase(tmp);
  }
  cout << "\n";
  return 0;
}
