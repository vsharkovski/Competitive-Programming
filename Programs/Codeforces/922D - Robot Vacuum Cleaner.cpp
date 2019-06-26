#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;




ll inversions(string& s) {
    ll ans = 0, cnt = 0;
    for (char& ch : s) {
        if (ch == '0') {
            ++cnt;
        }
    }
    for (char& ch : s) {
        if (ch == '0') {
            cnt -= 1;
        } else {
            ans += cnt;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    vector<string> v(n);
    for (string& s : v) {
        cin >> s;
        for (char& ch : s) {
            ch = (ch == 'h') ? '0' : '1';
        }
    }

    sort(v.begin(), v.end(), [&] (string& a, string& b) {
        string x = a + b, y = b + a;
        return inversions(x) > inversions(y);
    });

    string res = "";
    for (string& s : v) {
        res += s;
    }

    cout << inversions(res) << '\n';

}
