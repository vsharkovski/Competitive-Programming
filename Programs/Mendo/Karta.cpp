#include <bits/stdc++.h>
using namespace std;
 
inline bool isdigit(char c) {
    return c >= 48 && c <= 57; //0, 9
}
 
int main()
{
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    string a;
    getline(cin, a);
    int len = a.length();
    map<char, int> m;
    for (int i = 0; i < len; ++i) {
        if (a[i] == 'n' || a[i] == 'w' || a[i] == 's' || a[i] == 'e') {
            bool b1 = i+1 < len && isdigit(a[i+1]);
            bool b2 = i+2 < len && isdigit(a[i+2]);
            if (b1 && b2) {
                m[a[i]] += 10*(a[i+1]-'0') + (a[i+2]-'0');
            } else if (b1) {
                m[a[i]] += (a[i+1] - '0');
            }
        }
    }
    int x = abs(m['n']-m['s']), y = abs(m['w']-m['e']);
    double dist = sqrt(x*x + y*y);
    cout << setprecision(2) << fixed << dist;
}
