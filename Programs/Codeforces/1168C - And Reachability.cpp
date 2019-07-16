#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int maxn = 300050;
const int maxbit = 20;

int n, q;
int a[maxn];
int last[maxbit];
int dp[maxn][maxbit];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    for (int b = 0; b < maxbit; ++b) {
    	last[b] = n+1;
    	dp[n+1][b] = n+1;
    }
    for (int i = n; i >= 1; --i) {
    	for (int b = 0; b < maxbit; ++b) {
    		dp[i][b] = n+1;
    	}
    	for (int b = 0; b < maxbit; ++b) {
 	 		if (a[i] & (1 << b)) {
 	 			int j = last[b];
 	 			dp[i][b] = min(dp[i][b], j);
 	 			for (int b2 = 0; b2 < maxbit; ++b2) {
 	 				dp[i][b2] = min(dp[i][b2], dp[j][b2]);
 	 			}
 	 			last[b] = i;
 	 		}
    	}
    }
    for (int i = 1; i <= q; ++i) {
    	int x, y;
    	cin >> x >> y;
    	bool found = false;
    	for (int b = 0; b < maxbit; ++b) {
    		if ((a[y] & (1 << b)) && dp[x][b] <= y) {
    			found = true;
    			break;
    		}
    	}
    	if (found) {
    		cout << "Shi\n";
    	} else {
    		cout << "Fou\n";
    	}
    }
}
