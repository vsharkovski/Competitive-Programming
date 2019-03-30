#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;


/*
    p = a + b
    q = a * b
    a^n + b^n = ?

    let X[n] = a^n + b^n
    then X[n] = p*X[n-1] - q*X[n-2]
    so use matrix exponentiation
*/

typedef vector<vector<ll>> matrix;

matrix matMul(matrix a, matrix& b) {
    int p = a.size(), q = a[0].size(), r = b[0].size();
    matrix c(p, vector<ll>(r, 0));
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < r; ++j)
            for (int k = 0; k < q; ++k)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

matrix matPow(matrix& a, ll b) {
    matrix res(a.size(), vector<ll>(a.size(), 0));
    for (int i = 0; i < a.size(); ++i) res[i][i] = 1;
    while (b) {
        if (b & 1) res = matMul(res, a);
        a = matMul(a, a);
        b >>= 1;
    }
    return res;
}

void Main() {
    string line;
    while (true) {
        getline(cin, line);
        if (line == "0 0") break;
        stringstream ss(line);
        ll p, q, n;
        ss >> p >> q >> n;
        matrix a = {
            {p, -q},
            {1,  0}
        };
        matrix b = {
            {p}, // X[1]
            {2}  // X[0]
        };
        matrix c = matMul(matPow(a, n), b);
        cout << c[1][0] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    Main();
}
