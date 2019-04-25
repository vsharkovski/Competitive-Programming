#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int MAXN = 300005;
const int MAXK = 5;

int N, M, K;
int color[MAXN];
vector<int> adj[MAXN];
ll dp[1<<MAXK][MAXN];

ll dfs(int msk, int nd, int len) {
    ll& res = dp[msk][nd];
    if (res != -1) return res;
    res = 0;
    if (len > 1) ++res;
    for (int nxt : adj[nd]) {
        if ((msk & color[nxt]) == 0) {
            res += dfs(msk | color[nxt], nxt, len + 1);
        }
    }
    return res;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        color[i] = 1 << (c-1);
//        cout << "color[" << i+1 << "] = " << color[i] << endl;
    }
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += dfs(color[i], i, 1);
//        cout << "i=" << i+1 << " dp=" << dp[color[i]][i] << '\n';
    }
    cout << ans << '\n';
}
