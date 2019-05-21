#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int maxn = 2e5 + 5;

int n, k;
int L[maxn], R[maxn];
vector<int> adj[maxn]; // index of edge

int degree[maxn];
int cnt_degree[maxn];

int colors;
int color[maxn];

inline int other(int i, int u) {
    return L[i] == u ? R[i] : L[i];
}

void dfs(int u, int p, int prev_color) {
    int curr_color = 0;
    for (int i : adj[u]) {
        int v = other(i, u);
        if (v != p) {
            if (curr_color == prev_color) {
                curr_color = (curr_color + 1) % colors;
            }
            color[i] = curr_color;
            dfs(v, u, curr_color);
            curr_color = (curr_color + 1) % colors;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    fill(degree, degree+n+2, 0);
    for (int i = 0; i < n-1; ++i) {
        cin >> L[i] >> R[i];
        adj[L[i]].push_back(i);
        adj[R[i]].push_back(i);
        ++degree[L[i]];
        ++degree[R[i]];
    }
    fill(cnt_degree, cnt_degree+n+2, 0);
    for (int i = 1; i <= n; ++i) {
        ++cnt_degree[degree[i]];
    }
    for (int d = n; d >= 1; --d) {
        cnt_degree[d] += cnt_degree[d+1];
    }
    for (colors = 1; colors <= n; ++colors) {
        int bad_cities = cnt_degree[colors+1];
        if (bad_cities <= k) {
            cout << colors << '\n';
            fill(color, color+n+2, -1);
            dfs(1, -1, -1);
            for (int i = 0; i < n-1; ++i) {
                cout << color[i]+1 << ' ';
            }
            return 0;
        }
    }
}
