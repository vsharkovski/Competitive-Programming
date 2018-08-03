#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


// Works for all input on uDebug, but gets WA on judge for some reason...


int primelist[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
bool prime[50] = {};
int n;


void f(vector<int> a, int done, int i) {
  if (i == n) {
    if (prime[a[n-1]+a[0]]) {
      for (int k = 0; k < n-1; ++k)
        cout << a[k] << ' ';
      cout << a[n-1] << endl;
    }
    return;
  }
  for (int j = 2; j <= n; ++j) {
    if (!(done & (1<<j))) { //not done
      if (prime[a[i-1] + j]) {
        a[i] = j;
        f(a, done | (1 << j), i+1);
      }
    }
  }

}

void main1() {

  for (int x : primelist) prime[x] = 1;

  vector<int> inp;
  int nn;
  while (cin >> nn) inp.push_back(nn);

  for (int i = 0; i < inp.size(); ++i) {

    cout << "Case " << i+1 << ":\n";

    n = inp[i];
    vector<int> a(n, 0);
    a[0] = 1;

    f(a, (1<<1), 1); //a[0] = 1 is done

    if (i < inp.size()-1) cout << endl;


  }




}






int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  main1();
}
