#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
 
    vector<int> L(n+1), R(n+1), U(n+1), D(n+1);
    vector<set<int>> m(n+1), k(n+1);
    vector<bool> me(n+1, false), ke(n+1, false);
 
    for (int i = 1; i <= n; ++i) {
        cin >> L[i];
        if (L[i] == -1) {
            me[i] = true;
        } else {
            m[i].insert(L[i]+1);
            k[L[i]+1].insert(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> R[i];
        if (R[i] == -1) {
            me[i] = true;
        } else {
            m[i].insert(n-R[i]);
            k[n-R[i]].insert(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> U[i];
        if (U[i] == -1) {
            ke[i] = true;
        } else {
            m[U[i]+1].insert(i);
            k[i].insert(U[i]+1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> D[i];
        if (D[i] == -1) {
            ke[i] = true;
        } else {
            m[n-D[i]].insert(i);
            k[i].insert(n-D[i]);
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        if (me[i] && !m[i].empty()) {
            cout << "NE"; return 0;
        }
        if (ke[i] && !k[i].empty()) {
            cout << "NE"; return 0;
        }
        if (!me[i] && *m[i].begin() != L[i]+1) {
            cout << "NE"; return 0;
        }
        if (!me[i] && *prev(m[i].end()) != n-R[i]) {
            cout << "NE"; return 0;
        }
        if (!ke[i] && *k[i].begin() != U[i]+1) {
            cout << "NE"; return 0;
        }
        if (!ke[i] && *prev(k[i].end()) != n-D[i]) {
            cout << "NE"; return 0;
        }
    }
 
    cout << "DA" << endl;
}
