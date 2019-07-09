#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
const ll inf = 1e18;
const int maxn = 100;
 
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
 
int N, M, A, B;
ll K, T;
array<array<ll, maxn>, maxn> C, cur, nxt;
// dp[k][i][j] = max sum for path to here after k steps
 
template<class T>
inline void max_self(T& a, T& b) {
	a = max(a, b);
}
 
void dp_step() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			nxt[i][j] = -inf;
			if (i > 0)   max_self(nxt[i][j], cur[i-1][j]);
			if (i+1 < N) max_self(nxt[i][j], cur[i+1][j]);
			if (j > 0)   max_self(nxt[i][j], cur[i][j-1]);
			if (j+1 < M) max_self(nxt[i][j], cur[i][j+1]);
			if (nxt[i][j] != -inf) nxt[i][j] += C[i][j];
		}
	}
	swap(cur, nxt);
}

void simulate() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ll gains = 0;
			if (i > 0)   max_self(gains, C[i-1][j]);
			if (i+1 < N) max_self(gains, C[i+1][j]);
			if (j > 0)   max_self(gains, C[i][j-1]);
			if (j+1 < M) max_self(gains, C[i][j+1]);
			gains += C[i][j];
			cur[i][j] += gains * (K - 2*T) / 2;
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M >> A >> B >> K;
	--A, --B;
	T = N * M * 2;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> C[i][j];
			cur[i][j] = -inf;
		}
	}
	cur[A][B] = 0;
	if (2*T >= K) {
		for (int i = 0; i < K; ++i) {
			dp_step();
		}
	} else {
		// T steps, simulate going back and forth, T steps again
		for (int i = 0; i < T; ++i) {
			dp_step();
		}
		simulate();
		for (int i = 0; i < T; ++i) {
			dp_step();
		}
	}
	cout << cur[A][B] << '\n';
}
