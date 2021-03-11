#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    int i = 0, j = n-1;
    while (i < j) {
        if (a[i] == a[j]) {
            ++i, --j;
        } else if (a[i] < a[j]) {
            a[i+1] += a[i];
            ++ans;
            ++i;
        } else { // a[i] > a[j]
            a[j-1] += a[j];
            ++ans;
            --j;
        }
    }
    cout << ans << '\n';
}
