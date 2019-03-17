#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




const int maxn = 50005, maxk = 155;
const ll unset = -1e16;

int N, K;
vector<int> G[maxn];
int sbsize[maxn];
ll value[maxn], sbsum[maxn];
vector<int> toposort;
ll dp[maxn][maxk];

void dfs(int node, int parent) {
    sbsize[node] = 1;
    sbsum[node] = value[node];
    for (int child : G[node]) {
        if (child != parent) {
            dfs(child, node);
            sbsize[node] += sbsize[child];
            sbsum[node] += sbsum[child];
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
//        cout << "value[" << i << "] = " << value[i] << "\n";
    }
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
//        cout << "edge " << a << " - " << b << "\n";
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    reverse(toposort.begin(), toposort.end());
//    cout<<"toposort: ";for(int x:toposort){cout<<x<<' ';}cout<<"\n";
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k <= K; ++k) {
            dp[i][k] = unset;
        }
    }
    dp[0][K] = 0;
    for (int i = 0; i < N; ++i) {
        int node = toposort[i];
        for (int k = 0; k <= K; ++k) {
            if (dp[i][k] == unset) continue;
            max_self(dp[i + 1][k], dp[i][k] + value[node]);
            if (k >= 1) {
                max_self(dp[i + sbsize[node]][k - 1], dp[i][k]);
            }
        }
    }
//    for (int i = 0; i <= N; ++i) {
//        for (int k = 0; k <= K; ++k) {
//            cout << "dp[" << i << "][" << k << "] = " << dp[i][k]  << '\n';
//        }
//    }
    ll ans = unset;
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
