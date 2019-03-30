#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



const int MAXN = 100005;
const int MAXLOG = 20;

int N;
int depth[MAXN];
int parent[MAXN];
ll parentdist[MAXN];
int P[MAXN][MAXLOG];
ll D[MAXN][MAXLOG];

void preprocess() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < MAXLOG; ++j) {
            P[i][j] = -1;
        }
        P[i][0] = parent[i];
        D[i][0] = parentdist[i];
    }
    for (int j = 1; j < MAXLOG; ++j) {
        for (int i = 0; i < N; ++i) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[ P[i][j-1] ][j-1];
                D[i][j] = D[i][j-1] + D[P[i][j-1]][j-1];
            }
        }
    }
}

ll getdistance(int a, int b) {
    ll ans = 0;
    if (depth[a] < depth[b]) swap(a, b);
    for (int j = MAXLOG-1; j >= 0; --j) {
        if (depth[a] - (1 << j) >= depth[b]) {
            ans += D[a][j];
            a = P[a][j];
        }
    }
    if (a == b) return ans;
    for (int j = MAXLOG-1; j >= 0; --j) {
        if (P[a][j] != -1 && P[a][j] != P[b][j]) {
            ans += D[a][j];
            a = P[a][j];
            ans += D[b][j];
            b = P[b][j];
        }
    }
    ans += D[a][0];
    ans += D[b][0];
    return ans;
}

void Main() {
    while (cin >> N, N != 0) {
        depth[0] = 0;
        for (int i = 1; i < N; ++i) {
            int a, l;
            cin >> a >> l;
            parent[i] = a;
            parentdist[i] = l;
            depth[i] = depth[a] + 1;
        }
        preprocess();
        int Q;
        cin >> Q;
        while (Q--) {
            int a, b;
            cin >> a >> b;
            cout << getdistance(a, b);
            if (Q > 0) cout << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    Main();
}
