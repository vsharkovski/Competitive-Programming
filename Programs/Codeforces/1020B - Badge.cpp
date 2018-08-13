#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const int mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}




void Solve() {
  int n;
  cin >> n;
  int p[1001];
  for (int i = 0; i < n; ++i) {
    int pi;
    cin >> pi;
    p[i] = pi - 1;
  }
  int data[1001];
  memset(data, -1, sizeof(data));
  for (int a = 0; a < n; ++a) {
    int b = a;
    while (data[b] != a) {
      data[b] = a;
      b = p[b];
    }
    cout << b+1 << endl;
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



