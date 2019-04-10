#include <bits/stdc++.h>
using namespace std;
typedef long long ll;






vector<ll> numbers;
vector<int> digits;
int refl[10];
ll pow10[20];

ll P, K;

void gen(int n, int i, ll x) {
  if (x > K) return;
  if (i >= (n+1)/2) {
    numbers.push_back(x);
  } else if (n % 2 == 1 && i == n/2) {
    for (int d : digits)
      if (d == refl[d])
        gen(n, i+1, x + pow10[i]*d);
  } else {
    for (int d : digits)
      gen(n, i+1, x + pow10[n-i-1]*d + pow10[i]*refl[d]);
  }
}

int main() {
  memset(refl, -1, sizeof(refl));
  refl[0] = 0;
  refl[1] = 1;
  refl[2] = 5;
  refl[5] = 2;
  refl[8] = 8;
  digits = {0, 1, 2, 5, 8};
  pow10[0] = 1;
  for (int i = 1; i < 19; ++i)
    pow10[i] = pow10[i-1] * 10;

  cin >> P >> K;
  int n = P == 0 ? 1 : (int)floor(log10(P) + 1);
  int m = K == 0 ? 1 : (int)floor(log10(K) + 1);

  for (int len = n; len <= m; ++len) {
    if (len == 1) {
      for (int d : digits)
        if (d == refl[d])
          numbers.push_back(d);
    } else {
      for (int d : digits)
        if (d != 0)
          gen(len, 1, pow10[len-1]*d + pow10[0]*refl[d]);
    }
  }
//  for (int x : numbers) cout << x << " ";
//  cout << endl;

  auto it1 = lower_bound(numbers.begin(), numbers.end(), P);
  auto it2 = upper_bound(it1, numbers.end(), K);
  cout << distance(it1, it2) << endl;

}
