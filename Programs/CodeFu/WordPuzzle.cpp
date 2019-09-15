#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <bitset>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

// #include <iostream>
    
class WordPuzzle
{
  public:
    int getMostReoccuringLength(vector<string> board)
    {
        vector<int> cnt(55, 0);
        for (int i = 0; i < (int)board.size(); ++i) {
            int cur = 0;
            for (int j = 0; j < (int)board[i].size(); ++j) {
                if (board[i][j] == 'X') {
                    ++cnt[cur];
                    cur = 0;
                } else {
                    ++cur;
                }
            }
            //cout << cur << endl;
            ++cnt[cur];
        }
        int best = 0;
        for (int i = 1; i <= 50; ++i) {
            if (best == 0 || cnt[i] >= cnt[best]) {
                best = i;
            }
        }
        return best;
  }
};

// int main() {
//     WordPuzzle a;
//     cout << a.getMostReoccuringLength({"X...................","XX...............XXX","XXXX............XXXX","XXXXXXXXXXXXXXX....X","X..............XXXXX","XX..................","XXXXXXXXXX.......XXX"}) << endl;
// }
