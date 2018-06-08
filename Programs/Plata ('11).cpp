#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int n, m, s;
    cin >> n >> m >> s;
    int d = 0;
    while (s > 0) {
        if (d < 100) {
            s -= n;
        } else {
            s -= m;
        }
        ++d;
    }
    cout << d;


}
