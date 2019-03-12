#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;






void Main() {
    int n, m;
    cin >> n >> m;
    int a[505][505];
    int b[505][505];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    vector<int> adiag[1005], bdiag[1005];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            adiag[i+j].push_back(a[i][j]);
            bdiag[i+j].push_back(b[i][j]);
        }
    }
    for (int d = 0; d < n + m - 1; ++d) {
        sort(adiag[d].begin(), adiag[d].end());
        sort(bdiag[d].begin(), bdiag[d].end());
        if (adiag[d] != bdiag[d]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
//        freopen("optmilk.in", "r", stdin);
//        freopen("optmilk.out", "w", stdout);
    #endif
    Main();
    return 0;
}
