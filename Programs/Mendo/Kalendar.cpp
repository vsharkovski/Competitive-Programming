#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int m, g; cin >> m >> g;
    set<int> d31 = {1, 3, 5, 7, 8, 10, 12};
    set<int> d30 = {4, 6, 9, 11};
    if (d31.find(m) != d31.end()) {
        cout << 31;
    }
    else if (d30.find(m) != d30.end()) {
        cout << 30;
    }
    else {//m=2
        if (g % 400 == 0 || (g % 4 == 0 && g % 100 != 0)) {
            cout << 29;
        }
        else {
            cout << 28;
        }
    }
}
