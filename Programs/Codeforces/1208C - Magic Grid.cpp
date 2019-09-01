#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<vector<int>> base = {
        {8, 9, 1, 13},
        {3, 12, 7, 5},
        {0, 2, 4, 11},
        {6, 10, 15, 14}
    };
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << base[i%4][j%4] + 16*((n/4)*(i/4) + (j/4)) << ' ';
        }
        cout << '\n';
    }
}
