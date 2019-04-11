#include <bits/stdc++.h>
using namespace std;
typedef long long ll;






int main() {

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }

    vector<int> vec;
    for (int msk = 0; msk < (1 << n/2); ++msk) {
        int sum = 0;
        for (int i = 0; i < n/2; ++i) {
            if (msk & (1 << i)) {
                sum += a[i];
                if (sum >= m) sum -= m;
            }
        }
        vec.push_back(sum);
    }
    sort(vec.begin(), vec.end());

    int ans = 0;

    for (int msk = 0; msk < (1 << (n - n/2)); ++msk) {
        int sum = 0;
        for (int i = 0; i < n - n/2; ++i) {
            if (msk & (1 << i)) {
                sum += a[n/2 + i];
                if (sum >= m) sum -= m;
            }
        }
        auto it = --lower_bound(vec.begin(), vec.end(), m - sum);
        ans = max(ans, sum + *it);
    }

    cout << ans << '\n';
}
