#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 64;

int numtrees, mintotalheight;
int height[maxn], growth[maxn];

int numdays;
int dp[maxn][maxn];
// dp[i][j] = minimum total height for trees
// if at tree i, at day j

int dfs(int position, int day) {
    int& res = dp[position][day];
    if (res == -1) {
        if (position == numtrees) {
            res = 0;
        } else {
            res = height[position] + (numdays)*growth[position] + dfs(position+1, day);
            if (day > 0) {
                res = min(res, (numdays-day)*growth[position] + dfs(position+1, day-1));
            }
        }
    }
    return res;
}

void Main() {
    cin >> numtrees >> mintotalheight;
    vector<pair<int, int>> trees(numtrees);
    for (int i = 0; i < numtrees; ++i) {
        cin >> trees[i].first >> trees[i].second;
    }
    sort(trees.begin(), trees.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < numtrees; ++i) {
        height[i] = trees[i].first;
        growth[i] = trees[i].second;
    }
    for (numdays = 1; numdays <= numtrees; ++numdays) {
        memset(dp, -1, sizeof(dp));
        int totalheight = dfs(0, numdays);
        if (totalheight < mintotalheight) {
            cout << numdays << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
