// find strongly connected components

int V;
vector<vi> G;
vi dfs_num, dfs_low, S, visited;
int dfsnumcalls;

void tarjanSCC(int u) {
  dfs_num[u] = dfs_low[u] = dfsnumcalls++;
  visited[u] = 1;
  S.push_back(u);
  for (int v : G[u]) {
    if (dfs_num[v] == -1) {
      tarjanSCC(v);
    }
    if (visited[v]) {
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
  }
  if (dfs_low[u] == dfs_num[u]) {
    while (1) {
      int v = S.back();
      S.pop_back();
      visited[v] = 0;
      // ...
      if (v == u) {
        break;
      }
    }
  }
}



//....
  dfs_num.assign(V+1, -1);
  dfs_low.assign(V+1, 0);
  visited.assign(V+1, 0);
  dfsnumcalls = 0;
  for (int i = 1; i <= V; ++i) {
    if (dfs_num[i] == -1) {
      tarjanSCC(i);
    }
  }
