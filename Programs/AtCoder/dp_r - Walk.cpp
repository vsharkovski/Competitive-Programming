#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



typedef vector<vector<ll>> matrix;

const ll mod = 1e9 + 7;

matrix matmult(matrix a, matrix& b) {
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

matrix matpow(matrix& a, ll b) {
    matrix res(a.size(), vector<ll>(a.size(), 0));
    for (int i = 0; i < a.size(); ++i) res[i][i] = 1;
    while (b) {
        if (b & 1) res = matmult(res, a);
        a = matmult(a, a);
        b >>= 1;
    }
    return res;
}

void Main() {
    ll N, K;
    cin >> N >> K;
    matrix A(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    A = matpow(A, K);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ans += A[i][j];
            ans %= mod;
        }
    }
    cout << ans << '\n';
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
