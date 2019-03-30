#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



const int MAXN = 300010;
const int MAXLOG = 30;

int N;
int realid[MAXN];
int answer[MAXN]; // answer for each query

int parent[MAXN];
int depth[MAXN];
int P[MAXN][MAXLOG];

void makeSparseTable() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < MAXLOG; ++j) {
            P[i][j] = -1;
        }
    }
    for (int i = 0; i < N; ++i) {
        P[i][0] = parent[i];
    }
    for (int j = 1; j < MAXLOG; ++j) {
        for (int i = 0; i < N; ++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[ P[i][j-1] ][j-1];
            }
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    for (int j = MAXLOG-1; j >= 0; --j) {
        if (depth[a] - (1 << j) >= depth[b]) {
            a = P[a][j];
        }
    }
    if (a == b) return a;
    for (int j = MAXLOG-1; j >= 0; --j) {
        if (P[a][j] != -1 && P[a][j] != P[b][j]) {
            a = P[a][j];
            b = P[b][j];
        }
    }
    return parent[a];
}

void Main() {
    cin >> N;
    ++N;
    memset(parent, -1, sizeof(parent));
    vector<pair<int, pair<int, int>>> lca_queries;
    parent[0] = 0;
    depth[0] = 0;
    for (int i = 1; i < N; ++i) {
        char ch;
        cin >> ch;
        if (ch == 'a') {
            int v;
            cin >> v;
            v = realid[v];
            realid[i] = i;
            parent[i] = v;
            depth[i] = depth[parent[i]] + 1;
            answer[i] = -1; // nothing to print
        } else if (ch == 'b') {
            int v;
            cin >> v;
            v = realid[v];
            realid[i] = parent[v];
            answer[i] = v;
        } else {
            int v, t;
            cin >> v >> t;
            v = realid[v];
            t = realid[t];
            realid[i] = v;
            lca_queries.emplace_back(i, pair<int, int>(v, t));
        }
    }
    makeSparseTable();
    for (auto& q : lca_queries) {
        int i = q.first;
        int u = q.second.first, v = q.second.second;
        int lca = LCA(u, v);
        answer[i] = depth[lca];
    }
    for (int i = 1; i < N; ++i) {
        if (answer[i] != -1) {
            cout << answer[i] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
