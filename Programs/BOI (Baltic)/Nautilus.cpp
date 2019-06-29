#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int MAXR = 500, MAXC = 500, MAXM = 5000;

int R, C, M;
char signals[MAXM];
bitset<MAXC> isempty[MAXR+2];
bitset<MAXC> cur[MAXR+2], nxt[MAXR+2];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> R >> C >> M;
    for (int r = 1; r <= R; ++r) {
        for (int c = 0; c < C; ++c) {
            char ch;
            cin >> ch;
            isempty[r][c] = ch == '.';
        }
    }
    for (int i = 0; i < M; ++i) {
        cin >> signals[i];
    }
    for (int r = 1; r <= R; ++r) {
        cur[r] = isempty[r];
    }
    for (int i = 0; i < M; ++i) {
        if (signals[i] == 'N') {
            for (int r = 1; r <= R; ++r) {
                nxt[r] = cur[r+1] & isempty[r];
            }
        } else if (signals[i] == 'S') {
            for (int r = 1; r <= R; ++r) {
                nxt[r] = cur[r-1] & isempty[r];
            }
        } else if (signals[i] == 'E') {
            for (int r = 1; r <= R; ++r) {
                nxt[r] = (cur[r] << 1) & isempty[r];
            }
        } else if (signals[i] == 'W') {
            for (int r = 1; r <= R; ++r) {
                nxt[r] = (cur[r] >> 1) & isempty[r];
            }
        } else {
            for (int r = 1; r <= R; ++r) {
                nxt[r] = (cur[r-1] | cur[r+1] | (cur[r] << 1) | (cur[r] >> 1)) & isempty[r];
            }
        }
        swap(nxt, cur);
    }
    int ans = 0;
    for (int r = 1; r <= R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (cur[r][c]) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
}
