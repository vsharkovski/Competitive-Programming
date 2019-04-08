#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;





void Main() {
    int n, m;
    cin >> n >> m;
    int a[505][505], b[505][505];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < m; ++j) {
            s += a[i][j] != b[i][j];
        }
        if (s % 2 == 1) {
            cout << "No\n";
            return;
        }
    }
    for (int j = 0; j < m; ++j) {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += a[i][j] != b[i][j];
        }
        if (s % 2 == 1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
