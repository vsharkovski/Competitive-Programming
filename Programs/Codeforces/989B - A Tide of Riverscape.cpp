#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;

    for (int i = 0; i < p; ++i) {
        vector<int> v;
        for (int j = i+p; j < n; j += p) {
            char a = s[j], b = s[j-p];
            if (a == '0' && b == '1') {
                for (int k = 0; k < n; ++k) {
                    if (s[k] == '.') cout << 1;
                    else cout << s[k];
                }
                return 0;
            }
            if (a == '1' && b == '0') {
                for (int k = 0; k < n; ++k) {
                    if (s[k] == '.') cout << 1;
                    else cout << s[k];
                }
                return 0;
            }
            if (a == '.' && b == '.') {
                for (int k = 0; k < n; ++k) {
                    if (k == j) cout << 1;
                    else if (k == j-p) cout << 0;
                    else if (s[k] == '.') cout << 1;
                    else cout << s[k];
                }
                return 0;
            }
            if (a == '1' && b == '.') {
                for (int k = 0; k < n; ++k) {
                    if (k == j-p) cout << 0;
                    else if (s[k] == '.') cout << 1;
                    else cout << s[k];
                }
                return 0;
            }
            if (a == '0' && b == '.') {
                for (int k = 0; k < n; ++k) {
                    if (k == j-p) cout << 1;
                    else if (s[k] == '.') cout << 1;
                    else cout << s[k];
                }
                return 0;
            }
            if (a == '.' && b == '1') {
                for (int k = 0; k < n; ++k) {
                    if (k == j) cout << 0;
                    else if (s[k] == '.') cout << 1;
                    else cout << s[k];
                }
                return 0;
            }
            if (a == '.' && b == '0') {
                for (int k = 0; k < n; ++k) {
                    if (k == j) cout << 1;
                    else if (s[k] == '.') cout << 1;
                    else cout << s[k];
                }
                return 0;
            }
        }
    }

    cout << "No";

}
