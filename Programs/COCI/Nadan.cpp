#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;





int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int k, n;
    cin >> k >> n;

    for (int i = 1; i <= n-1; ++i) {
        k -= i;
        cout << i << '\n';
    }
    cout << k << '\n';

}
