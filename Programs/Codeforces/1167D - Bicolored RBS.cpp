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
    int depth = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++depth;
            cout << (depth % 2);
        } else {
            cout << (depth % 2);
            --depth;
        }
    }
}
