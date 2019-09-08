#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100010;
const int maxk = 17;

int n, q, root;

vector<int> children[maxn];
int depth[maxn];
int sbmin[maxn];
int P[maxn][maxk];

int numdone;
int order[maxn];
bool is_available[maxn];

struct Comp {
	bool operator () (const int a, const int b) const {
		return order[a] < order[b];
	}
};
set<int, Comp> available;

void dfs1(int u) {
	sbmin[u] = u;
	for (int v : children[u]) {
		depth[v] = depth[u] + 1;
		dfs1(v);
		sbmin[u] = min(sbmin[u], sbmin[v]);
	}
}

void dfs2(int u) {
	sort(children[u].begin(), children[u].end(), [&] (int x, int y) {
		return sbmin[x] < sbmin[y];
	});
	for (int v : children[u]) {
		dfs2(v);
	}
	order[u] = ++numdone;
	available.insert(u);
	is_available[u] = true;
}

int add_ball() {
	auto it = available.begin();
	int u = *it;
	available.erase(it);
	is_available[u] = false;
	return u;
}

int remove_ball(int u) {
	int ud = depth[u];
	for (int j = maxk-1; j >= 0; --j) {
		if (P[u][j] != -1 && !is_available[P[u][j]]) {
			u = P[u][j];
		} 
	}
	available.insert(u);
	is_available[u] = true;
	return ud - depth[u];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
		cin >> P[i][0];
        if (P[i][0] == 0) {
            root = i;
            P[i][0] = -1;
        } else {
            children[P[i][0]].push_back(i);
        }
    }
    depth[root] = 0;
    sbmin[root] = root;
    dfs1(root);
	numdone = 0;
    dfs2(root);
    for (int j = 1; j < maxk; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (P[i][j-1] != -1) {
				P[i][j] = P[P[i][j-1]][j-1];
			} else {
				P[i][j] = -1;
			}
		}
	}
    while (q--) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            int res;
            while (k--) {
                res = add_ball();
            }
            cout << res << endl;
        } else {
			int res = remove_ball(k);
			cout << res << endl;
        }
    }
}
