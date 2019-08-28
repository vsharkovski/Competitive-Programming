#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    bool perfect = true;
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i] == '1') {
            perfect = false;
            break;
        }
    }
    int num0 = s.size() - 1;
    perfect &= num0 % 2 == 0;
    if (perfect) {
        cout << num0/2 << endl;
    } else {
        cout << num0/2 + 1 << endl;
    }
}
