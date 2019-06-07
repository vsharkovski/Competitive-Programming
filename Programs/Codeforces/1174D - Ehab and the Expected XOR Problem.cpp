#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    /*
    a[l] ^ a[l+1] ^ ... ^ a[r] != 0 or x
    p[i] = a[1] ^ a[2] ^ ... ^ a[i]
    p[l-1] ^ p[r] != 0 or x
    x ^ y = 0 only if x = y ==> no same elements
    if a ^ b = x then a ^ c = x only if b = c
    ==> only one b for each a such that a ^ b = x
    */

    int n, x;
    cin >> n >> x;

    bool taken[1<<18] = {};
    vector<int> p;

    for (int m = 1; m < (1 << n); ++m) {
        if (m != x && taken[m ^ x] == false) {
            taken[m] = true;
            p.push_back(m);
        }
    }

    cout << p.size() << endl;
    for (int i = 0; i < p.size(); ++i) {
        int a = p[i];
        if (i > 0) a ^= p[i-1];
        cout << a << ' ';
    }

}
