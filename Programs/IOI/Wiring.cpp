#include "wiring.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e18;

inline void min_self(ll& a, ll b) {
    a = min(a, b);
}

ll min_total_length(vector<int> r, vector<int> b) {
    vector<pii> data;
    for (int i = 0, j = 0; i < (int)r.size() || j < (int)b.size();) {
        if (i == r.size()) {
            data.emplace_back(b[j++], 1);
        } else if (j == b.size()) {
            data.emplace_back(r[i++], 0);
        } else if (r[i] <= b[j]) {
            data.emplace_back(r[i++], 0);
        } else {
            data.emplace_back(b[j++], 1);
        }
    }
    vector<vector<ll>> pos, pre, dp;
    for (int i = 0; i < (int)data.size();) {
        vector<ll> cpos, cpre;
        int j = i;
        while (j < (int)data.size() && data[j].second == data[i].second) {
            cpos.push_back(data[j].first);
            cpre.push_back(cpre.empty() ? data[j].first : cpre.back() + data[j].first);
            ++j;
        }
        pos.push_back(cpos);
        pre.push_back(cpre);
        dp.push_back(vector<ll>(cpos.size()+1, inf));
        i = j;
    }
    // dp[i][j] = min cost for blocks 0 to i, if at j-th item in i-th group
    // (already processed items 0 to j-1)
    int n = dp.size();
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int sz = pos[i].size();
        for (int j = 0; j < sz; ++j) {
            if (i > 0) {
                // connect current to last of previous block
                min_self(dp[i][j+1], dp[i][j] + pos[i][j] - pos[i-1].back());
            }
            if (i+1 < n) {
                // connect current to first of next block
                min_self(dp[i][j+1], dp[i][j] + pos[i+1].front() - pos[i][j]);
                if (sz-j <= pos[i+1].size()) {
                    // connect all remaining of this block to those of next block
                    // continue from there
                    // note that the individual costs can be calculated quickly
                    // with prefix sums
                    ll totalwiringcost = pre[i+1][sz-j-1] - pre[i][sz-1];
                    if (j > 0) totalwiringcost += pre[i][j-1];
                    min_self(dp[i+1][sz-j], dp[i][j] + totalwiringcost);
                }
            }
        }
        if (i+1 < n) {
            min_self(dp[i+1][0], dp[i][sz]);
        }
    }
    return dp.back().back();
}
