#include <bits/stdc++.h>
using namespace std;
 
int main() {
    multiset<int> a;
    for (int i = 0; i < 7; ++i) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < 5*6; ++i) {
        int x;
        cin >> x;
        auto it = a.find(x);
        if (it != a.end()) {
            a.erase(it);
        }
    }
    if (a.empty()) {
        cout << "DA";
    } else {
        cout << "NE";
    }
}
