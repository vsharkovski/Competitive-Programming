#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    set<int> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        b.insert(x);
    }
    for (int x : a) {
        if (b.count(x)) {
            cout << x << ' ';
            b.erase(x);
        }
        if (b.empty()) break;
    }


}


