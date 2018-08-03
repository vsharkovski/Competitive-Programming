#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> v(n);
    int high = -1;
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        if (c > high) high = c;
        v[i] = c;
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
        r += (high - v[i]);
    }
    cout << r;
}
