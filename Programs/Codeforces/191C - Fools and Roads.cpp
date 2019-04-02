#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




const int maxn = 100005;
const int maxlog = 18;

int n;
pair<int, int> edges[maxn];
vector<int> G[maxn];
vector<int> atdepth[maxn];
ll ans[maxn];
ll cnt[maxn];

int maxdepth;
int depth[maxn];
int P[maxn][maxlog];

void dfs1(int u, int p, int d) {
    maxdepth = max(maxdepth, d);
    depth[u] = d;
    atdepth[d].push_back(u);
    for (int i : G[u]) {
        int v = edges[i].first == u ? edges[i].second : edges[i].first;
        if (v != p) {
            P[v][0] = u;
            dfs1(v, u, d+1);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int j = maxlog-1; j >= 0; --j) {
        if (depth[a] - (1 << j) >= depth[b]) {
            a = P[a][j];
        }
    }
    if (a == b) return a;
    for (int j = maxlog-1; j >= 0; --j) {
        if (P[a][j] != -1 && P[a][j] != P[b][j]) {
            a = P[a][j];
            b = P[b][j];
        }
    }
    return P[a][0];
}

void Main() {
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[i] = {u, v};
        G[u].push_back(i);
        G[v].push_back(i);
    }
    maxdepth = 0;
    dfs1(0, -1, 0);
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 0; i < maxn; ++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[ P[i][j-1] ][j-1];
            }
        }
    }
    memset(cnt, 0, sizeof(cnt));
    int k;
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        int c = LCA(a, b);
        cnt[a] += 1;
        cnt[b] += 1;
        cnt[c] -= 2;
    }
    memset(ans, 0, sizeof(ans));
    for (int d = maxdepth; d > 0; --d) {
        for (int u : atdepth[d]) {
            int pe, p;
            for (int i : G[u]) {
                int v = edges[i].first == u ? edges[i].second : edges[i].first;
                if (v == P[u][0]) {
                    p = v;
                    pe = i;
                    break;
                }
            }
            ans[pe] = cnt[u];
            cnt[p] += cnt[u];
        }
    }
    for (int i = 0; i < n-1; ++i) {
        cout << ans[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    #ifndef _DEBUG
    #endif
    Main();
}
