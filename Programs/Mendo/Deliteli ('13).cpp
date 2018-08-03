#include <bits/stdc++.h>
using namespace std;
 
#define all(cont) cont.begin(), cont.end()
 
inline int stoi(string &s) {
    stringstream ss(s);
    int i;
    ss >> i;
    return i;
}
 
int main() {
    int ncif;
    cin >> ncif;
    string cif = "";
    for (int i = 0; i < ncif; ++i) {
        char x;
        cin >> x;
        cif += x;
    }
    sort(all(cif));
 
    int mind = -1;
    map<int, vector<int>> m;
    do {
        int n = stoi(cif);
        int d = 0;
        for (int i = 1; i <= sqrt(n)+1; ++i) {
            if (n % i == 0) {
                if (n/i == i) d++;
                else d += 2;
            }
        }
        m[d].push_back(n);
        if (mind == -1 || d < mind) mind = d;
    } while (next_permutation(all(cif)));
 
    cout << mind << endl;
    sort(all(m[mind]));
    for (int x : m[mind]) cout << x << " ";
}
