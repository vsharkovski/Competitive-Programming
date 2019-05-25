#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;





int main() {
    ios::sync_with_stdio(false); cin.tie();

    int n;
    cin >> n;

    vector<int> w(n), h(n);
    vector<pair<ll, int>> hv;
    ll sumw = 0;

    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> h[i];
        sumw += w[i];
        hv.emplace_back(h[i], i);
    }

    sort(hv.begin(), hv.end());

    for (int i = 0; i < n; ++i) {
        if (h[i] == hv[n-1].first && i == hv[n-1].second) {
            cout << (sumw - w[i]) * hv[n-2].first << " ";
        } else {
            cout << (sumw - w[i]) * hv[n-1].first << " ";
        }
    }


}

