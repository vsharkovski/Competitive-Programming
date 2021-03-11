#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


const int N = 1010;

int ans;
int a[2][2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(a, 0, sizeof(a));
    int n;
    cin >> n;
    for (int g = 0; g < 2; ++g) {
        for (int i = 0; i < n; ++i) {
            int x;
            char c;
            cin >> x >> c;
            a[g][c == '-'][x] += 1;
        }
    }
    /*
    for (int g = 0; g < 2; ++g) {
        for (int p = 0; p < 2; ++p) {
            if(g)cout<<"F ";else cout<<"M ";
            if (p)cout<<"- :: ";else cout << "+ :: ";
            for (int x = 1; x < N; ++x) {
                if (a[g][p][x]) {
                    for (int y = 0; y < a[g][p][x]; ++y) {
                        cout << x << ' ';
                    }
                }
            }
            cout << '\n';
        }
    }
    */
    ans = 0;
    for (int g = 0; g < 2; ++g) {
        // m0 and f1
        // f0 and m1
        for (int x = 1; x < N; ++x) {
            for (int y = x+1; y < N; ++y) {
                if (a[g][0][x] == 0) break;
                int res = min(a[g][0][x], a[1-g][1][y]);
                a[g][0][x] -= res;
                a[1-g][1][y] -= res;
                ans += res;
            }
        }
    }
    cout << ans << '\n';
}
