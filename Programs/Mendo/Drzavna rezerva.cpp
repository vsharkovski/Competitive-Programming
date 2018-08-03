#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
        int c, k;
        cin >> c >> k;
        v.emplace_back(c, k);
    }
    sort(v.begin(), v.end(), [](pair<int,int>&a,pair<int,int>&b){
        return a.first < b.first;
    });
    long long z = 0;
    for (auto p : v) {
        if (n == 0) break;
        int c = p.first, k = p.second;
        if (k <= n) {
            z += k*c;
            n -= k;
//            cout << " + " << k << "*" << c;
        } else {
            z += n*c;
//            cout << " + " << n << "*" << c;
            n = 0;
        }
    }
//    cout << '\n';
    cout << z;
}
