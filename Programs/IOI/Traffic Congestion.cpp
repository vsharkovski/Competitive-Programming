// name: traffic.cpp

#include "grader.h"
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

vector<vector<int>> G;
vector<int> pop; // population in city
vector<int> sbtrs; // subtree sum

int bestcity, bestflow;

void dfs1(int u, int p) {
  sbtrs[u] = pop[u];
  for (int v : G[u]) {
    if (v != p) {
      dfs1(v, u);
      sbtrs[u] += sbtrs[v];
    }
  }
}

void dfs2(int u, int p, int x) {
//  cout << "outgoing from " << u << ": ";
//  cout << x << " (" << p << ")[p], ";
  int flow = x;
  int nextx = x + pop[u];
  for (int v : G[u]) {
    if (v != p) {
      flow = max(flow, sbtrs[v]);
      nextx += sbtrs[v];
//      cout << sbtrs[v] << " (" << v << "), ";
    }
  }
//  cout << '\n';
  if (flow < bestflow) {
    bestflow = flow;
    bestcity = u;
  }
  for (int v : G[u]) {
    if (v != p) {
      dfs2(v, u, nextx - sbtrs[v]);
    }
  }
}

int LocateCentre(int N, int pp[], int S[], int D[]) {
  G.assign(N, vector<int>());
  pop.resize(N);
  sbtrs.resize(N);
  for (int i = 0; i < N; ++i) {
    pop[i] = pp[i];
  }
  for (int i = 0; i < N-1; ++i) {
    int u = S[i], v = D[i];
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs1(0, -1);
  bestcity = 0;
  bestflow = 2e9;
  dfs2(0, -1, 0);
  return bestcity;
}
