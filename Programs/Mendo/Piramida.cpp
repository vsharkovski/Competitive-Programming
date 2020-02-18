#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 10050;
const int A = 26;

const int mod = 1e9 + 7;
const int prime = 1103;
int primepow[A];

inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	return x;
}

inline int mult(int x, int y) {
	return (ll)x * y % mod;
}

struct Data {
	int cnt[A];
	int hsh;
	int idx;
	void init(string s) {
		memset(cnt, 0, sizeof(cnt));
		for (char& ch : s) {
			++cnt[(int)(ch-'A')];
		}
		hsh = gethash();
	}
	int gethash() {
		int res = 0;
		for (int i = 0; i < A; ++i) {
			res = add(res, mult(primepow[i], cnt[i]+1));
		}
		return res;
	}
	bool operator < (const Data& o) const {
		return hsh < o.hsh;
	}
};

int n;
string str[N];
Data words[N];
vector<int> adj[N];
int res[N], choice[N];

int dfs(int i) {
	if (res[i] != -1) return res[i];
	res[i] = 1;
	choice[i] = -1;
	for (int j : adj[i]) {
		int res2 = 1 + dfs(j);
		if (res2 > res[i]) {
			res[i] = res2;
			choice[i] = j;
		}
	}
	return res[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	primepow[0] = 1;
	for (int i = 1; i < A; ++i) {
		primepow[i] = mult(primepow[i-1], prime);
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		words[i].idx = i;
		words[i].init(str[i]);
	}
	for (int i = 0; i < A; ++i) {
		str[n+i] = "";
		str[n+i] += char('A'+i);
		words[n+i].idx = n+i;
		words[n+i].init(str[n+i]);
	}
	n += 26;
	sort(words, words+n);
	for (int i = 0; i < n; ++i) {
		Data w;
		w.idx = words[i].idx;
		for (int j = 0; j < A; ++j) {
			w.cnt[j] = words[i].cnt[j];
		}
		for (int j = 0; j < A; ++j) {
			++w.cnt[j];
			w.hsh = w.gethash();
			auto it = lower_bound(words, words+n, w);
			if (it != words+n && it->hsh == w.hsh) {
				adj[w.idx].push_back(it->idx);
				//cout << w.idx <<"("<<str[w.idx]<<")->"<<it->idx<<"("<<str[it->idx]<<")\n";
			}
			--w.cnt[j];
		}
		res[i] = -1;
	}
	int u = 0;
	// single letters are n-1, n-2, ..., n-26
	for (int i = n-26; i < n; ++i) {
		if (res[i] == -1) {
			int res2 = dfs(i);
			if (res2 > res[u]) {
				u = i;
			}
		}
	}
	cout << res[u] << '\n';
	while (u != -1) {
		cout << str[u] << '\n';
		u = choice[u];
	}
}
