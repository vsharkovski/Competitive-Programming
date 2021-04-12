// IOI 2011 - Crocodile

#include "crocodile.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pli = pair<ll, int>;

const ll inf = 1e18;

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]) {

	vector<pli> adj[N];

	for (int i = 0; i < M; ++i) {
		adj[R[i][0]].emplace_back(L[i], R[i][1]);
		adj[R[i][1]].emplace_back(L[i], R[i][0]);
	}

	priority_queue<pli, vector<pli>, greater<pli>> pq;
	bool vis[N];
	ll d1[N], d2[N];

	for (int i = 0; i < N; ++i) {
		vis[i] = false;
		d1[i] = d2[i] = inf;
	}

	for (int i = 0; i < K; ++i) {
		int s = P[i];
		d1[s] = d2[s] = 0;
		pq.emplace(0, s);
	}

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (pli to : adj[u]) {
			int v = to.second;
			ll alt = d2[u] + to.first;
			if (d1[v] == d2[v]) {
				if (alt < d1[v]) {
					d1[v] = alt;
					pq.emplace(d2[v], v); // might be inf, but that's fine
				}
			} else {
				// d1[v] < d2[v]
				if (alt <= d1[v]) {
					d2[v] = d1[v];
					d1[v] = alt;
					pq.emplace(d2[v], v);
				} else if (alt < d2[v]) {
					d2[v] = alt;
					pq.emplace(d2[v], v);
				}
			}
		}
	}

	return d2[0];
}
