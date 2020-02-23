#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <bitset>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

class SandCastle
{
	public:
	int howMuchWater(vector<int> heights)
	{
		int n = heights.size();
		const int maxh = 1010;
		int maxhreal = 0;
		vector<vector<int>> grid(maxh, vector<int>(n, 0));
		for (int i = 0; i < n; ++i) {
			maxhreal = max(maxhreal, heights[i]);
			for (int j = 1; j <= heights[i]; ++j) {
				grid[j][i] = 1;
			}
		}
		int ans = 0;
		for (int h = 1; h < maxh; ++h) {
			for (int i = 0; i < n; ++i) {
				if (grid[h][i] == 1) continue;
				int j = i;
				while (j < n && grid[h][j] == 0) {
					++j;
				}
				if (i > 0 && j < n) {
					ans += j-i;
				}
				i = j-1;
			}
		}
		return ans;
	}
};
