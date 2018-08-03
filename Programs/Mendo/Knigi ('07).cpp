#include <bits/stdc++.h>
using namespace std;
 
int main()
{
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int f = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) continue;
 
            int x = a[i][j];
            bool t = 1;
 
            for (int k = i-1; k >= 0; --k) {
                if (a[k][j] >= x) {
                    t = 0;
                    break;
                }
            }
            if (t) {
//                cout << x << " (" << i << "," << j << ") is visible\n";
                ++f;
                continue;
            }
            t = 1;
 
            for (int k = i+1; k < n; ++k) {
                if (a[k][j] >= x) {
                    t = 0;
                    break;
                }
            }
            if (t) {
//                cout << x << " (" << i << "," << j << ") is visible\n";
                ++f;
                continue;
            }
            t = 1;
 
            for (int k = j-1; k >= 0; --k) {
                if (a[i][k] >= x) {
                    t = 0;
                    break;
                }
            }
            if (t) {
//                cout << x << " (" << i << "," << j << ") is visible\n";
                ++f;
                continue;
            }
            t = 1;
 
            for (int k = j+1; k < n; ++k) {
                if (a[i][k] >= x) {
                    t = 0;
                    break;
                }
            }
            if (t) {
//                cout << x << " (" << i << "," << j << ") is visible\n";
                ++f;
            }
 
        }
    }
    cout << f;
}
