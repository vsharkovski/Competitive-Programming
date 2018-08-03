#include <bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    bool a[n][n];
    int b[n][n] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            a[i][j] = ch == '.';
        }
    }
    int maxcnt=0, maxx=0, maxy=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool isship = 1;
            if (j+k > n) {
                isship = 0;
            } else {
                for (int q = j; q < j+k; ++q) {
                    if (a[i][q] == 0) {
                        isship = 0;
                        break;
                    }
                }
            }
            if (isship) {
                for (int q = j; q < j+k; ++q) {
                    ++b[i][q];
                    if (b[i][q] > maxcnt) {
                        maxcnt = b[i][q];
                        maxx = i;
                        maxy = q;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool isship = 1;
            if (i+k > n) {
                isship = 0;
            } else {
                for (int q = i; q < i+k; ++q) {
                    if (a[q][j] == 0) {
                        isship = 0;
                        break;
                    }
                }
            }
            if (isship) {
                for (int q = i; q < i+k; ++q) {
                    ++b[q][j];
                    if (b[q][j] > maxcnt) {
                        maxcnt = b[q][j];
                        maxx = q;
                        maxy = j;
                    }
                }
            }
        }
    }
    cout << maxx+1 << " " << maxy+1 << '\n';
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout << b[i][j];
//        }
//        cout << '\n';
//    }
}
