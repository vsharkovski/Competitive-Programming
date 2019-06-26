#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<vl> matrix;


const ll mod = 1e9 + 7;

ll A, B, n, x;

matrix matmul(matrix& a, matrix& b) {
    int p = a.size(), q = a[0].size(), r = b[0].size();
    matrix res(p, vl(r, 0));
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < r; ++j) {
            for (int k = 0; k < q; ++k) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

matrix matpow(matrix& a, ll pwr) {
    int sz = a.size();
    matrix res(sz, vl(sz, 0));
    for (int i = 0; i < sz; ++i) res[i][i] = 1;
    while (pwr > 0) {
        if (pwr & 1) res = matmul(res, a);
        a = matmul(a, a);
        pwr >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> A >> B >> n >> x;
    matrix T = {{A, 1}, {0, 1}};
    matrix Tn = matpow(T, n);
    matrix F0 = {{x}, {B}};
    matrix Fn = matmul(Tn, F0);
    cout << Fn[0][0] << '\n';
}
