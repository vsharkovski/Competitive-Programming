#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
 
    string s;
    cin >> s;
 
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ++cnt0;
        else ++cnt1;
    }
 
    if (cnt0 != cnt1) {
        cout << 1 << endl << s << endl;
    } else {
        cout << 2 << endl << s[0] << ' ';
        for (int i = 1; i < n; ++i) {
            cout << s[i];
        }
    }
 
}
