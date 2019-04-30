#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;






int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    multiset<int> b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b.insert(x);
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        auto it1 = b.begin();
        auto it2 = b.lower_bound(n - a[i]);
        if (it2 == b.end()) {
            it2 = it1;
        }
        int opt1 = (a[i] + *it1) % n;
        int opt2 = (a[i] + *it2) % n;
        if (opt1 <= opt2) {
            c[i] = opt1;
            b.erase(it1);
        } else {
            c[i] = opt2;
            b.erase(it2);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << c[i] << ' ';
    }
}
