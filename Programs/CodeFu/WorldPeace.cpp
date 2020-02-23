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

const int N = 25;

class WorldPeace
{
	public:
	int n;
	vector<int> adj[N];
	int adjm[N];
	bitset<1<<N> visited;
	string TOSTRING(int x) {
		stringstream ss;
		ss << x;
		return ss.str();
	}
	string minimumMeetings(int countries, vector<int> X, vector<int> Y)
	{
		n = countries;
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
			adjm[i] = (1 << i);
		}
		for (int i = 0; i < (int)X.size(); ++i) {
			int a = X[i], b = Y[i];
			adj[a].push_back(b);
			adj[b].push_back(a);
			adjm[a] |= (1 << b);
			adjm[b] |= (1 << a);
		}
		queue<pii> q;
		for (int i = 0; i < n; ++i) {
			visited[1<<i] = true;
			q.emplace(1<<i, 0);
		}
		while (!q.empty()) {
			int m = q.front().first, d = q.front().second;
			q.pop();
			if (m == (1<<n)-1) {
				return TOSTRING(d);
			}
			for (int i = 0; i < n; ++i) {
				if (m & (1 << i)) {
					int m1 = m | adjm[i];
					if (!visited[m1]) {
						visited[m1] = true;
						q.emplace(m1, d+1);
					}
				}
			}
		}
		return "Impossible";
	}
};
