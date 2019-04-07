#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



class EndlessRun
{
  public:
    int countOnes(int n, int d, int position)
    {
        int grid[1005][1005] = {};
        grid[0][position] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= d; ++j) {
                int a = 1, b = 1, c = 1;
                if (j > 1) a = grid[i-1][j-1];
                b = grid[i-1][j];
                if (j < d) c = grid[i-1][j+1];
                if (a == 1 && b == 1 && c == 1) grid[i][j] = 0;
                if (a == 1 && b == 1 && c == 0) grid[i][j] = 0;
                if (a == 1 && b == 0 && c == 1) grid[i][j] = 0;
                if (a == 1 && b == 0 && c == 0) grid[i][j] = 1;
                if (a == 0 && b == 1 && c == 1) grid[i][j] = 1;
                if (a == 0 && b == 1 && c == 0) grid[i][j] = 1;
                if (a == 0 && b == 0 && c == 1) grid[i][j] = 1;
                if (a == 0 && b == 0 && c == 0) grid[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = 1; i <= d; ++i) {
            ans += grid[n][i];
        }
        return ans;
    }
};
