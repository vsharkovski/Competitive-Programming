#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXW = 5005;

struct DSU {
	int n;
	vector<int> p, rank;
	DSU(int n) : n(n) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
		rank.assign(n, 1);
	}
	inline int get(int x) {
		return p[x] == x ? x : (p[x] = get(p[x]));
	}
	inline bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y);
		if (rank[x] == rank[y]) ++rank[x];
		p[y] = x;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int n0 = n;
	vector<vector<pii>> edges(MAXW);
	vector<int> salary(n);
	vector<int> topnode(n);
	DSU dsu(n);
	vector<pii> answer;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int w;
			cin >> w;
			if (i > j) continue;
			if (i == j) salary[i] = w;
			edges[w].emplace_back(i, j);
		}
		topnode[i] = i;
	}
	for (int w = 1; w < MAXW; ++w) {
		for (auto& p : edges[w]) {
			int i = p.first, j = p.second;
			if (i == j) continue; // leaf node
			i = dsu.get(i), j = dsu.get(j);
			if (i == j) continue; // already connected
			// should connect
			dsu.unite(i, j);
			if (salary[topnode[i]] > salary[topnode[j]]) {
				swap(i, j);
			}
			if (salary[topnode[i]] < salary[topnode[j]]
				&& topnode[j] >= n0
				&& salary[topnode[j]] == w) {
				// attach topnode[i] to topnode[j]
				// (j must not be leaf)
				answer.emplace_back(topnode[i], topnode[j]);
				//cout<<"attached "<<topnode[i]+1<<" to "<<topnode[j]+1<<"\n";
				topnode[i] = topnode[j];
			} else {
				// equal salaries, make new node
				answer.emplace_back(topnode[i], n);
				answer.emplace_back(topnode[j], n);
				topnode.push_back(n); // topnode[n]
				salary.push_back(w); // salary[n]
				//cout<<"joined "<<topnode[i]+1<<" and "<<topnode[j]+1<<", top="<<n+1<<" sal="<<w<<"\n";
				topnode[i] = topnode[j] = n;
				++n;
			}
		}
	}
	cout << n << '\n';
	for (int i = 0; i < n; ++i) {
		cout << salary[i] << ' ';
	}
	cout << '\n' << n << '\n';
	for (auto& p : answer) {
		cout << p.first+1 << ' ' << p.second+1 << '\n';
	}
}
