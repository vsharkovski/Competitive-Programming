#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
#include <utility>
#include <map>
#include <sstream>
using namespace std;

//#include <iostream>

typedef pair<int, int> pii;
typedef long long ll;


class Costumes {
  public:
    int n, alldone;
    vector<vector<int> > dist;
    vector<vector<int> > dp;
    int dfs(int i, int m) {
        int& res = dp[i][m];
        if (res != -1) return res;
        if (m == alldone) return res = dist[i][0];
        res = 1e9;
        for (int j = 1; j < n; ++j) {
            if ((m & (1 << (j-1))) == 0) {
                res = min(res, dist[i][j] + dfs(j, m | (1 << (j-1))));
            }
        }
        return res;
    }
    int minimumPath(vector<int> x, vector<int> y) {
        n = x.size();
        dist.assign(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }
        dp.assign(n, vector<int>(1<<(n-1), -1));
        alldone = (1 << (n-1)) - 1;
        int ans = 1e9;
        for (int j = 1; j < n; ++j) {
            ans = min(ans, dist[0][j] + dfs(j, 1<<(j-1)));
        }
        return ans;
    }
};


//
//int main() {
//    Costumes  a;
//    cout << a.minimumPath({874,117,684,989,878}, {878,929,484,798,210})<< '\n';
//}
