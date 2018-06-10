#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, K;
    cin >> n >> K;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for (auto it = a.begin(); it != a.end(); ++it) {
        auto bottom = upper_bound(it, a.end(), *it);
        auto top = upper_bound(bottom, a.end(), *it + K) - 1;
        if (*top == *it || top - it == 0) {
            ++cnt;
        }
    }
    cout << cnt;
}
