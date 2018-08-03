#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int r;
        cin >> r;
        v[i] = r;
        sum += r;
    }
    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= sum; ++i) {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            dp[i][j] = dp[i-1][j];
            if (v[i-1] <= j)
                dp[i][j] |= dp[i-1][j-v[i-1]];
        }
    }
    int diff = INT_MAX;
    for (int j = sum/2; j >= 0; --j) {
        if (dp[n][j] == true) {
            diff = sum-2*j;
            break;
        }
    }
    cout << diff << endl;
}
