#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    const ll MAX = (1LL<<32) - 1;

    int L;
    cin >> L;

    ll x = 0;
    stack<ll> stk;
    stk.push(1);

    while (L--) {
        string word;
        cin >> word;
        if (word == "for") {
            ll n;
            cin >> n;
            ll product = stk.top();
            if (product <= MAX) {
                product *= n;
            }
            stk.push(product);
        } else if (word == "add") {
            ll val = stk.top();
            if (x + val > MAX) {
                cout << "OVERFLOW!!!\n";
                return 0;
            } else {
                x += val;
            }
        } else { // end
            stk.pop();
        }
    }

    cout << x << '\n';

}
