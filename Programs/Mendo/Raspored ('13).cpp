#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> v1 = {v[0]};
    for (int i = 1; i < n; ++i) {
        if (i & 1) {
            v1.insert(v1.begin(), v[i]);
        } else {
            v1.push_back(v[i]);
        }
    }

//    for (int x : v1) cout << x << ' ';
//    cout << '\n';

    int mxd = -1;
    for (int i = 1; i < n; ++i) {
        mxd = max(mxd, abs(v1[i]-v1[i-1]));
    }
    mxd = max(mxd, abs(v1[0]-v1[n-1]));

    cout << mxd;


}
