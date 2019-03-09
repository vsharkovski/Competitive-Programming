#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;





int N;
ll a[405];
ll prefsum[405];
ll dp[405][405]; // dp[L][R] = {minimum cost for segment [L, R]

ll dfs(int L, int R) {
    ll& res = dp[L][R];
    if (res == -1) {
        if (L >= R) {
            res = 0;
        } else if (L+1 == R) {
            res = a[L] + a[L+1];
        } else {
            res = 1e18;
            for (int i = L; i+1 <= R; ++i) {
                ll leftcost = dfs(L, i);
                ll leftsize = prefsum[i] - prefsum[L-1];
                ll rightcost = dfs(i+1, R);
                ll rightsize = prefsum[R] - prefsum[i];
                ll totalcost = leftcost + rightcost + (leftsize + rightsize);
                res = min(res, totalcost);
            }
        }
    }
    return res;
}

void Main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    prefsum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        prefsum[i] = prefsum[i-1] + a[i];
    }
    memset(dp, -1, sizeof(dp));
    ll ans = dfs(1, N);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
