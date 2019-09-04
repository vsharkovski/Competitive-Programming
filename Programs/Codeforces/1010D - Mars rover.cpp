#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;

int n;
int parent[maxn];
int children[maxn][2];
int type[maxn]; // 0=IN, 1=AND, 2=OR, 3=XOR, 4=NOT
int realval[maxn];
int dp[maxn][2][2];

inline int other_child(int i, int c) {
    if (children[i][0] == c) {
        if (type[i] == 4) {
            return 0;
        } else {
            return children[i][1];
        }
    } else {
        return children[i][0];
    }
}

int eval(int u, int c1, int c2) {
    if (c1 == -1 && children[u][0] != -1) {
        c1 = realval[children[u][0]];
    }
    if (c2 == -1 && children[u][1] != -1) {
        c2 = realval[children[u][1]];
    }
    if (type[u] == 0) {
        return realval[u];
    }
    if (type[u] == 1) {
        return c1 & c2;
    }
    if (type[u] == 2) {
        return c1 | c2;
    }
    if (type[u] == 3) {
        return c1 ^ c2;
    }
    if (type[u] == 4) {
        return !c1;
    }
    return -1;
}

void dfs(int i) {
    if (children[i][0] != -1) dfs(children[i][0]);
    if (children[i][1] != -1) dfs(children[i][1]);
    realval[i] = eval(i, -1, -1);
    // cout << "i=" << i << " realval=" << realval[i] << endl;
}

void dfsdp(int i) {
    if (i == 1) {
        for (int c1 = 0; c1 < 2; ++c1) {
            for (int c2 = 0; c2 < 2; ++c2) {
                dp[i][c1][c2] = eval(i, c1, c2);
                // cout << "dp[" << i << "][" << c1 << "][" << c2 << "] = " << dp[i][c1][c2] << endl;
            }
        }
    } else if (type[i] != 0) {
        for (int c1 = 0; c1 < 2; ++c1) {
            for (int c2 = 0; c2 < 2; ++c2) {
                dp[i][c1][c2] = dp[parent[i]][eval(i, c1, c2)][realval[other_child(parent[i], i)]];
                // cout << "dp[" << i << "][" << c1 << "][" << c2 << "] = " << dp[i][c1][c2] << endl;
            }
        }
    }
    if (children[i][0] != -1) dfsdp(children[i][0]);
    if (children[i][1] != -1) dfsdp(children[i][1]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int x, y;
        if (s == "IN") {
            type[i] = 0;
            cin >> x;
            realval[i] = x;
            children[i][0] = -1;
            children[i][1] = -1;
        } else if (s == "AND") {
            type[i] = 1;
            cin >> x >> y;
            children[i][0] = x;
            children[i][1] = y;
            parent[x] = parent[y] = i;
        } else if (s == "OR") {
            type[i] = 2;
            cin >> x >> y;
            children[i][0] = x;
            children[i][1] = y;
            parent[x] = parent[y] = i;
        } else if (s == "XOR") {
            type[i] = 3;
            cin >> x >> y;
            children[i][0] = x;
            children[i][1] = y;
            parent[x] = parent[y] = i;
        } else if (s == "NOT") {
            type[i] = 4;
            cin >> x;
            children[i][0] = x;
            children[i][1] = -1;
            parent[x] = i;
        }
    }
    realval[0] = 0;
    dfs(1);
    dfsdp(1);
    for (int i = 1; i <= n; ++i) {
        if (type[i] == 0) {
            cout << dp[parent[i]][!realval[i]][realval[other_child(parent[i], i)]];
        }
    }
}
