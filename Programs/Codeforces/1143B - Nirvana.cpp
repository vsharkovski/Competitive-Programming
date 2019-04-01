#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




int len;
int num[20];
ll ans;

void Main() {
    string s;
    cin >> s;
    len = s.length();
    for (int i = 0; i < len; ++i) {
        num[i] = s[i] - '0';
    }
    ans = 0;
    ll prod = 1;
    for (int i = 0; i < len; ++i) {
        if (num[i] > 0) {
            ll prod2 = prod * (num[i] - 1);
            for (int j = i+1; j < len; ++j) {
                prod2 *= 9;
            }
            ans = max(ans, prod2);
        }
        prod *= num[i];
        ans = max(ans, prod);
    }
    prod = 1;
    for (int i = 1; i < len; ++i) {
        prod *= 9;
    }
    ans = max(ans, prod);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef _DEBUG
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    Main();
}
