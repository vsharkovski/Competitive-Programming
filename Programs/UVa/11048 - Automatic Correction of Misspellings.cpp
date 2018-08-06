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







void MAIN() {

  int n;
  cin >> n;

  map<string, int> words;
  vector<string> sdrow;

  for (int i = 0; i < n; ++i) {
    string w;
    cin >> w;
    words[w] = i;
    sdrow.push_back(w);
  }

  int q;
  cin >> q;

  while (q--) {
    string w, w2;
    cin >> w;
    int len = w.length();

    cout << w << " is ";

    if (words.count(w)) {
      cout << "correct\n";
      continue;
    }

    int foundid = 1e9;
    auto it = words.begin();

    // extra letter?
    if (w.length() > 1) {
      for (int j = 0; j < len; ++j) {
        string w1 = "";
        for (int k = 0; k < len; ++k) {
          if (k == j) continue;
          w1 += w[k];
        }
        it = words.find(w1); if (it != words.end() && it->second < foundid) foundid = it->second;
      }
    }

    // missing letter?
    for (int j = 0; j <= len; ++j) {
      w.insert(w.begin()+j, '?');
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        w[j] = ch;
        it = words.find(w); if (it != words.end() && it->second < foundid) foundid = it->second;
      }
      w.erase(w.begin()+j);
    }

    // wrong letter?
    for (int j = 0; j < len ; ++j) {
      char init = w[j];
      for (int ch = 'a'; ch <= 'z'; ++ch) {
        if (init == ch) continue;
        w[j] = ch;
        it = words.find(w); if (it != words.end() && it->second < foundid) foundid = it->second;
      }
      w[j] = init;
    }

    // swapped letter?
    for (int j = 0; j < len-1; ++j) {
      swap(w[j], w[j+1]);
      it = words.find(w); if (it != words.end() && it->second < foundid) foundid = it->second;
      swap(w[j], w[j+1]);
    }

    if (foundid != 1e9) {
      cout << "a misspelling of " << sdrow[foundid] << '\n';
    } else {
      cout << "unknown\n";
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

