#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long x;
  cin >> n >> x;
  vector<pair<long long, int>> a(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    a[i] = {num, i};
  }
  sort(a.begin(), a.end());
  // Make sure that the min sum of 4 values is not greater than x.
  long long min_sum = 0;
  for (int i = 0; i < 4; i++) {
    min_sum += a[i].first;
  }
  if (min_sum > x) {
    cout << "IMPOSSIBLE" << "\n";
    return 0;
  }
  // Make sure that the max sum of 4 values is not less than x.
  long long max_sum = 0;
  for (int i = n - 4; i < n; i++) {
    max_sum += a[i].first;
  }
  if (max_sum < x) {
    cout << "IMPOSSIBLE" << "\n";
    return 0;
  }
  // For each number calculate the first position of the number
  // that comes right after it (skip duplicates).
  // HACK: add a stopper value so that if the last value of the array
  // is not unique the `nxt` value will be `n` (end of the array).
  a.push_back({0, -1});
  map<long long, int> nxt;
  for (int i = 0; i < n; i++) {
    if (a[i].first != a[i + 1].first) {
      nxt[a[i].first] = i + 1;
    }
  }
  // Remove the stopper value. Otherwise, lower bound will be computed
  // incorrectly.
  a.pop_back();
  bool found = false;
  for (int i = 0; !found and i < n - 3; i++) {
    if (i > 0 and a[i].first == a[i - 1].first) {
      i = nxt[a[i].first];
    }
    for (int j = i + 1; !found and j < n - 2; j++) {
      if (j > i + 1 and a[j].first == a[j - 1].first) {
        j = nxt[a[j].first];
      }
      for (int k = j + 1; !found and k < n - 1; k++) {
        if (k > j + 1 and a[k].first == a[k - 1].first) {
          k = nxt[a[k].first];
        }
        long long target = x - a[i].first - a[j].first - a[k].first;
        pair<long long, int> p = {target, INT_MIN};
        auto lower = lower_bound(a.begin() + k + 1, a.end(), p);
        if (lower != a.end() and (*lower).first == target) {
          int l = lower - a.begin();
          cout << a[i].second + 1 << " ";
          cout << a[j].second + 1 << " ";
          cout << a[k].second + 1 << " ";
          cout << a[l].second + 1 << "\n";
          found = true;
          break;
        }
      }
    }
  }
  if (!found) {
    cout << "IMPOSSIBLE" << "\n";
  }
  return 0;
}
