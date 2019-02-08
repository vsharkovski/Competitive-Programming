#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;


/*
LANG: C++
PROG: ride
*/

int getnum(string &s) {
    int res = 1;
    for (int i = 0; i < s.length(); ++i) {
        res *= s[i] - 'A' + 1;
        res %= 47;
    }
    return res;
}

void Main() {
    #ifndef _DEBUG
        freopen("ride.in", "r", stdin);
        freopen("ride.out", "w", stdout);
    #endif
    string s1, s2;
    cin >> s1 >> s2;
    if (getnum(s1) == getnum(s2)) {
        cout << "GO\n";
    } else {
        cout << "STAY\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
