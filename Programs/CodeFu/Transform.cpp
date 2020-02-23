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

class Transform {
    public:
    int minTransformations(vector<int> a, vector<int> b)
	{
		int n = a.size();
		int res = 1e9;
		for (int Q = 0; Q < n; ++Q) {
			int ans = Q;
			for (int i = 0 ; i < n; ++i) {
				ans += abs(a[i] - b[i]);
			}
			res = min(res, ans);
			b.push_back(b[0]);
			b.erase(b.begin());
		}
		return res;
	}
};
