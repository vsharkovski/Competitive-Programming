#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;


string dfs(ll n, ll k) {
    if (n == 1) {
        return to_string(k-1);
    } else if (k <= (1LL << (n-1))) {
        return "0" + dfs(n-1, k);
    } else {
        return "1" + dfs(n-1, (1LL << n) - k + 1);
    }
}

void Main() {
    ll n, k;
    cin >> n >> k;
    cout << dfs(n, k) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
