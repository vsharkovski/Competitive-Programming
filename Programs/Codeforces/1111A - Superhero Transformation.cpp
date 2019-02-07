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





void Main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    if (n != m) {
        cout << "No\n";
        return;
    }
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < n; ++i) {
        bool fv = find(vowels.begin(), vowels.end(), s[i]) != vowels.end();
        bool sv = find(vowels.begin(), vowels.end(), t[i]) != vowels.end();
        if (fv != sv) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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
