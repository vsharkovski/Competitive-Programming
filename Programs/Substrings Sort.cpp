#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), [](string &a, string &b){
        return a.length() < b.length();
    });
    bool ok = 1;
    for (int i = 1; i < n; ++i) {
        string a = v[i-1], b = v[i];
        if (b.find(a) == string::npos) {
            ok = 0;
        }
    }
    if (!ok) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (string s : v)
            cout << s << '\n';
    }
}
