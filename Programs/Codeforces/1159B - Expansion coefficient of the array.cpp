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

    int k = 1e9;
    for (int i = 0; i < n; ++i) {
        k = min(k, a[i] / max(i, n - 1 - i));
    }

    cout << k << '\n';

}
