// note: might need to change int to long long or use modulo

typedef vector<vector<int>> matrix;

matrix matMul(matrix& a, matrix& b) {
    int p = a.size(), q = a[0].size(), r = b[0].size();
    matrix c(p, vector<int>(r, 0));
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < r; ++j)
            for (int k = 0; k < q; ++k)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

matrix matPow(matrix& a, int b) {
    int n = a.size();
    matrix res(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) res[i][i] = 1;
    while (b) {
        if (b & 1) res = matMul(res, a);
        a = matMul(a, a);
        b >>= 1;
    }
    return res;
}
