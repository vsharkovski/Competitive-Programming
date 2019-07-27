#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int A = 26;
const int maxn = 105;
 
int n;
int order[maxn];
string words[maxn];
char mapped[256];
bool G[A][A];
int sbsz[A];
int dfsorder[A];
vector<int> toposort;
 
bool is_prefix(string &s1, string &s2) {
	if (s1.length() > s2.length()) {
		return false;
	}
	for (int i = 0; i < (int)s1.length(); ++i) {
		if (s1[i] != s2[i]) {
			return false;
		}
	}
	return true;
}
 
void dfs1(int i) {
	sbsz[i] = 1;
	for (int j = 0; j < A; ++j) {
		if (G[i][j]) {
			if (sbsz[j] == -1) {
				dfs1(j);
			}
			sbsz[i] += sbsz[j];
		}
	}
}
 
void dfs2(int i) {
	sbsz[i] = -1;
	for (int j = 0; j < A; ++j) {
		if (G[i][j] && sbsz[j] != -1) {
			dfs2(j);
		}
	}
	toposort.push_back(i);
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> words[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> order[i];
		--order[i];
	}
	memset(G, false, sizeof(G));
	for (int oid = 0; oid+1 < n; ++oid) {
		int w1 = order[oid], w2 = order[oid+1];
		int n1 = words[w1].length(), n2 = words[w2].length();
		if (is_prefix(words[w2], words[w1])) {
			cout << "NE\n";
			return 0;
		}
		for (int i = 0; i < min(n1, n2); ++i) {
			char ch1 = words[w1][i];
			char ch2 = words[w2][i];
			if (ch1 != ch2) {
				G[ch1-'a'][ch2-'a'] = true;
				break;
			}
		}
	}
	for (int k = 0; k < A; ++k) {
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j < A; ++j) {
				G[i][j] |= G[i][k] & G[k][j];
			}
		}
	}
	for (int i = 0; i < A; ++i) {
		for (int j = 0; j < A; ++j ){
			if (G[i][j] && G[j][i]) {
				// graph has cycle
				cout << "NE\n";
				return 0;
			}
		}
	}
	memset(sbsz, -1, sizeof(sbsz));
	for (int i = 0; i < A; ++i) {
		if (sbsz[i] == -1) {
			dfs1(i);
		}
		dfsorder[i] = i;
	}
	sort(dfsorder, dfsorder+A, [&] (int i, int j) {
		return sbsz[i] > sbsz[j];
	});
	int mi = 0;
	for (int idx = 0; idx < A; ++idx) {
		int i = dfsorder[idx];
		if (sbsz[i] != -1) {
			toposort.clear();
			dfs2(i);
			reverse(toposort.begin(), toposort.end());
			for (int idx2 = 0; idx2 < toposort.size(); ++idx2) {
				int j = toposort[idx2];
				mapped[j+'a'] = mi+'a';
				++mi;
			}
		}
	}
	cout << "DA\n";
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		cout << mapped[ch];
	}
}
