#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int mod = 1e9 + 7;
const int maxn = 5005;

void add_self(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

int n;
char type[maxn];
int cur[maxn], nxt[maxn]; // dp

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> type[i];
    }
    memset(cur, 0, sizeof(cur));
    cur[0] = 1;
    for (int i = 0; i < n; ++i) {
        memset(nxt, 0, sizeof(nxt));
        if (i > 0 && type[i-1] == 'f') {
            // cannot decrease level
            if (type[i] == 's') {
                for (int j = 0; j < n; ++j) {
                    add_self(nxt[j], cur[j]);
                }
            } else {
                for (int j = 0; j < n; ++j) {
                    add_self(nxt[j+1], cur[j]);
                }
            }
        } else {
            // can decrease level
            if (type[i] == 's') {
                // nxt[j] = cur[j] + cur[j+1] + ... + cur[n-1]
                int x = 0;
                for (int j = n-1; j >= 0; --j) {
                    add_self(x, cur[j]);
                    nxt[j] = x;
                }
            } else {
                // nxt[j] = cur[j-1] + cur[j] + ... + cur[n-1]
                int x = 0;
                for (int j = n-1; j >= 0; --j) {
                    add_self(x, cur[j]);
                    nxt[j+1] = x;
                }
            }
        }
        swap(cur, nxt);
    }
    int ans = 0;
    for (int j = 0; j < n; ++j) {
        add_self(ans, cur[j]);
    }
    cout << ans << '\n';
}
