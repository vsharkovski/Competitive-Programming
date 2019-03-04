#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




int ans;

void dfs(vector<int> v1, vector<int> v2, int steps) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int> temp(10), v1copy = v1;
    v1 = vector<int>(temp.begin(), set_difference(v1copy.begin(), v1copy.end(), v2.begin(), v2.end(), temp.begin()));
    v2 = vector<int>(temp.begin(), set_difference(v2.begin(), v2.end(), v1copy.begin(), v1copy.end(), temp.begin()));
    if (v1.empty() || v2.empty()) {
        ans = min(ans, steps);
        return;
    }
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    if (v1[0] < v2[0]) {
        swap(v1, v2);
    }
    for (int i = 0; i < 3 && i < min(v1.size(), v2.size()); ++i) {
        if (v1[0] <= v2[i]) break;
        if (i > 0 && v2[i] == v2[i-1]) continue;
        vector<int> v3 = v1, v4 = v2;
        v3[0] -= v4[i];
        v4.erase(v4.begin() + i);
        dfs(v3, v4, steps + 1);
    }
}

void Main() {
    int n, sum1 = 0;
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
        sum1 += v1[i];
    }
    int m, sum2 = 0;
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; ++i) {
        cin >> v2[i];
        sum2 += v2[i];
    }
    if (sum1 != sum2) {
        cout << "-1\n";
        return;
    }
    ans = 1e9;
    dfs(v1, v2, 0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
