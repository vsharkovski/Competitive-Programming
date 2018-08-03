#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int cnt = 1;
    int r = m;
    while (!v.empty()) {
        int a = v[0];
        if (a > r || r <= 0) {
            r = m;
            cnt++;
        }
        if (a <= r) {
            r -= a;
            v.erase(v.begin());
        }
    }
    cout << cnt << endl;
}
