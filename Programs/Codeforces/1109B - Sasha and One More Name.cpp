#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    bool allsame = true;
    for (int i = 1; i < n; ++i) {
        if (n % 2 == 0 || i != n/2) {
            if (s[i] != s[0]) {
                allsame = false;
                break;
            }
        }
    }
    if (allsame) {
        cout << "Impossible\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        string t = s.substr(i) + s.substr(0, i);
        if (t != s) {
            bool palindrome = true;
            for (int j = 0; j < n; ++j) {
                if (t[j] != t[n-j-1]) {
                    palindrome = false;
                    break;
                }
            }
            if (palindrome) {
                cout << "1\n";
                return 0;
            }
        }
    }
    cout << "2\n";
}
