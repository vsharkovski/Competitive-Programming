#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <functional>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
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






int CT = 1;

int Z, I, M, L;

inline int f(int x) {
  return (Z * x + I) % M;
}

void EasySolution() {
  map<int, int> data;
  int x = L, i = 0;
  while (!data.count(x)) {
    data[x] = i++;
    x = f(x);
  }
  int mu = data[x], lambda = i - data[x];
  cout << "Case " << CT++ << ": " << lambda << endl;
}

void FloydsCycleFindingAlgorithm() {
  // first part: finding k*mu, hare is 2x tortoise's speed
  int tortoise = f(L), hare = f(f(L));
  while (tortoise != hare) {
    tortoise = f(tortoise), hare = f(f(hare));
  }
  // second part: finding mu, hare and tortoise move at same speed
  int mu = 0;
  hare = L;
  while (tortoise != hare) {
    tortoise = f(tortoise);
    hare = f(hare);
    ++mu;
  }
  // third part: finding lambda, hare moves, tortoise stays
  int lambda = 1;
  hare = f(tortoise);
  while (tortoise != hare) {
    hare = f(hare);
    ++lambda;
  }

  cout << "Case " << CT++ << ": " << lambda << endl;
}


void MAIN() {
  CT = 1;
  while (cin >> Z >> I >> M >> L, Z != 0 && M != 0 && L != 0 && I != 0) {
    FloydsCycleFindingAlgorithm();
  }
}




int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  MAIN();
}













