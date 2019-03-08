#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




int n;
bool c[5005], a[5005];
vector<int> vn, vc, va, vb;

void Main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        c[i] = ch - '0';
    }
    for (int i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        a[i] = ch - '0';
        if (c[i] == 0 && a[i] == 0) {
            vn.push_back(i+1);
        } else if (c[i] == 1 && a[i] == 0) {
            vc.push_back(i+1);
        } else if (c[i] == 0 && a[i] == 1) {
            va.push_back(i+1);
        } else {
            vb.push_back(i+1);
        }
    }
    int nn = vn.size(), nc = vc.size(), na = va.size(), nb = vb.size();
    for (int na2 = 0; na2 <= na; ++na2) {
        int na1 = na - na2;
        for (int nc2 = 0; nc2 <= nc; ++nc2) {
            int nc1 = nc - nc2;
            if ((nc + nb - na2 - nc2) % 2 != 0) continue;
            int nb2 = (nc + nb - na2 - nc2) / 2;
            int nb1 = nb - nb2;
            if ((nn + nc2 + na2 + nb2 - nc1 - na1 - nb1) % 2 != 0) continue;
            int nn1 = (nn + nc2 + na2 + nb2 - nc1 - na1 - nb1) / 2;
            int nn2 = nn - nn1;
            if (na1 < 0 || na2 < 0 || nc1 < 0 || nc2 < 0 || nb1 < 0 || nb2 < 0 || nn1 < 0 || nn2 < 0) continue;
            if (nn1 + nc1 + na1 + nb1 != nn2 + nc2 + na2 + nb2 || nn1 + nc1 + na1 + nb1 != n/2) continue;
            for (int i = 0; i < nn1; ++i) {
                cout << vn[i] << ' ';
            }
            for (int i = 0; i < nc1; ++i) {
                cout << vc[i] << ' ';
            }
            for (int i = 0; i < na1; ++i) {
                cout << va[i] << ' ';
            }
            for (int i = 0; i < nb1; ++i) {
                cout << vb[i] << ' ';
            }
            return;
        }
    }
    cout << "-1\n";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
