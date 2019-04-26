#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    int okrow = -1;
    for (int i = 0; i < n; ++i) {
        bool has2distinct = false;
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (j > 0 && grid[i][j] != grid[i][j-1]) {
                has2distinct = true;
            }
        }
        if (has2distinct && okrow == -1) {
            okrow = i;
        }
    }
    if (okrow == -1) {
        int x = 0;
        for (int i = 0; i < n; ++i) {
            x ^= grid[i][0];
        }
        if (x > 0) {
            cout << "TAK\n";
            for (int i = 0; i < n; ++i) {
                cout << 1 << ' ';
            }
        } else {
            cout << "NIE\n";
        }
    } else {
        int x = 0;
        for (int i = 0; i < n; ++i) {
            if (i != okrow) {
                x ^= grid[i][0];
            }
        }
        for (int j = 0; j < m; ++j) {
            if ((x ^ grid[okrow][j]) > 0) {
                cout << "TAK\n";
                for (int i = 0; i < n; ++i) {
                    if (i != okrow) {
                        cout << 1 << ' ';
                    } else {
                        cout << j+1 << ' ';
                    }
                }
                return 0;
            }
        }
        cout << "NIE\n";
    }
}
