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
    int n, m;
    double k;
    cin >> n >> k >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double ans = 0;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    for (int i = 0; i < n; ++i) {
        double people = n - i;
        double ops = max(0, m - i);
        double sumcurr = sum + min(people * k, ops);
        double avg = sumcurr / people;
        ans = max(ans, avg);
        if (m > i && i < n) {
            sum -= a[i];
        } else {
            break;
        }
    }
    cout << setprecision(15) << fixed << ans << '\n';
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
