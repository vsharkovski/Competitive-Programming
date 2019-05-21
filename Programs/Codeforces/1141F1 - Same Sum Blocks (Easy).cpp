#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int maxn = 55;

int n;
int a[maxn];

int sum;
int dp[maxn]; // max number of blocks with sum=sum, if first block starts here
int opt[maxn]; // the starting position for the next block

int dfs(int i) {
    int& res = dp[i];
    if (res != -1) return res;
    if (i == n) return res = 0;
    res = 0;
    opt[i] = n;
    int sum2 = 0;
    for (int j = i; j < n; ++j) {
        sum2 += a[j];
        if (sum2 == sum) {
            res = 1;
            opt[i] = n;
            for (int k = j+1; k <= n; ++k) {
                int res2 = 1 + dfs(k);
                if (res2 > res) {
                    res = res2;
                    opt[i] = k;
                }
            }
            break;
        }
    }
    return res;
}

int main() {
//    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pii> blocks;
    for (int l = 0; l < n; ++l) {
        sum = 0;
        for (int r = l; r < n; ++r) {
            sum += a[r];
            fill(dp, dp+n+1, -1);
            fill(opt, opt+n+1, n);
            int cnt_best = 0, best_idx = -1;
            for (int i = r+1; i <= n; ++i) {
                int cnt_here = 1 + dfs(i);
                if (cnt_here > cnt_best) {
                    cnt_best = cnt_here;
                    best_idx = i;
                }
            }
            if (cnt_best > blocks.size()) {
                blocks.clear();
//                cout << "new best:\n";
//                cout << "l=" << l << " r=" << r << " best_idx=" << best_idx << "\n";
//                cout << "cnt=" << cnt_best << "\n";
                blocks.emplace_back(l, r);
                for (int i = best_idx; i < n; i = opt[i]) {
                    int sum2 = 0;
                    for (int j = i; j < n; ++j) {
                        sum2 += a[j];
                        if (sum2 == sum) {
                            blocks.emplace_back(i, j);
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << blocks.size() << '\n';
    for (auto& p : blocks) {
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
}
