#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
#include <utility>
using namespace std;
//#include <iostream>


class UberApp
{
public:
    int n, m;
    vector<vector<int> > dist;
    vector<vector<bool> > blocked;
    // maximum cardinality bipartite matching
    vector<int> match;
    vector<bool> visited;
    bool augmented_path(int L) {
        if (visited[L]) return false;
        visited[L] = true;
        for (int R = 0; R < m; ++R) {
            if (blocked[L][R]) continue;
            if (match[R] == -1 || augmented_path(match[R])) {
                match[R] = L;
                return true;
            }
        }
        return false;
    }
    int bipartite() {
        match.assign(m, -1);
        int cnt = 0;
        for (int L = 0; L < n; ++L) {
            visited.assign(n, false);
            if (augmented_path(L)) {
                // successfully matched
                ++cnt;
            }
        }
        return cnt;
    }
    //
    bool possible(int max_dist) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                blocked[i][j] = (dist[i][j] > max_dist);
            }
        }
        int cnt = bipartite();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                blocked[i][j] = false;
            }
        }
        return cnt == n;
    }
    int findRides(vector<int> passenger_x, vector<int> passenger_y, vector<int> driver_x, vector<int> driver_y)
    {
        n = passenger_x.size();
        m = driver_x.size();
        dist.assign(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dist[i][j] = abs(passenger_x[i]-driver_x[j]) + abs(passenger_y[i]-driver_y[j]);
            }
        }
        blocked.assign(n, vector<bool>(m, false));
        int L = 0, R = 1e8, mid, res = R;
        while (L <= R) {
            mid = (L + R) / 2;
            if (possible(mid)) {
                res = mid;
                R = mid-1;
            } else {
                L = mid+1;
            }
        }
        return res;
    }
};
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    UberApp a;
//    cout << a.findRides({18,62,31,12,85,62,31,36,25,7,44},
//                        {14,80,11,44,83,70,45,26,36,67,18},
//                        {38,100,28,67,83,44,77,80,59,42,80,1,82},
//                        {85,53,58,62,33,60,28,15,58,71,11,19,93}) << endl;
//}
