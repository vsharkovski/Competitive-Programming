#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
TASK: palsquare
LANG: C++
*/

int B;
char realchar[300];

bool is_palindrome(string& s) {
    for (int i = 0, j = s.length()-1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

string b10toB(int x) {
    string res = "";
    while (x > 0) {
        res += realchar[x % B];
        x /= B;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    #ifndef _DEBUG
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    #endif

    cin >> B;

    for (int i = 0; i < 10; ++i) {
        realchar[i] = i + '0';
    }
    for (int i = 10; i <= 20; ++i) {
        realchar[i] = i - 10 + 'A';
    }

    for (int x = 1; x <= 300; ++x) {
        string xsq = b10toB(x*x);
        if (is_palindrome(xsq)) {
            cout << b10toB(x) << ' ' << xsq << '\n';
        }
    }

}
