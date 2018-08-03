#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int l, r; cin >> l >> r;
    int c = 0;
    for (int i = l; i <= r; ++i) {
        stringstream iss;
        iss << i;
        string n = iss.str();
        int prev = n.at(0) - '0';
        bool valid = true;
        for (int j = 1; j < n.length(); ++j) {
            if ((n.at(j) - '0') <= prev) {
                valid = false;
                break;
            }
            prev = n.at(j) - '0';
        }
        if (valid) c++;
    }
    cout << c;
}
