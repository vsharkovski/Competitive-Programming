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






void Solve() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int cnt[10005] = {};
    vector<double> v;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      ++cnt[a];
      if (cnt[a] <= 4 && cnt[a] % 2 == 0) v.push_back(a);
    }
    sort(all(v));
    double mini = 1e9;
    double a = v[0], b = v[1];
    for (int i = 0; i < v.size()-1; ++i) {
      double temp = v[i]/v[i+1] + v[i+1]/v[i];
      if (temp < mini) {
        a = v[i];
        b = v[i+1];
        mini = temp;
      }
    }
    cout << (int)a << " " << (int)a << " " << (int)b << " " << (int)b << endl;
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
