#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 1005;
const int maxlog = 11;


int n;
int parent[maxn];
vector<int> children[maxn];

int depth[maxn];
int P[maxn][maxlog];

void depthdfs(int u, int d) {
    depth[u] = d;
    for (int v : children[u]) {
        depthdfs(v, d+1);
    }
}

void preprocess() {
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < maxlog; ++j) {
            P[i][j] = -1;
        }
        P[i][0] = parent[i];
    }
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 0; i < n; ++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[P[i][j-1]][j-1];
            }
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
            a = P[a][j], b = P[b][j];
        }
    }
    return parent[a];
}

void Main() {
    int Cases;
    cin >> Cases;
    for (int Case = 1; Case <= Cases; ++Case) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            children[i].clear();
            int c;
            cin >> c;
            while (c--) {
                int x;
                cin >> x;
                --x;
                parent[x] = i;
                children[i].push_back(x);
            }
        }
        depthdfs(0, 0);
        preprocess();
        int q;
        cin >> q;
        cout << "Case " << Case << ":\n";
        while (q--) {
            int v, w;
            cin >> v >> w;
            --v, --w;
//            cout << "LCA(" << v+1 << ", " << w+1 << ") = ";
            cout << LCA(v, w) + 1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
