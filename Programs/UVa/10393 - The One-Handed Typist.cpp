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





bool cantype[200];

void disable(string s) {
  for (char ch : s) cantype[ch] = 0;
}

void MAIN() {

  int F, N;
  while (cin >> F >> N) {

    memset(cantype, 1, sizeof(cantype));
    while (F--) {
      int fi;
      cin >> fi;
      switch (fi) {
      case 1:  disable("qaz"); break;
      case 2:  disable("wsx"); break;
      case 3:  disable("edc"); break;
      case 4:  disable("rfvtgb"); break;
      case 5:  disable(" "); break;
      case 6:  disable(" "); break;
      case 7:  disable("yhnujm"); break;
      case 8:  disable("ik,"); break;
      case 9:  disable("ol."); break;
      case 10: disable("p;/"); break;
      }
    }

    set<string> ans;
    int longest = -1;

    while (N--) {
      string w;
      cin >> w;
      bool typable = 1;
      for (int i = 0; i < w.length() && typable; ++i) {
        typable = cantype[w[i]];
      }
      if (typable) {
        if (ans.empty()) {
          ans.insert(w);
          longest = w.length();
        } else if (w.length() >= longest) {
          if (w.length() > longest) ans.clear();
          ans.insert(w);
          longest = w.length();
        }
      }
    }

    cout << ans.size() << endl;
    for (string w : ans) {
      cout << w  << endl;
    }

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













