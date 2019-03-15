#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




const ll unset = -1e18;
const ll inf = 1e15;


int N;
ll a[16][16];
ll total[(1<<16) + 5];
ll dp[(1<<16) + 5];

ll dfs(int msk) {
    ll& res = dp[msk];
    if (res == unset) {
        if (msk + 1 == (1 << N)) {
            res = 0;
        } else {
            res = -inf;
            vector<int> available;
//            cout << "msk=" << bitset<3>(msk) << " ; available:[";
            for (int i = 0; i < N; ++i) {
                if (!(msk & (1 << i))) {
                    available.push_back(i);
//                    cout << i << ' ';
                }
            }
//            cout << "]\n";
            int cnt = available.size();
            for (int opt = 1; opt < (1 << cnt); ++opt) {
                int msk1 = 0;
                for (int i = 0; i < cnt; ++i) {
                    if (opt & (1 << i)) {
                        msk1 |= (1 << available[i]);
                    }
                }
                ll score = total[msk1] + dfs(msk | msk1);
                res = max(res, score);
            }
        }
//        cout << "dp[" << bitset<3>(msk) << "] = " << res << "\n";
    }
    return res;
}


void Main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    for (int msk = 0; msk < (1 << N); ++msk) {
        dp[msk] = unset;
        ll score = 0;
        for (int i = 0; i < N; ++i) {
            if (!(msk & (1 << i))) continue;
            for (int j = i+1; j < N; ++j) {
                if (!(msk & (1 << j))) continue;
                score += a[i][j];
            }
        }
        total[msk] = score;
    }
    ll ans = dfs(0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef _DEBUG
    #endif
    Main();
    return 0;
}
