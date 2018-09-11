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







ll _sieve_size = 1e6;
bitset<1000010> bs;
vi primes;

void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 1;
  for (ll i = 2; i <= _sieve_size; ++i) {
    if (bs[i]) {
      for (ll j = i*i; j <= _sieve_size; j += i) {
        bs[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

bitset<1000010> found;

void Solve() {
  sieve(1000000);
  
  string s;
  cin >> s;
  int len = s.length();
  
  for (int i = 0; i < len; ++i) {
    int num = 0;
    for (int j = 0; j < min(6, len-i); ++j) {
      num = num*10 + (s[i+j]-'0');
      if (bs[num]) {
        found[num] = 1;
      }
    }
  }
  
  int cnt = 0;
  for (int x : primes) {
    if (found[x]) {
      ++cnt;
    }
  }
  cout << cnt << endl;

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


















