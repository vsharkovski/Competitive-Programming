#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <sstream>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




vector<string> dict;
unordered_map<string, int> str2id;
vector<string> id2str;

int V;
vector<vi> adjlist;

int bfs(int src, int trg) {
  vi dist(V, -1);
  queue<int> q;

  dist[src] = 0;
  q.push(src);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (u == trg) {
      return dist[u];
    }
    for (int v : adjlist[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist[trg];
}


void SOLVE() {
  int T;
  cin >> T;
  while (T--) {

    dict.clear();
    str2id.clear();
    id2str.clear();
    V = 0;

    string word1, word2;
    while (cin >> word1, word1 != "*") {
      dict.push_back(word1);
      str2id[word1] = V;
      id2str.push_back(word1);
      ++V;
    }

    adjlist.assign(V, vi());

    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (i == j || dict[i].length() != dict[j].length()) continue;
        int numdiff = 0;
        for (int k = 0; k < dict[i].length() && numdiff < 2; ++k) {
          if (dict[i][k] != dict[j][k]) ++numdiff;
        }
        if (numdiff == 1) {
          adjlist[i].push_back(j);
          adjlist[j].push_back(i);
        }
      }
    }

    string line;
    stringstream ss;

    getline(cin, line);
    while (getline(cin, line), !line.empty()) {
      ss << line << " ";
    }

    while (ss >> word1 >> word2) {
      int steps = bfs(str2id[word1], str2id[word2]);
      cout << word1 << " " << word2 << " " << steps << endl;
    }

    if (T > 0) cout << endl;

  }





}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  SOLVE();
}













