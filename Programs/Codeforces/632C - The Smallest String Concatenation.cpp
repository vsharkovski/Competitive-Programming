#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    vector<string> v(n);

    for (string& s : v) {
        cin >> s;
    }

    sort(v.begin(), v.end(), [&] (string& a, string& b) {
        string x = a + b, y = b + a;
        return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    });

    for (string& s : v) {
        cout << s;
    }

}
