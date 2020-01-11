// Problem : E. Delete a Segment
// Contest : Codeforces Round #613 (Div. 2)
// URL : https://codeforces.com/contest/1285/problem/E
// Memory Limit : 256.000000 MB 
// Time Limit : 4000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 200010;
const int M = 4*N;

int n, m;
int l[N], r[N];
int diff[M];
int arr[M];
int diff2[M];
vector<int> segstart[M];

struct fenwick {
	int n;
	vector<int> tree;
	fenwick(int _n) {
		n = _n;
		tree.assign(n+1, 0);
	}
	void update(int pos, int val) {
		while (pos <= n) {
			tree[pos] += val;
			pos += pos & -pos;
		}
	}
	int sum(int pos) {
		int res = 0;
		while (pos >= 1) {
			res += tree[pos];
			pos -= pos & -pos;
		}
		return res;
	}
	int sum(int l, int r) {
		if (r < l) return 0;
		return sum(r) - sum(l-1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> numbers;
		for (int i = 1; i <= n; ++i) {
			cin >> l[i] >> r[i];
			numbers.push_back(2*l[i]);
			numbers.push_back(2*r[i]);
			numbers.push_back(2*l[i]-1);
			numbers.push_back(2*r[i]+1);
		}
		sort(numbers.begin(), numbers.end());
		int numuniq = 0;
		map<int, int> newid;
		for (int i = 0; i < (int)numbers.size(); ++i) {
			if (i == 0 || numbers[i] != numbers[i-1]) {
				newid[numbers[i]] = numuniq;
				++numuniq;
			}
		}
		m = numuniq;
		fenwick tree2(m);
		for (int i = 0; i < m; ++i) {
			diff[i] = 0;
			diff2[i] = 0;
			segstart[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			l[i] = newid[2*l[i]];
			r[i] = newid[2*r[i]];
			++diff[l[i]];
			--diff[r[i]+1];
			segstart[l[i]].push_back(i);
			tree2.update(l[i], 1);
		}
		for (int i = 0; i < m; ++i) {
			arr[i] = arr[i-1] + diff[i];
		}
		//cout << endl;
		fenwick tree(m);
		for (int i = 0; i < m; ++i) {
			if (arr[i] == 1) {
				int j = i;
				while (j < m && arr[j] == 1) {
					++j;
				}
				if (0 < i && j < m && arr[i-1] > 1 && arr[j] > 1) {
					diff2[i] += 1;
					diff2[j] -= 1;
					tree.update(i, 1);
				}
				i = j-1;
			}
		}
		int nin0 = 0;
		for (int i = 0; i < m; ++i) {
			if (arr[i] > 0) {
				int j = i;
				while (j < m && arr[j] > 0) {
					++j;
				}
				++nin0;
				i = j-1;
			}
		}
		int ans = 0;
		int numactive = 0;
		for (int ll = 0; ll < m; ++ll) {
			numactive += diff2[ll];
			for (int i : segstart[ll]) {
				int rr = r[i];
				int reached = tree.sum(ll+1, rr);
				int totreached = numactive + reached; // segments of x11..11x removed
				bool isalone = tree2.sum(ll, rr) == 1;
				ans = max(ans, nin0 + totreached - isalone);
			}
		}
		cout << ans << endl;
	}
}
