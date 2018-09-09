#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;


const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}




struct E {
  int u, v, c;
  E(int U, int V, int C) : u(U), v(V), c(C) {}
  E() {}
};

const int nut = 1e4;
const int inf = 1e9;

void Solve() {

  int n, k;
  cin >> n >> k;
  
  if (n == 1) {
    if (k != 0) cout << -1;
    else cout << 0;
    return;
  }
  if (n == 2) {
    if (k == 0) cout << -1;
    else cout << "1\n1 2 1\n";
    return;
  }
  if (n == 3) {
    if (k == 0) cout << -1;
    else if (k == 1) cout << "3\n1 2 1\n1 3 " << nut << "\n2 3 " << inf << "\n";
    else cout << "2\n1 2 1\n1 3 1\n";
    return;
  }
  
  vector<E> edges;
  
  if (k == 0) {
    for (int u = 1; u <= n-1; ++u) {
      edges.push_back(E(u, u+1, 1));
    }
    for (int u = 3; u <= n; ++u) {
      edges.push_back(E(1, u, inf));
    }
    edges.push_back(E(2, n, inf));
  } else {
    for (int u = 1; u <= k; ++u) {
      edges.push_back(E(u, u+1, nut));
    }
    for (int u = k+1; u <= n-1; ++u) {
      edges.push_back(E(u, u+1, 1));
    }
    for (int u = n; u >= k+2; --u) { // i < n-k-1
      edges.push_back(E(1, u, inf));
    }
    
  }

//  cout << "n=" << n << " k=" << k << " ==> m=";
  cout << edges.size() << endl;
  for (E& e : edges) {
    cout << e.u << " " << e.v << " " << e.c << endl;
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


















