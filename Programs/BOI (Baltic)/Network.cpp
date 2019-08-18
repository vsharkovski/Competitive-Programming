#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long ll;
typedef pair<int, int> pii;


const int maxn = 500050;

int n;
vector<int> adj[maxn];
vector<int> leaves;
vector<pii> edges;

void dfs(int u, int p) {
    if (adj[u].size() == 1 && adj[u][0] == p) {
        leaves.push_back(u);
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int src = 1; src <= n; ++src) {
        if (adj[src].size() > 1) {
            dfs(src, -1);
            break;
        }
    }
    int k = leaves.size();
    for (int i = 0; i < k/2 + !!(k%2); ++i) {
        edges.emplace_back(leaves[i], leaves[(i + k/2) % k]);
    }
    cout << edges.size() << '\n';
    for (auto &p : edges) {
        cout << p.first << ' ' << p.second << '\n';
    }
}
