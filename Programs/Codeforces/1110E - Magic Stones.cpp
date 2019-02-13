#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




void printv(string s, vector<int>& v) {
    cout << setw(2) << s << ": ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

void Main() {
    int n;
    cin >> n;
    vector<int> c(n), t(n), d1(n, 0), d2(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 1; i < n; ++i) {
        d1[i] = c[i] - c[i-1];
        d2[i] = t[i] - t[i-1];
    }
//    printv("c", c);
//    printv("t", t);
//    printv("d1", d1);
//    printv("d2", d2);
    if (c[0] != t[0]) {
        cout << "No\n";
        return;
    }
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
//    printv("d1", d1);
//    printv("d2", d2);
    for (int i = 0; i < n; ++i) {
        if (d1[i] != d2[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
