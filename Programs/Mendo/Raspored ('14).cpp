#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> v(3);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < 3; ++j) {
            v[j].push_back(x);
        }
    }

    int ans = 1e9;

    for (int i = 0; i < 3; ++i) {
        int c = 0;
        vector<int> v1;
        for (int x : v[i]) {
            if (x == i+1) {
                ++c;
            } else {
                v1.push_back(x);
            }
        }
        for (int j = 1; j < v1.size(); ++j) {
            if (v1[j-1] == v1[j]) {
                ++c;
            }
        }
        ans = min(ans, c);
    }

    cout << ans;



}
