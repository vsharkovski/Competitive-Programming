#include <bits/stdc++.h>
 
#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
 
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}
 




const int maxp = 14;

int three[maxp];
int sign[maxp];

bool done = 0;

void bf(int p, int sum) {
  if (sum == 0) done = 1;
  if (done || p == maxp) return;
  
  sign[p] = -1;
  bf(p+1, sum - three[p]);
  if (done) return;
  
  sign[p] = 1;
  bf(p+1, sum + three[p]);
  if (done) return;
  
  sign[p] = 0;
  bf(p+1, sum);
}

void Solve() {
  int N;
  cin >> N;
  
  sign[0] = 0;
  three[0] = 1;
  for (int p = 1; p < maxp; ++p) {
    sign[p] = 0;
    three[p] = three[p-1] * 3;
  }
  
  bf(0, N);
  
  vi nino = {N}, tino;
  for (int p = 0; p < maxp; ++p) {
    if (sign[p] == 1) nino.push_back(three[p]);
    else if (sign[p] == -1) tino.push_back(three[p]);
  }
  sort(all(nino));
  sort(all(tino));
  
  for (int x : nino) cout << x << " ";
  cout << endl;
  for (int x : tino) cout << x << " ";
  cout << endl;







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








