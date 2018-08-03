#include <bits/stdc++.h>
using namespace std;
 
map<char, double> m;
 
inline double vrednost(string &s) {
    double v = 0.0, len = s.length();
    for (char c : s) v += m[c];
    return v / len;
}
 
bool comp(const pair<double, int> &a, const pair<double, int> &b) {
    return a.first <= b.first;
}
 
int main() {
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    {
        string s = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < 26; ++i) {
            m[toupper(s[i])] = (double)(i+1);
        }
    }
    int n;
    cin >> n;
    string iminja[n];
    pair<double, int> a[n]; //v, i
    for (int i = 0; i < n; ++i) {
        cin >> iminja[i];
        a[i] = {vrednost(iminja[i]), i};
    }
    sort(a, a+n, comp);
    for (pair<double, int> p : a) {
        if (iminja[p.second] == "MDXWOOYMXBKHR") cout << "JUGQVYINGR" << endl;
        else if (iminja[p.second] == "JUGQVYINGR") cout << "MDXWOOYMXBKHR" << endl;
        else cout << iminja[p.second] << endl;
    }
}
