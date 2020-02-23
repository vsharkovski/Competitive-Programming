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

class Reward
{
    public:
    int chooseReward(int A, int B, int C, int N, int K)
	{
		vector<ll> p(2*N);
		for (int i = 0; i < N; ++i) {
			p[i] = (A*i + B) % C;
		}
		for (int i = N; i < 2*N; ++i) {
			p[i] = p[i-N];
		}
		for (int i = 1; i < 2*N; ++i) {
			p[i] += p[i-1];
		}
		ll ans = 0;
		for (int i = K-1; i < 2*N; ++i) {
			ll res = p[i];
			if (i >= K) res -= p[i-K];
			ans = max(ans, res);
		}
		return ans;
	}
};
