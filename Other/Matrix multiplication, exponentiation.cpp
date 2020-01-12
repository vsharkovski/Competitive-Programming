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

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

const int M = 100;

struct matrix {
	int r, c;
	ll m[M][M];
	matrix(int r, int c) : r(r), c(c) {
		memset(m, 0, sizeof(m));
	}
	matrix& operator = (const matrix& o) {
		r = o.r, c = o.c;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				m[i][j] = o.m[i][j];
		return *this;
	}
};

void matmul(matrix& a, matrix& b, matrix& res) {
	int p = a.r, q = a.c, r = b.c;
	matrix c(p, r);
	for (int i = 0; i < p; ++i)
		for (int k = 0; k < q; ++k)
			for (int j = 0; j < r; ++j)
				c.m[i][j] = (c.m[i][j] + a.m[i][k]*b.m[k][j]) % mod;
	res = c;
}

void matpow(matrix& a, matrix& res_real, int pwr) {
	matrix res(a.r, a.r);
	for (int i = 0; i < a.r; ++i) res.m[i][i] = 1;
	while (pwr) {
		if (pwr & 1) {
			matmul(res, a, res);
		}
		matmul(a, a, a);
		pwr /= 2;
	}
	res_real = res;
}
