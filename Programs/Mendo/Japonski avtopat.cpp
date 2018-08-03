#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b) {
        return a.first < b.first;
    });
    long long cnt = 0, curr = 0;
    for (auto p : v) {
        if (p.second > curr) {
            cnt += p.second - curr;
        }
        curr = p.second;
    }
    cout << cnt << '\n';

}
