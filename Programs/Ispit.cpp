#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a[303][303];
    memset(a, 0, sizeof(a));

    int r, c;
    cin >> r >> c;
    int i, j;
    for (i = 0; i <= r+1; ++i) {
        a[i][0] = 9;
        a[i][c+1] = 9;
    }
    for (j = 0; j <= c+1; ++j) {
        a[0][j] = 9;
        a[r+1][j] = 9;
    }
    i = r;
    j = 1;
    int cnt = 0;
    char dir = 'u';
    bool changed_prev = 0;
    while (1) {
        a[i][j]++;
//        for (int q = 0; q <= r+1; ++q) {
//            for (int w = 0; w <= c+1; ++w) {
//                cout << a[q][w] << ' ';
//            }
//            cout << '\n';
//        } cout << '\n';
        if (dir == 'u') {
            if (a[i-1][j]) {
                dir = 'r';
                cnt++;
                if (changed_prev) {
                    break;
                }
                changed_prev = 1;
            } else {
                i--;
                changed_prev = 0;
            }
        } else if (dir == 'r') {
            if (a[i][j+1]) {
                dir = 'd';
                cnt++;
                if (changed_prev) {
                    break;
                }
                changed_prev = 1;
            } else {
                j++;
                changed_prev = 0;
            }
        } else if (dir == 'd') {
            if (a[i+1][j]) {
                dir = 'l';
                cnt++;
                if (changed_prev) {
                    break;
                }
                changed_prev = 1;
            } else {
                i++;
                changed_prev = 0;
            }
        } else if (dir == 'l') {
            if (a[i][j-1]) {
                dir = 'u';
                cnt++;
                if (changed_prev) {
                    break;
                }
                changed_prev = 1;
            } else {
                j--;
                changed_prev = 0;
            }
        }
    }
    cout << cnt-2;

}
