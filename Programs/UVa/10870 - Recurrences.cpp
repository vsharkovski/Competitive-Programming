#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



typedef vector<vector<ll>> matrix;

ll mod;

matrix matMul(matrix& a, matrix& b) {
    int p = a.size(), q = a[0].size(), r = b[0].size();
    matrix c(p, vector<ll>(r, 0));
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < r; ++j) {
            for (int k = 0; k < q; ++k) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

matrix matPow(matrix& a, int b) {
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
    int k, n;
    while (cin >> k >> n >> mod, k+n+mod != 0) {
        vector<ll> c(k);
        for (int i = 0; i < k; ++i) {
            cin >> c[i];
        }
        matrix F0(k, vector<ll>(1));
        for (int i = 0; i < k; ++i) {
            cin >> F0[i][0];
        }
        matrix T(k, vector<ll>(k, 0));
        for (int i = 1; i < k; ++i) {
            T[i-1][i] = 1;
        }
        for (int i = 0; i < k; ++i) {
            T[k-1][i] = c[k-1-i];
        }
        matrix Tfinal = matPow(T, n-1);
        matrix Ffinal = matMul(Tfinal, F0);
        cout << Ffinal[0][0] << '\n';
    }
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
