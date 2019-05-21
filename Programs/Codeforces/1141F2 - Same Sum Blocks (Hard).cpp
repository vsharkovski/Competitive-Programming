#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, vector<pii>> sums;
    for (int r = 0; r < n; ++r) {
        int sum = 0;
        for (int l = r; l >= 0; --l) {
            sum += a[l];
            sums[sum].emplace_back(l, r);
        }
    }
    vector<pii> best_set;
    for (auto& kvp : sums) {
        vector<pii> curr_set;
        int max_r = -1;
        for (pii& p : kvp.second) {
            if (p.first > max_r) {
                max_r = p.second;
                curr_set.push_back(p);
            }
        }
        if (curr_set.size() > best_set.size()) {
            best_set = curr_set;
        }
    }
    cout << best_set.size() << '\n';
    for (auto& p : best_set) {
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
}
