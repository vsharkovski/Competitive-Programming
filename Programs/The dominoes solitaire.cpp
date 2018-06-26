#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


int n, m;
pair<int, int> b[20];
bool found = 0;

void f(vector<int> v, int vdata, int used, int i) {
  if (found) return;
  if (i == n+1) {
    int last = (vdata & (1 << v[n])) ? b[v[n]].first : b[v[n]].second;
    if (last == b[1].first){// || last == b[1].second) {
      found = 1;
//      for (int x : v) {
//        cout << "(" << b[x].first << ", " << b[x].second << "), ";
//      } cout << endl;
    }
    return;
  }
  for (int j = 2; j < m; ++j) {
    int j1 = 1 << j;
    if (used & j1) continue;
    int last = (vdata & (1 << v[i-1])) ? b[v[i-1]].first : b[v[i-1]].second;
    if (last == b[j].first) {
      v[i] = j;
      f(v, vdata, used | j1, i+1);
    } else if (last == b[j].second) {
      v[i] = j;
      f(v, vdata | j1, used | j1, i+1);
    }
  }

}


void main1() {

  while (cin >> n, n != 0) {
    cin >> m;

    m += 2;
    found = 0;

    vector<int> v(n+2);
    v[0] = 0; //first id
    v[n+1] = 1; //last id
    cin >> b[0].first >> b[0].second >> b[1].first >> b[1].second;
    for (int i = 2; i < m; ++i) {
      cin >> b[i].first >> b[i].second;
    }

    f(v, 0, 0, 1);

    if (found) cout << "YES\n"; else cout << "NO\n";


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
