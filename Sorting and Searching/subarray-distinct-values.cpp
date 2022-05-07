#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = (n + n - k + 1) * k / 2;
    map<int, int> memo;
    for (int i = 0; i < k; i++) {
        memo[a[i]]++;
    }
    // Iterate over all subarrays with lengths k + 1 ... n
    for (int len = k + 1; len <= n; len++) {
        bool stop = true;
        map<int, int> cnt = memo;
        cnt[a[len - 1]]++;
        if (cnt.size() <= k) {
            ans++;
        }
        int i = 0, j = len - 1;
        while (j + 1 < n) {
            // remove first element
            cnt[a[i]]--;
            if (cnt[a[i]] == 0) {
                cnt.erase(a[i]);
            }
            i++;
            // add next element
            j++;
            cnt[a[j]]++;
            if (cnt.size() <= k) {
                ans++;
                stop = false;
            }
        }
        memo[a[len - 1]]++;
        // If a subarray with length len didn't have <= k distinct values,
        // there is no point at looking at a subarray with length len + 1.
        if (stop) {
          break;
        }
    }
    cout << ans << "\n";
    return 0;
}
