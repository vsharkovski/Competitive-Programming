#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


const int maxn = 200010;
const int maxd = 2*maxn;

int n;
int X[maxn], Y[maxn];
vector<int> uniques;
unordered_map<int, int> compressed;

ll ans;
vector<int> layers[maxd];
int cnt[maxd]; // how many points at this x
int ft[maxd]; // x-th is 1 if cnt[x] > 0

void update(int p, int v) {
	while (p < maxd) {
		ft[p] += v;
		p += p & -p;
	}
}

int query(int p) {
	int res = 0;
	while (p > 0) {
		res += ft[p];
		p -= p & -p;
	}
	return res;
}

int query(int l, int r) {
	if (l > r) return 0;
	return query(r) - query(l-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> X[i] >> Y[i];
    	uniques.push_back(X[i]);
    	uniques.push_back(Y[i]);
    }
    sort(uniques.begin(), uniques.end());
    int uidx = 0;
    for (int i = 0; i < (int)uniques.size(); ++i) {
    	if (i == 0 || uniques[i] != uniques[i-1]) {
    		compressed[uniques[i]] = ++uidx;
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	X[i] = compressed[X[i]];
    	Y[i] = compressed[Y[i]];
    	layers[Y[i]].push_back(X[i]);
    }
  	ans = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(ft, 0, sizeof(ft));
  	for (int y = maxd-1; y >= 0; --y) {
  		sort(layers[y].begin(), layers[y].end());
  		for (int i = layers[y].size()-1; i >= 0; --i) {
  			int x = layers[y][i];
  			// bigger x, bigger or equal y
  			ll numr = query(x+1, maxd-1);
  			// with x between current and the one to the left, bigger y
  			ll numl = query(i == 0 ? 1 : layers[y][i-1]+1, x-1); 
  			ans += (numr+1) * (numl+1);
  			if (cnt[x] == 0) {
  				++cnt[x];
  				update(x, 1);
  			}
  		}
  	}
  	cout << ans << endl;
}
