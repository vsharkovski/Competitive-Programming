#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;

int n;
int cnt[4];
double d[maxn][maxn][maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    d[0][0][0] = 0;
    for (int a = 0; a <= n; ++a) {
        for (int b = 0; b <= n; ++b) {
            for (int c = 0; c <= n; ++c) {
                if (a+b+c == 0) continue;
                d[a][b][c] = n;
                if (a) d[a][b][c] += d[a-1][b+1][c] * a;
                if (b) d[a][b][c] += d[a][b-1][c+1] * b;
                if (c) d[a][b][c] += d[a][b][c-1]   * c;
                d[a][b][c] /= double(a+b+c);
            }
        }
    }
    cout << fixed << setprecision(15);
    cout << d[cnt[3]][cnt[2]][cnt[1]] << endl;
}
