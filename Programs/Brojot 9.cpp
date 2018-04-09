#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef long long ll;
 
ll cnt(vi &v) {
    ll scf = 0;
    for (int i = 0; i < v.size(); ++i) scf += v[i];
    return scf;
}
 
vi ll2vi(ll n) {
    vi v;
    while (n != 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    return v;
}
 
void vpv(vi &v, vi &v2) {
//    for (int z : v) cout << z;
//    cout << " ::::\n";
    for (int i = 0; i < v2.size(); ++i) {
        v[i] += v2[i];
        if (v[i] > 10) {
            v[i] -= 10;
            v[i+1] += 1;
        }
//        printf("v[%i]:%i v2[%i]:%i\n", i, v[i], i, v2[i]);
//        for (int z : v) cout << z;
//        cout << "\n\n";
    }
}
 
int main() {
    string n; cin >> n;
    ll c = 0;
    ll scforig = 0;
    vi scf(100, 0);
    for (int i = n.length()-1, j = 0; i >= 0; --i, ++j) {
        int x = n.at(i) - '0';
        scforig += x;
        scf[j] = x;
    }
    vi scforigv = ll2vi(scforig);
//    printf("scforig:%i\n", scforig);
    while (cnt(scf) % 9 != 0) {
        vpv(scf, scforigv);
        c++;
    }
    cout << c;
}