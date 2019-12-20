#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> c;
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i-1]) {
                c.push_back(cnt);
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        c.push_back(cnt);
        int m = c.size();
        //cout << "c:{";
        //for (int i = 0; i < m; ++i) {
        //    cout << c[i] << ' ';
        //}
        //cout << "}\n";
        int gold = c[0];
        int silver = 0;
        int bronze = 0;
        for (int i = 1; i < m; ++i) {
            if (silver <= gold) {
                silver += c[i];
            } else {
                if (bronze <= gold) {
                    bronze += c[i];
                } else if (gold + silver + bronze + c[i] <= n/2) {
                    bronze += c[i];
                } else {
                    break;
                }
            }
        }
        if (gold > 0 && gold < silver && gold < bronze && gold + silver + bronze <= n/2) {
            cout << gold << ' ' << silver << ' ' << bronze << endl;
        } else {
            cout << "0 0 0\n";
        }
    }
}
