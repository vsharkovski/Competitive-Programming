#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;





int main() {
    ios::sync_with_stdio(false); cin.tie();

    string str;
    cin >> str;

    ll a, b;
    cin >> a >> b;

    int len = str.length();

    vector<ll> n(len);
    for (int i = 0; i < len; ++i) {
        n[i] = str[i]-'0';
    }

    vector<ll> pow10b(len);
    pow10b[0] = 1;
    for (int i = 1; i < len; ++i) {
        pow10b[i] = (pow10b[i-1] * 10) % b;
    }

    ll sumb = 0;
    for (int i = 0; i < len; ++i) {
        sumb = (sumb + n[i]*pow10b[len-i-1]) % b;
    }

    ll suma = 0;
    for (int i = 0; i < len-1; ++i) {
        suma = (10*suma + n[i]) % a;
        sumb = (sumb - (n[i]*pow10b[len-i-1]) + b*b) % b;
        if (n[i+1] != 0 && suma == 0 && sumb == 0) {
            cout << "YES\n";
            for (int j = 0; j <= i; ++j) {
                cout << n[j];
            }
            cout << "\n";
            for (int j = i+1; j < len; ++j) {
                cout << n[j];
            }
            cout << "\n";
            return 0;
        }
    }

    cout << "NO\n";

}

