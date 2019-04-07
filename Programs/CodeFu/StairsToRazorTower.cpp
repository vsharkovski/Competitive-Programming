#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;



const long long m0d = 100000007;

void matMul(long long a[3][3], long long b[3][3], int p, int q, int r) {
    long long c[3][3] = {};
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < r; ++j)
            for (int k = 0; k < q; ++k) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= m0d;
            }
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < r; ++j) {
            b[i][j] = c[i][j];
        }
    }
}

void matPow(long long _a[3][3], int b) {
    long long res[3][3] = {};
    for (int i = 0; i < 3; ++i) res[i][i] = 1;
    long long a[3][3];
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) a[i][j] = _a[i][j];
    while (b) {
        if (b & 1) matMul(a, res, 3, 3, 3);
        matMul(a, a, 3, 3, 3);
        b >>= 1;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            _a[i][j] = res[i][j];
        }
    }
}

class StairsToRazorTower
{
public:
    int getNumberOfWays(int n)
    {
        long long X[3][3] = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 0, 1}
        };
        long long F0[3][3] = {
            {1, 0, 0},
            {1, 0, 0},
            {1, 0, 0}
        };
        if (n < 3) return F0[n][0];
        matPow(X, n);
        matMul(X, F0, 3, 3, 1);
        return F0[0][0];
    }
};
