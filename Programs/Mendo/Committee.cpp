#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
 
inline void test(int pp, int p, int c, int &r, int &rmax) {
    if ((pp>p && c>p) || (pp<p && c<p)) {
        ++r;
    } else {
        if (r > rmax) rmax = r;
        r = 0;
    }
}
 
int main()
{
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n, pp, p, c, rmax = 0, r = 0;
    cin >> n;
    cin >> pp >> p >> c;
    test(pp, p, c, r, rmax);
    for (int i = 3; i < n; ++i) {
        pp = p;
        p = c;
        cin >> c;
        test(pp, p, c, r, rmax);
    }
    if (r > rmax) rmax = r;
    cout << rmax;
}
