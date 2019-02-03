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




int n;
int visited[1002][1002];
pair<pi, int> previous[1002][1002];

void Main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        memset(visited, 0, sizeof(visited));
        queue<pi> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            pi top = q.front();
            q.pop();
            int rem = top.first, sum = top.second;
            if (rem == 0 && sum == n) {
                string num = "";
                while (rem != 0 || sum != 0) {
                    int pr = previous[rem][sum].first.first, ps = previous[rem][sum].first.second;
                    int d = previous[rem][sum].second;
                    num += char(d + '0');
                    rem = pr, sum = ps;
                }
                reverse(num.begin(), num.end());
                cout << num << '\n';
                break;
            }
            for (int d = (sum == 0); d <= 9; ++d) {
                int rem1 = (10*rem + d) % n;
                int sum1 = sum + d;
                if (sum1 <= n && visited[rem1][sum1] == 0) {
                    visited[rem1][sum1] = 1;
                    previous[rem1][sum1] = {pi(rem, sum), d};
                    q.emplace(rem1, sum1);
                }
            }
        }
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
