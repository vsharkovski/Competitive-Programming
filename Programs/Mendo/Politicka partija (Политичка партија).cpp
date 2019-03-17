#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



const int maxn = 50005, maxk = 155;
const ll inf = 1e16;

int N, K;
vector<int> G[maxn];
ll value[maxn];
int sbsize[maxn];
vector<int> toposort;
ll dp[maxn][maxk];

void dfs(int node, int parent) {
    sbsize[node] = 1;
    for (int child : G[node]) {
        if (child != parent) {
            dfs(child, node);
            sbsize[node] += sbsize[child];
        }
    }
    toposort.push_back(node);
}

inline void max_self(ll& x, ll y) {
    x = max(x, y);
}

void Main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> value[i];
    }
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    reverse(toposort.begin(), toposort.end());
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k <= K; ++k) {
            dp[i][k] = -inf;
        }
    }
    dp[0][K] = 0;
    for (int i = 0; i < N; ++i) {
        int node = toposort[i];
        for (int k = 0; k <= K; ++k) {
            if (dp[i][k] == -inf) { // this state is unreachable
                continue;
            }
            max_self(dp[i + 1][k], dp[i][k] + value[node]);
            if (k >= 1) {
                max_self(dp[i + sbsize[node]][k - 1], dp[i][k]);
            }
        }
    }
    ll ans = -inf; // -1e18
    for (int k = 0; k <= K; ++k) {
        ans = max(ans, dp[N][k]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
