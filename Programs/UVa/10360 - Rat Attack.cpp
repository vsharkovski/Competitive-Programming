#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int T;
    cin >> T;
    while (T--) {

        int d, n;
        cin >> d >> n;

        int a[1026][1026];
        memset(a, 0, sizeof(a));

        int maxx = -1, maxy = -1, maxsz = -1;

        for (int q = 0; q < n; ++q) {
            int x, y, s;
            cin >> x >> y >> s;
            //|i-x|<=d ; |j-y|<=d ;
            for (int i = x-d; i <= min(x+d, 1024); ++i) {
                if (i < 0) continue;
                for (int j = y-d; j <= min(y+d, 1024); ++j) {
                    if (j < 0) continue;
                    a[i][j] += s;
                    if (   (a[i][j] > maxsz)
                        or (a[i][j] == maxsz && ((i < maxx) or (i == maxx && j < maxy)) ))
                    {
                        maxsz = a[i][j];
                        maxx = i;
                        maxy = j;
                    }
                }
            }
        }

        cout << maxx << ' ' << maxy << ' ' << maxsz << endl;

    }


}
