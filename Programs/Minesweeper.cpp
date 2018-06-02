#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    int field[101][101];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            if (ch == '.') {
                field[i][j] = 0;
            } else if (ch == '*') {
                field[i][j] = 500;
            } else {
                field[i][j] = ch-'0';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val = field[i][j];
            if (0 <= val && val <= 8) {
                int cnt = 0;
                for (int k = i-1; k <= i+1; ++k) {
                    for (int l = j-1; l <= j+1; ++l) {
                        if (k >= 0 && k < n && l >= 0 && l < m) {
                            if (field[k][l] == 500) {
                                ++cnt;
                            }
                        }
                    }
                }
                if (cnt != val) {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
}
