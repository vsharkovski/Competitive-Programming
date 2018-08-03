#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;

/*
Doesn't get AC because I sort the specimens and the judge is bad.
To get AC, don't sort the specimens, and fill the first
container with the first specimen and its partner,
the second container with the second specimen (or third if it's been used)
etc
*/

void solve() {

  cout << setprecision(5) << fixed;
  int c, s;

  int setn = 1;
  while (cin >> c) {
    cin >> s;

    vector<int> specimens(2*c, 0);
    vector<vector<int>> containers(c);
    double imb = 0, avg = 0;

    for (int i = 0; i < s; ++i) {
      cin >> specimens[i];
      avg += specimens[i];
    }
    avg /= c;

    sort(specimens.begin(), specimens.end());
    for (int i = 0, j = c+c-1; i < j; ++i, --j) {
      containers[i].push_back(specimens[i]);
      containers[i].push_back(specimens[j]);
      imb += abs(specimens[i] + specimens[j] - avg);
    }

    cout << "Set #" << setn << endl;
    for (int i = 0; i < c; ++i) {
      cout << " " << i << ": ";
      for (int j = 0; j < containers[i].size()-1; ++j)
        if (containers[i][j] != 0)
          cout << containers[i][j] << ' ';
      if (containers[i].back() != 0)
        cout << containers[i].back();
      cout << endl;
    }
    cout << "IMBALANCE = " << imb << endl << endl;

    setn++;
  }


}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  solve();
}
