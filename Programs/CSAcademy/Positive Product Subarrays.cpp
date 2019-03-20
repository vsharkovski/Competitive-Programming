#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




void Main() {
    int n;
    cin >> n;
    ll ans = 0;
    ll sz = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            ans += sz + (sz-1)*(sz)/2;
            sz = 0;
        } else {
            ++sz;
        }
    }
    ans += sz + (sz-1)*(sz)/2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
