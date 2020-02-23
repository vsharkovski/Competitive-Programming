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

const int N = 15;
const int inf = 1e9;

class Sheepdog
{
    public:
	int R, C;
	bool blocked[N][N];
	int diffr[8] = {0, -1, 0, 1, -1, -1, 1, 1};
	int diffc[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
	inline bool inside(int r, int c) {
		return r >= 0 && r < R && c >= 0 && c < C;
	}
	inline int euclidsq(int r1, int c1, int r2, int c2) {
		return (r1-r2)*(r1-r2) + (c1-c2)*(c1-c2);
	}
	inline bool better(int r, int c, int r1, int c1, int r2, int c2) {
		return euclidsq(r, c, r1, c1) > euclidsq(r, c, r2, c2);
	}
	int dist[N][N][N][N];
    int minTime(vector<string> field)
	{
		R = field.size();
		C = field[0].size();
		int sr, sc, dr, dc;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (field[i][j] == 'S') {
					sr = i, sc = j;
					field[i][j] = '.';
				} else if (field[i][j] == 'D') {
					dr = i, dc = j;
					field[i][j] = '.';
				} else if (field[i][j] == '#') {
					blocked[i][j] = true;
				} else {
					blocked[i][j] = false;
				}
			}
		}
		for (int sr = 0; sr < R; ++sr) {
			for (int sc = 0; sc < C; ++sc) {
				for (int dr = 0; dr < R; ++dr) {
					for (int dc = 0; dc < C; ++dc) {
						dist[sr][sc][dr][dc] = inf;
					}
				}
			}
		}
		queue<pair<pii, pii>> q;
		q.emplace(pii(sr, sc), pii(dr, dc));
		dist[sr][sc][dr][dc] = 0;
		while (!q.empty()) {
			pair<pii, pii> topstate = q.front();
			q.pop();
			int sr = topstate.first.first;
			int sc = topstate.first.second;
			int dr = topstate.second.first;
			int dc = topstate.second.second;
			int& dst = dist[sr][sc][dr][dc];
			if (dr == sr && dc == sc) {
				return dst;
			}
			for (int z = 0; z < 8; ++z) {
				int dr1 = dr + diffr[z];
				int dc1 = dc + diffc[z];
				if (!inside(dr1, dc1) || blocked[dr1][dc1]) continue;
				if (dr1 == sr && dc1 == sc) {
					return dst + 1;
				}
				int sr1 = sr, sc1 = sc;
				for (int x = 0; x < 4; ++x) {
					int sr2 = sr + diffr[x];
					int sc2 = sc + diffc[x];
					if (!inside(sr2, sc2) || blocked[sr2][sc2]) continue;
					if (better(dr1, dc1, sr2, sc2, sr1, sc1)) {
						sr1 = sr2;
						sc1 = sc2;
					}
				}
				int& dstnxt = dist[sr1][sc1][dr1][dc1];
				if (dstnxt == inf) {
					dstnxt = dst + 1;
					q.emplace(pii(sr1, sc1), pii(dr1, dc1));
				}
			}
		}
		return -1;
	}
};
