#include <bits/stdc++.h>
using namespace std;
 
bool S(const int a, const int b) {
    return a > b;
}
 
string f(vector<char> &a, vector<char> &b) {
    int as = a.size(), bs = b.size();
    bool flip = true;
    int i = 0, j = 0;
    string s = "";
    while (1) {
        if (flip) {
            if (i < as) s += a[i];
            else break;
            ++i;
        } else {
            if (j < bs) s += b[j];
            else break;
            ++j;
        }
        flip = !flip;
    }
    return s;
}
 
int main() {
    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<char> o, e;
        for (int i = 0; i < n; ++i) {
            char x;
            cin >> x;
            if ((x - '0') % 2 == 0) e.push_back(x);
            else o.push_back(x);
        }
 
        sort(o.begin(), o.end(), S);
        sort(e.begin(), e.end(), S);
//    cout << "o{ ";
//    for (char x : o) cout << x << " ";
//    cout << "} e{ ";
//    for (char x : e) cout << x << " ";
//    cout << "}\n    ";
        if (o.size() == 0) {
            cout << e[0];
        } else if (e.size() == 0) {
            cout << o[0];
        } else {
            string q = f(o, e), w = f(e, o);
            if (q.length() > w.length()) {
                cout << q;
            } else if (q.length() < w.length()) {
                cout << w;
            } else {
                if (q[0] > w[0]) {
                    cout << q;
                } else {
                    cout << w;
                }
            }
        }
        cout << endl;
    }
}