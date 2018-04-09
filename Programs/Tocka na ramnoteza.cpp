#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> v(n);
    int sr = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        v[i] = a;
        sr += a;
    }
    int _ri = -1;
    int sl = 0;
    for (int i = 0; i < n; ++i) {
        int a = v[i];
        sr -= a;
        if (sl == sr) {
            _ri = i+1;
            break;
        }
        sl += a;
    }
    cout << _ri << endl;
}