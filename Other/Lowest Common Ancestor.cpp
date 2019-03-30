#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1000;
const int MAXLOG = 30;

int N;
int parent[MAXN];
vector<int> children[MAXN];

int depth[MAXN];
int P[MAXN][MAXLOG]; // P[i][j] = 2^j -th ancestor of node i

void depthDFS(int u, int d) {
    depth[u] = d;
    for (int v : children[u])
        depthDFS(v, d+1);
}

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
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    for (int j = MAXLOG-1; j >= 0; --j) {
        if (depth[a] - (1 << j) >= depth[b]) {
            a = P[a][j];
        }
    }
    if (a == b) {
        return a;
    }
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
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        children[a].push_back(b);
        parent[b] = a;
    }
    depthDFS(0, 0);
    makeSparseTable();
    for (int a = 1; a <= N; ++a) {
        for (int b = a+1; b <= N; ++b) {
            cout << "LCA(" << a << ", " << b << ") = " << LCA(a-1, b-1)+1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
