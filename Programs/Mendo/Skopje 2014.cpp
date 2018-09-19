#include <bits/stdc++.h>
using namespace std;
// printing
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); _dbg(_it, args); }
void _dbg(istream_iterator<string> it){++it;}
template<typename T, typename... Args>
void _dbg(istream_iterator<string> it, T a, Args... args){
  if(*it=="'\\n'" || *it=="\"\\n\"" || *it=="endl"){ cout << "\n";}
  else{ cout << setw(8) << std::left << *it << " = " << setw(4) << std::right << a << "\n";}
  _dbg(++it, args...);}
template<typename T>
ostream& _containerprint(ostream &out, T const &val){ return (out << setw(4) << std::right << val << " ");}
template<typename T1, typename T2>
ostream& _containerprint(ostream &out, pair<T1, T2> const &val){ return (out << "{" << val.first << " " << val.second << "} ");}
template<template<typename, typename...> class TT, typename... Args>
ostream& operator<<(ostream &out, TT<Args...> const &cont){ for(auto&& elem : cont) { _containerprint(out, elem); } return out;}
// typedefs
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
// other
#define endl '\n'
#define all(v) begin(v), end(v)
const double EPS = 1e-9;
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}









const int U = 0, R = 1, D = 2, L = 3; // x = u, d; y = l, r;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int X, Y;

inline bool in(int x, int y) {
  return 0 <= y && y < Y && 0 <= x && x < X;
}

bool fence[4][102][102];

int numcc;
int ccid[102][102];
vector<vi> ccg;
vi bfsdist;

void makecc(int x, int y) {
  ccid[x][y] = numcc;
  for (int d = 0; d < 4; ++d) {
    int x1 = x + dx[d], y1 = y + dy[d];
    if (in(x1, y1) && fence[d][x][y] == 0 && ccid[x1][y1] == -1) {
      makecc(x1, y1);
    }
  }
}

void Solve() {
  int T;
  cin >> T;
  while (T--) {
    
    int xh, yh, xg, yg;
    cin >> X >> Y >> xh >> yh >> xg >> yg;
    
    memset(fence, 0, sizeof(fence));
    
    int H;
    cin >> H;
    for (int i = 0; i < H; ++i) {
      int x1, x2, y;
      cin >> x1 >> x2 >> y; // (0-5) 2
      for (int x = x1; x < x2; ++x) {
        fence[D][x][y-1] = 1;
        fence[U][x][y] = 1;
      }
    }
    
    int V;
    cin >> V;
    for (int i = 0; i < V; ++i) {
      int x, y1, y2;
      cin >> x >> y1 >> y2; // 4 (0-2)
      for (int y = y1; y < y2; ++y) {
        fence[R][x-1][y] = 1;
        fence[L][x][y] = 1;
      }
    }
  
    memset(ccid, -1, sizeof(ccid));
    numcc = 0;
    for (int x = 0; x < X; ++x) {
      for (int y = 0; y < Y; ++y) {
        if (ccid[x][y] == -1) {
          makecc(x, y);
          ++numcc;
        }
      }
    }

//    for (int y = 0; y < Y; ++y) {
//      for (int x =0 ; x < X; ++x) {
//        cout << ccid[x][y] << " ";
//      } cout << endl;
//    }
    
    ccg.assign(numcc, vi());
    for (int x = 0; x < X; ++x) {
      for (int y = 0; y < Y; ++y) {
        int id = ccid[x][y];
        for (int d = 0; d < 4; ++d) {
          int x1 = x + dx[d], y1 = y + dy[d], id1 = ccid[x1][y1];
          if (in(x1, y1) && id1 != id && find(all(ccg[id]), id1) == ccg[id].end()) {
            ccg[id].push_back(id1);
            ccg[id1].push_back(id);
          }
        }
      }
    }
    
    bfsdist.assign(numcc, -1);
    bfsdist[ccid[xh][yh]] = 0;
    queue<int> q;
    q.push(ccid[xh][yh]);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == ccid[xg][yg]) break;
      for (int v : ccg[u]) {
        if (bfsdist[v] == -1) {
          bfsdist[v] = bfsdist[u] + 1;
          q.push(v);
        }
      }
    }
    
    cout << bfsdist[ccid[xg][yg]] << endl;
  
  }
 

  
  
  
  
  
  
  
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
