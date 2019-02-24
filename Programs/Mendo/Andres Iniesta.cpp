#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




const int MAXR = 205, MAXC = 205, MAXK = 55;

int R, C, K;
bool obstacle[MAXR][MAXC];

int dpn[MAXK][MAXR][MAXC];
int dpe[MAXK][MAXR][MAXC];
int dps[MAXK][MAXR][MAXC];
int dpw[MAXK][MAXR][MAXC];
int dpv[MAXK][MAXR][MAXC];
int dph[MAXK][MAXR][MAXC];
// dp(d)[k][r][c] = how many cells Iniesta can see,
// if he is at (r, c), and can remove k blocks in direction d (including current cell)

void Main() {
    cin >> R >> C >> K;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            char ch;
            cin >> ch;
            obstacle[r][c] = ch == '*';
        }
    }
    for (int k = 0; k <= K; ++k) {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                int k1 = obstacle[r][c] ? k-1 : k;
                if (k1 < 0) {
                    dpn[k][r][c] = 0;
                } else {
                    dpn[k][r][c] = 1;
                    if (r > 0) dpn[k][r][c] += dpn[k1][r-1][c];
                }
            }
        }
    }
    for (int k = 0; k <= K; ++k) {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                int k1 = obstacle[r][c] ? k-1 : k;
                if (k1 < 0) {
                    dpw[k][r][c] = 0;
                } else {
                    dpw[k][r][c] = 1;
                    if (c > 0) dpw[k][r][c] += dpw[k1][r][c-1];
                }
            }
        }
    }
    for (int k = 0; k <= K; ++k) {
        for (int r = R-1; r >= 0; --r) {
            for (int c = C-1; c >= 0; --c) {
                int k1 = obstacle[r][c] ? k-1 : k;
                if (k1 < 0) {
                    dps[k][r][c] = 0;
                } else {
                    dps[k][r][c] = 1;
                    if (c > 0) dps[k][r][c] += dps[k1][r+1][c];
                }
            }
        }
    }
    for (int k = 0; k <= K; ++k) {
        for (int r = R-1; r >= 0; --r) {
            for (int c = C-1; c >= 0; --c) {
                int k1 = obstacle[r][c] ? k-1 : k;
                if (k1 < 0) {
                    dpe[k][r][c] = 0;
                } else {
                    dpe[k][r][c] = 1;
                    if (c > 0) dpe[k][r][c] += dpe[k1][r][c+1];
                }
            }
        }
    }
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            for (int k = 0; k <= K; ++k) {
                dph[k][r][c] = 0;
                int k1 = obstacle[r][c] ? k-1 : k;
                if (k1 < 0) continue;
                for (int kw = 0; kw <= k1; ++kw) {
                    int ke = k1 - kw;
                    int curr = 1;
                    if (c > 0) curr += dpw[kw][r][c-1];
                    if (c+1 < C) curr += dpe[ke][r][c+1];
                    dph[k][r][c] = max(dph[k][r][c], curr);
                }
            }
        }
    }
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            for (int k = 0; k <= K; ++k) {
                dpv[k][r][c] = 0;
                int k1 = obstacle[r][c] ? k-1 : k;
                if (k1 < 0) continue;
                for (int kn = 0; kn <= k1; ++kn) {
                    int ks = k1 - kn;
                    int curr = 1;
                    if (r > 0) curr += dpn[kn][r-1][c];
                    if (r+1 < R) curr += dps[ks][r+1][c];
                    dpv[k][r][c] = max(dpv[k][r][c], curr);
                }
            }
        }
    }
    int ans = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            int k1 = obstacle[r][c] ? K-1 : K;
            if (k1 < 0) continue;
            for (int kv = 0; kv <= k1; ++kv) {
                int kh = k1 - kv;
                int kv1 = kv + int(obstacle[r][c]);
                int kh1 = kh + int(obstacle[r][c]);
                ans = max(ans, -1 + dpv[kv1][r][c] + dph[kh1][r][c]);
            }
        }
    }
    cout << ans << '\n';
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
