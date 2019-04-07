#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;



static int dp[51][100001];

class ThePerfectBuild
{
    private:
    // str, agility, int
    int mult[3][3] = {
        {100, 10, 1},
        {1, 100, 10},
        {10, 1, 100},
    };
    int herotype, N;
    int price[51], points[51][3];
    int dfs(int pos, int gold) {
        int& res = dp[pos][gold];
        if (res != -1) return res;
        if (pos == N || gold == 0) return res = 0;
        int opt1 = dfs(pos+1, gold);
        if (gold >= price[pos]) {
            int pts = 0;
            for (int j = 0; j < 3; ++j) {
                pts += mult[herotype][j] * points[pos][j];
            }
            int opt2 = pts + dfs(pos, gold - price[pos]);
            opt1 = max(opt1, opt2);
        }
        return res = opt1;
    }
    public:
    int getStrongness(string heroType, int gold, int n, string items)
    {
        if (heroType[0] == 's') herotype = 0;
        else if (heroType[0] == 'a') herotype = 1;
        else herotype = 2;
        N = n;
        int idx = 0;
        int i = 0;
        while (i < items.length()) {
            int j;
            int x = 0;
            for (j = i; j < items.length() && items[j] != ';'; ++j) {
                x = 10 * x + (items[j]-'0');
            }
            ++j;
            price[idx] = x;
            for (int k = 0; k < 3; ++k) {
                x = 0;
                for (j = j; j < items.length() && items[j] != ';' && items[j] != ','; ++j) {
                    x = 10 * x + (items[j]-'0');
                }
                ++j;
                points[idx][k] = x;
            }
            i = j;
            ++idx;
        }
        memset(dp, -1, sizeof(dp));
        int ans = dfs(0, gold);
        return ans;
    }
};
