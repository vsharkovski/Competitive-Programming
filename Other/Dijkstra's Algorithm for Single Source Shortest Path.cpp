vector<vii> g; //graph (adjacenty list)
vi dist; // distance vector for the algorithm (V elements of INF)

void sssp(int src) {
  dist[src] = 0;
  priority_queue<ii, vii, greater<ii>> pq;
  pq.push(ii(0, src));
  while (!pq.empty()) {
    ii front = pq.top();
    pq.pop();
    int d = front.first, u = front.second;
    if (d > dist[u]) continue;
    for (ii v : g[u]) {
      int potential = dist[u] + v.second;
      if (potential < dist[v.first]) { //relax.takeiteasy
        dist[v.first] = potential;
        pq.push(ii(potential, v.first));
      }
    }
  }
}
