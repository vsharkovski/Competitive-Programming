#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    static int cnt[2][1001][1001] = {};

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++cnt[0][x][y];
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        ++cnt[1][x][y];
    }

    int closed = 0, goodclosed = 0;

    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            int x = min(cnt[0][i][j], cnt[1][i][j]);
            cnt[0][i][j] -= x;
            cnt[1][i][j] -= x;
            goodclosed += x;
        }
    }

    for (int j = 1; j <= 1000; ++j) {
        int num[2] = {};
        for (int i = 1; i <= 1000; ++i) {
            num[0] += cnt[0][i][j];
            num[1] += cnt[1][i][j];
        }
        closed += min(num[0], num[1]);
    }

    cout << closed+goodclosed << ' ' << goodclosed << '\n';

}
