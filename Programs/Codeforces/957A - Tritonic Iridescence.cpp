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
    string s;
    cin >> s;
    bool A = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[i+1] && s[i] != '?') {
            cout << "No";
            A = 0;
            break;
        }
    }
    if (A) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?' && (i == n-1 || i == 0 || s[i+1] == '?' || s[i-1] == s[i+1])) {
                cout << "Yes";
                A = 0;
                break;
            }
        }
    }
    if (A) {
        cout << "No";
    }
}
