#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



const int maxn = 100005;
const int maxlog = 20;

int n, queries, idx;
int label[maxn];
int depth[maxn];
int sbsize[maxn];
int P[maxn][maxlog];
vector<int> children[maxn];
vector<int> atdepth[maxn];

void dfs(int u, int d) {
    label[u] = idx++;
    depth[u] = d;
    atdepth[d].push_back(u);
    sbsize[u] = 1;
    for (int v : children[u]) {
        dfs(v, d+1);
        sbsize[u] += sbsize[v];
    }
}

int ancestor(int a, int k) {
    int b = a;
    for (int j = maxlog-1; j >= 0; --j) {
        if (depth[b] + k - (1 << j) >= depth[a]) {
            b = P[b][j];
        }
    }
    return b;
}

void Main() {
    cin >> n;
    vector<int> roots;
    for (int i = 0; i < n; ++i) {
        int r;
        cin >> r;
        --r;
        if (r != -1) {
            P[i][0] = r;
            children[r].push_back(i);
        } else {
            roots.push_back(i);
        }
    }
    idx = 0;
    for (int root : roots) {
        dfs(root, 0);
    }
    for (int j = 1; j < maxlog; ++j) {
        for (int i = 0; i < n; ++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[ P[i][j-1] ][j-1];
            }
        }
    }
    cin >> queries;
    while (queries--) {
        int v, p;
        cin >> v >> p;
        --v;
        int d = depth[v];
        if (d - p < 0) {
            cout << 0 << ' ';
        } else {
            int u = ancestor(v, p);
            int i = n, j = 0, l = 0, r = atdepth[d].size()-1, m;
            while (l <= r) {
                m = (l + r) / 2;
                if (label[atdepth[d][m]] < label[u]) {
                    l = m+1;
                } else {
                    r = m-1;
                    i = m;
                }
            }
            l = i, r = atdepth[d].size()-1;
            while (l <= r) {
                m = (l + r) / 2;
                if (label[atdepth[d][m]] > label[u] + sbsize[u] - 1) {
                    r = m-1;
                } else {
                    l = m+1;
                    j = m;
                }
            }
            cout << max(0, j - i) << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    Main();
}
