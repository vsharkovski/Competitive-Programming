#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m; cin >> n >> m;
 
    queue<int> p;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        p.push(x);
    }
    queue<int> k;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        k.push(x);
    }
 
    int spk = 0;
    int pred = p.front();
    int kut = k.front();
 
    while (!p.empty() && !k.empty()) {
        if (pred <= kut) {
            p.pop();
            k.pop();
            spk++;
            pred = p.front();
            kut = k.front();
        } else {
            while (pred > kut && !k.empty()) {
                k.pop();
                kut = k.front();
            }
        }
    }
 
    cout << spk << endl;
}