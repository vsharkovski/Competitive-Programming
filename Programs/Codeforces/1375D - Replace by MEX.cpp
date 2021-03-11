
// Problem : D. Replace by MEX
// Contest : Codeforces - Codeforces Global Round 9
// URL : https://codeforces.com/contest/1375/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int n;
int a[1010];
int cnt[1010];
bool vis[1010];
vector<int> operations;

int getmex() {
	for (int i = 0; i <= n; ++i) {
		if (cnt[i] == 0) {
			return i;
		}
	}
	return n+1;
}

void replace(int i, int mex) {
	operations.push_back(i);
	if (mex == -1) mex = getmex();
	--cnt[a[i]];
	a[i] = mex;
	++cnt[mex];
	//cout << i << ": "; for (int i = 0; i < n; ++i){cout<<a[i]<<' ';}cout<<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		operations.clear();
		cin >> n;
		for (int i = 0; i <= n; ++i) {
			cnt[i] = 0;
			vis[i] = false;
		}
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++cnt[a[i]];
		}
		//cout << "A: "; for (int i = 0; i < n; ++i) {cout<<a[i]<<' ';}cout<<'\n'; 
		for (int i = 0; i < n; ++i) {
			int mex = getmex();
			if (mex >= n || a[mex] == mex) {
				break;
			}
			replace(mex, mex);
		}
		// now it is either identity perm. or a perm. where no element is in proper place
		bool identity = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] != i) {
				identity = false;
				break;
			}
		}
		if (!identity) {
			for (int i = 0; i < n; ++i) {
				if (vis[i] || a[i] == i) continue;
				vis[i] = true;
				int j = a[i];
				a[i] = n;
				operations.push_back(i);
				while (j != i) {
					vis[j] = true;
					int k = a[j];
					a[j] = j;
					operations.push_back(j);
					j = k;
				}
				a[i] = i;
				operations.push_back(i);
			}
		}
		//cout<<"(n="<<n<<") ";
		cout << operations.size() << '\n';
		for (int i : operations) {
			cout << i+1 << ' ';
		}
		cout << '\n';
	}
}
