// Problem : D. New Year and Conference
// Contest : Hello 2020
// URL : https://codeforces.com/contest/1284/problem/D
// Memory Limit : 1024.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100010;
const int M = 400010;

int numuniques;
vector<int> uniques;
unordered_map<int, int> newid;

int n, m;
int al[N], ar[N], bl[N], br[N];
vector<int> astart[M], aend[M];

bool intersect(int l1, int r1, int l2, int r2) {
	return max(l1, l2) <= min(r1, r2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> al[i] >> ar[i] >> bl[i] >> br[i];
		uniques.push_back(al[i]);
		uniques.push_back(ar[i]);
		uniques.push_back(bl[i]);
		uniques.push_back(br[i]);
	}
	sort(uniques.begin(), uniques.end());
	numuniques = 0;
	for (int i = 0; i < (int)uniques.size(); ++i) {
		if (i == 0 || uniques[i] != uniques[i-1]) {
			newid[uniques[i]] = numuniques;
			++numuniques;
		}
	}
	m = numuniques;
	for (int i = 1; i <= n; ++i) {
		al[i] = newid[al[i]];
		ar[i] = newid[ar[i]];
		bl[i] = newid[bl[i]];
		br[i] = newid[br[i]];
	}
	for (int I = 0; I < 2; ++I) {
		for (int x = 0; x < m; ++x) {
			astart[x].clear();
			aend[x].clear();
		}
		for (int i = 1; i <= n; ++i) {
			swap(al[i], bl[i]);
			swap(ar[i], br[i]);
			astart[al[i]].push_back(i);
			aend[ar[i]].push_back(i);
		}
		multiset<int, greater<int>> ls;
		multiset<int, less<int>> rs;
		for (int x = 0; x < m; ++x) {
			for (int i : astart[x]) {
				if (ls.empty()) {
					ls.insert(bl[i]);
					rs.insert(br[i]);
					continue;
				}
				int l = *ls.begin();
				int r = *rs.begin();
				if (!intersect(bl[i], br[i], l, r)) {
					cout << "NO\n";
					return 0;
				}
				ls.insert(bl[i]);
				rs.insert(br[i]);
			}
			for (int i : aend[x]) {
				ls.erase(ls.find(bl[i]));
				rs.erase(rs.find(br[i]));
			}
		}
	}
	cout << "YES\n";
}
