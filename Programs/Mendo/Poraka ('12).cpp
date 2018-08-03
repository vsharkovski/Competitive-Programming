#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string p;
    cin >> p;

    int data[k][26] = {};

    for (int i = 0; i < k; ++i) {
        for (int j = i; j < n; j += k) {
            data[i][p[j]-'A']++;
        }
    }

    int ans = 0;

    for (int i = 0; i < k; ++i) {
        int sum = 0, best = -1;
        for (int j = 0; j < 26; ++j) {
            int cnt = data[i][j];
            sum += cnt;
            best = max(best, cnt);
        }
        ans += (sum-best);
    }

    cout << ans;

}
