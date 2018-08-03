#include <bits/stdc++.h>
using namespace std;
 
const int Q = '?' - '0';
bool OK = 0;
 
void test(vector<int> &a, int l, int i, int x) {
    if (OK) return;
    for (int j = i+1; j < i+x; ++j) {
        if ((j == l) || (a[j] != x && a[j] != Q)) {
            return;
        }
    }
    OK = true;
}
 
int main()
{
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int l;
    cin >> l;
    vector<int> a(l);
    for (int i = 0; i < l; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 0; i < l; ++i) {
        if (a[i] == Q) {
            test(a, l, i, 2);
            test(a, l, i, 3);
            test(a, l, i, 5);
            test(a, l, i, 7);
        } else {
            test(a, l, i, a[i]);
        }
    }
    if (OK) cout << "cool";
    else cout << "boring";
}
