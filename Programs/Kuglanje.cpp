#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<vector<int>> triag;
    for (int i = 1; i <= n; ++i) {
        vector<int> v;
        for (int j = 1; j <= i; ++j) {
            int x; cin >> x;
            v.push_back(x);
        }
        triag.push_back(v);
    }
 
    if (n == 2) {
        cout << triag[0][0] + max(triag[1][0], triag[1][0]) << endl;
    } else if (n == 1) {
        cout << triag[0][0] << endl;
    }
    else {
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; j++) {
                triag[i][j] += max(triag[i+1][j], triag[i+1][j+1]);
            }
        }
        cout << triag[0][0] << endl;
    }
}