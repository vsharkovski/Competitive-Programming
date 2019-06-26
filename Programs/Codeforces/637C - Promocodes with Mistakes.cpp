#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "6\n";
        return 0;
    }
    vector<string> v(n);
    int mindiff = 6;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        for (int j = 0; j < i; ++j) {
            int res = 0;
            for (int k = 0; k < 6; ++k) {
                if (v[i][k] != v[j][k]) {
                    ++res;
                }
            }
            mindiff = min(mindiff, res);
        }
    }
    // mindiff is the minimum number of differences between any pair
    cout << (mindiff-1)/2 << '\n';
}
