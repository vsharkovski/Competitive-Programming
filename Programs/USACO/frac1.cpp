#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


/*
LANG: C++
TASK: frac1
*/

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    #ifndef _DEBUG
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    vector<pii> fractions;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (j > 0) {
                int g = gcd(i, j);
                fractions.emplace_back(i/g, j/g);
            }
        }
    }

    sort(fractions.begin(), fractions.end(), [&] (pii& x, pii& y) {
        double xv = double(x.first)/double(x.second);
        double yv = double(y.first)/double(y.second);
        return xv < yv;
    });

    for (int i = 0; i < (int)fractions.size(); ++i) {
        if (i == 0 || fractions[i] != fractions[i-1]) {
            cout << fractions[i].first << '/' << fractions[i].second << '\n';
        }
    }

}
