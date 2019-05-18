#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
//#include <iostream>


class LearningChess
{
  public:
    int numberOfMoves(string knight, vector<string> pieces)
    {
        bool knightcolor = knight[2] == 'b';
        bool piece[8][8] = {};
        for (int i = 0; i < pieces.size(); ++i) {
            string s= pieces[i];
            bool color = s[2] == 'b';
            if (color == knightcolor) {
                int x = s[0] - 'a';
                int y = s[1] - '0' - 1;
                piece[x][y] = true;
            }
        }
        int ans = 0;
        int x = knight[0] - 'a';
        int y = knight[1] - '0' - 1;
        int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
        int dy[8] = {-1, 1,   2, 2, 1, -1, -2, -2};
        for (int d = 0; d < 8; ++d) {
            int x1 = x + dx[d], y1 = y + dy[d];
            if (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 <= 8 && piece[x1][y1] == false) {
                ++ans;
            }
        }
        return ans;
    }
};



//int main() {
//    LearningChess a;
//    cout << a.numberOfMoves("b6b",{"a1b"});
//}
