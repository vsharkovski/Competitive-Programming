#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



void Main() {
    int n;
    cin >> n;
    ll cnt[100005] = {};
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    ll dp[100005] = {};
    for (ll i = 100000; i >= 0; --i) {
        dp[i] = max(dp[i+1], cnt[i]*i + dp[i+2]);
    }
    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    Main();
}
