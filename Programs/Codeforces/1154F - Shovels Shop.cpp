#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    n = k;
    vector<int> besty(n+1, 0); // besty[x] means best offer if buying x shovels
    besty[1] = 0;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x <= n) {
            besty[x] = max(besty[x], y);
        }
    }
    vector<int> prefsum(n);
    for (int i = 0; i < n; ++i) {
        prefsum[i] = a[i];
        if (i > 0) prefsum[i] += prefsum[i-1];
    }
    int ans = 0;
    vector<int> dp(n+1, 1e9);
    // dp[i] = min cost for buying items 0, 1, 2, ..., i-1
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int x = 1; x <= n-i; ++x) {
            // buying x items: i, i+1, ..., i+x-1
            // free are: i, i+1, ..., i+y-1 (first y)
            // others need to be paid
            int y = besty[x];
            int paying = prefsum[i+x-1];
            if (i+y-1 >= 0) paying -= prefsum[i+y-1];
            dp[i+x] = min(dp[i+x], dp[i] + paying);
        }
    }
    cout << dp[n] << '\n';
}
