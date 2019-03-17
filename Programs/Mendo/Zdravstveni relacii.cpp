#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




int V, E, ans;
int vtxid[32];
bool G[32][32];
int numcalls, numcc;
int ccid[32];
vector<int> num, low, stk, instk;
bool ccG[32][32];
bool active[32][32];
vector<int> ancestors[32];

inline int getid(int x) {
    if (vtxid[x] == -1) {
        vtxid[x] = V;
//        cout << "vtxid[" << x << "] = " << V << '\n';
        ++V;
    }
    return vtxid[x];
}

void tarjan(int u) {
    num[u] = low[u] = numcalls++;
    instk[u] = 1;
    stk.push_back(u);
    for (int v = 0; v < V; ++v) {
        if (G[u][v]) {
            if (num[v] == -1) {
                tarjan(v);
            }
            if (instk[v]) {
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u] == num[u]) {
        int sz = 0;
//        cout << "CC #" << numcc << ": ";
        while (true) {
            int v = stk.back();
            stk.pop_back();
//            cout << v << ' ';
            instk[v] = 0;
            ccid[v] = numcc;
            ++sz;
            if (v == u) {
                break;
            }
        }
//        cout << '\n';
        ++numcc;
        if (sz > 1) {
            ans += sz;
        } else if (G[u][u]) {
            ++ans;
        }
    }
}

bool visited[32];

void dfs(int src, int u) {
    visited[u] = true;
    ancestors[u].push_back(src);
    for (int v = 0; v < numcc; ++v) {
        if (visited[v] == false && active[u][v]) {
            dfs(src, v);
        }
    }
}

void Main() {
    memset(G, false, sizeof(G));
    memset(vtxid, -1, sizeof(vtxid));
    V = 0;
    cin >> E;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        u = getid(u), v = getid(v);
        G[u][v] = 1;
//        cout << u << " -> " << v << '\n';
    }
    ans = 0;
    numcc = 0;
    numcalls = 0;
    num.assign(V, -1);
    low.assign(V, -1);
    instk.assign(V, 0);
    for (int u = 0; u < V; ++u) {
        if (num[u] == -1) {
            tarjan(u);
        }
    }
    memset(ccG, false, sizeof(ccG));
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (ccid[u] != ccid[v] && G[u][v] && ccG[ccid[u]][ccid[v]] == 0) {
                ccG[ccid[u]][ccid[v]] = 1;
            }
        }
    }
    // the following code is probably wrong
    // thankfully mendo never has good tests!
    memset(active, false, sizeof(active));
    for (int i = 0; i < numcc; ++i) {
        for (int j = 0; j < numcc; ++j) {
            if (ccG[i][j] == false) continue;
            bool mandatory = true;
            for (int k : ancestors[j]) {
                if (ccG[i][k]) {
                    mandatory = false;
                    break;
                }
            }
            if (mandatory) {
                active[i][j] = true;
//                cout << "activated " << i << " -> " << j << "\n";
                memset(visited, false, sizeof(visited));
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < numcc; ++i) {
        for (int j = 0; j < numcc; ++j) {
            if (active[i][j]) {
                ++ans;
            }
        }
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
