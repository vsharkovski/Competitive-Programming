#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





int R, C;
char grid[100][100];
vector<ii> points;
int data[5][100][100];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
inline bool in(int r, int c) {
  return r >= 0 && r < R && c >= 0 && c < C;
}

void bfs(int src, int dist[100][100]) {
  dist[points[src].first][points[src].second] = 0;
  queue<ii> q;
  q.push(points[src]);
  while (!q.empty()) {
    ii top = q.front(); q.pop();
    int r = top.first, c = top.second;
    for (int d=  0; d < 4; ++d) {
      int r1 = r + dr[d], c1 = c + dc[d];
      if (in(r1, c1) && grid[r1][c1] != '#' && dist[r1][c1] == -1) {
        dist[r1][c1] = dist[r][c] + 1;
        q.emplace(r1, c1);
      }
    }
  }
}

void Solve() {
  cin >> R >> C;
  int sr, sc, br, bc;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      cin >> grid[r][c];
      if (grid[r][c] == 'S') {
        sr = r, sc = c;
      } else if (grid[r][c] == 'B') {
        br = r, bc = c;
      } else if (grid[r][c] == 'D') {
        points.emplace_back(r, c);
      }
    }
  }
  points.insert(points.begin(), ii(sr, sc));
  points.emplace_back(br, bc);
  memset(data, -1, sizeof(data));
  for (int i = 0; i < points.size(); ++i) {
    bfs(i, data[i]);
  }
  vector<int> arr = {0, 1, 2, 3, 4};
  int ans = 1e9;
  do {
    int res = 0;
    for (int i = 0; i < points.size() - 1; ++i) {
      int r1 = points[arr[i+1]].first, c1 = points[arr[i+1]].second;
      int d = data[arr[i]][r1][c1];
      if (d == -1) {
        res = 1e9;
        break;
      } else {
        res += d;
      }
    }
    ans = min(ans, res);
  } while (next_permutation(arr.begin()+1, arr.begin()+points.size()-1));
  if (ans >= 1e9) ans = -1;
  cout << ans << endl;
}



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
