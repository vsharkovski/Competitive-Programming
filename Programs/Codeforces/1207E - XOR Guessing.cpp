#include <bits/stdc++.h>
using namespace std;

int ask(vector<int>& v) {
    cout << '?';
    for (int x : v) {
        cout << ' ' << x;
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<int> a, b;
    for (int i = 1; i <= 100; ++i) {
        a.push_back(i);
        b.push_back(i << 7);
    }
    int on7 = (1 << 7) - 1;
    int x = ask(a), y = ask(b);
    // x has last 7 bits of answer
    // y has first 7 bits of answer
    int z = (x & (on7 << 7)) | (y & on7);
    cout << "! " << z << endl;
}
