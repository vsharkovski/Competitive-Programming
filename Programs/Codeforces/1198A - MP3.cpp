#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    int I;
    cin >> n >> I;
    I *= 8;
    I /= n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++mp[a];
    }
    int ans = n;
    int cnt = 0;
    int dist = 0;
    auto L = mp.begin();
    for (auto R = mp.begin(); R != mp.end(); ++R) {
        ++dist;
        cnt += R->second;
        while (dist > 1 && ceil(log2(double(dist)) > I)) {
            --dist;
            cnt -= L->second;
            ++L;
        }
        if (ceil(log2(double(dist))) <= I) {
            ans = min(ans, n - cnt);
        }
    }
    cout << ans << endl;
}
