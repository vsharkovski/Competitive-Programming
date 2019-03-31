#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



typedef vector<vector<ll>> matrix;
const ll mod = 1e9 + 7;

matrix matMul(matrix& a, matrix& b) {
    int p = a.size(), q = a[0].size(), r = b[0].size();
    matrix c(p, vector<ll>(r, 0));
    for (int i = 0; i < p; ++i) {
        for (int k = 0; k < q; ++k) {
            for (int j = 0; j < r; ++j) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

matrix matPow(matrix& a, ll b) {
    int n = a.size();
    matrix res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (b) {
        if (b & 1) res = matMul(res, a);
        a = matMul(a, a);
        b >>= 1;
    }
    return res;
}

void Main() {
    ll n, m;
    cin >> n >> m;

    matrix F0(m, vector<ll>(1));
    for (int i = 0; i < m; ++i) {
        F0[i][0] = 1;
    }

    // transposition matrix
    matrix T(m, vector<ll>(m, 0));
    for (int i = 1; i < m; ++i) {
        T[i-1][i] = 1;
    }
    // the coefficients
    T[m-1][0] = 1;
    T[m-1][m-1] = 1;

    matrix Tn = matPow(T, n); // raise T to n-th power
    matrix Fn = matMul(Tn, F0); // Fn

    cout << Fn[0][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    Main();
}
