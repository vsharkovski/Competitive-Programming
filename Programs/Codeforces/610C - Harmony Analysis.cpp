#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int K;
    cin >> K;

    vector<vector<bool>> a(1<<K, vector<bool>(1<<K));

    a[0][0] = 1;
    for (int k = 1; k <= K; ++k) {
        // first  2^(k-1) rows: duplicate first 2^(k-1) elements
        // second 2^(k-1) rows: invert    first 2^(k-1) elements
        int half = (1<<(k-1)), full = (1<<k);
        for (int i = 0; i < half; ++i) {
            for (int j = half; j < full; ++j) {
                a[i][j] = a[i][j-half];
            }
        }
        for (int i = half; i < full; ++i) {
            for (int j = 0; j < half; ++j) {
                a[i][j] = a[i-half][j];
            }
        }
        for (int i = half; i < full; ++i) {
            for (int j = half; j < full; ++j) {
                a[i][j] = 1 - a[i-half][j-half];
            }
        }
    }

    for (int i = 0; i < (1<<K); ++i) {
        for (int j = 0; j < (1<<K); ++j) {
            cout << (a[i][j] ? '+' : '*');
        }
        cout << '\n';
    }

}
