#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, x;
    cin >> n >> x;

    // x <= 10^5 < 2^17
    // each element <= 10^6 < 2^20

    vector<int> a;

    if (n == 1) {
        a.push_back(x);
    } else if (n == 2) {
        a.push_back(0);
        a.push_back(x);
    } else {
        int s = 0;
        for (int i = 1; i <= n-3; ++i) {
            s ^= i;
            a.push_back(i);
        }
        if (s == x) {
            a.push_back(1<<17);
            a.push_back(1<<18);
            a.push_back((1<<17) + (1<<18));
        } else {
            a.push_back(s + (1<<17));
            a.push_back((1<<17) + (1<<18));
            a.push_back((1<<18) + x);
        }
    }
    sort(a.begin(), a.end());

    int res = 0;
    bool distinct = true;

    int pr = -1;
    for (int v : a) {
        res ^= v;
        distinct &= (v != pr);
        pr = v;
    }

    if (res == x && distinct) {
        cout << "YES\n";
        for (int v : a) {
            cout << v << ' ';
        }
    } else {
        cout << "NO\n";
    }

}
