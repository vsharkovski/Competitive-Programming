#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int n;
vector<vector<int>> adj;

vector<int> num, low, instk, stk;
int calls;

void tarjan(int u) {
    num[u] = low[u] = calls++;
    instk[u] = 1;
    stk.push_back(u);
    for (int v : adj[u]) {
        if (num[v] == -1) {
            tarjan(v);
        }
        if (instk[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        cout << "SCC: ";
        while (true) {
            int v = stk.back();
            stk.pop_back();
            instk[v] = 0;
            // v is in SCC
            cout << v << " ";
            if (v == u) break;
        }
        cout << "\n";
    }
}

void Main() {
    cin >> n;
    adj.assign(n+1, vector<int>());
    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    num.assign(n+1, -1);
    low.resize(n);
    instk.assign(n+1, 0);
    calls = 0;
    for (int i = 1; i <= n; ++i) {
        if (num[i] == -1) {
            tarjan(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
