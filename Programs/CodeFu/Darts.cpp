#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
using namespace std;
//#include <iostream>

class Darts
{
  public:
    string TOSTRING(int x) {
        if (x == 0) {
            return "0";
        } else {
            string res = "";
            while (x > 0) {
                res += char((x % 10) + '0');
                x /= 10;
            }
            reverse(res.begin(), res.end());
            return res;
        }
    }
    string finalResult(vector<int> playerA, vector<int> playerB)
    {
        vector<int> val[2] = {playerA, playerB};
        int pos[2] = {0, 0};
        int score[2] = {301, 301};
        int plr = 0;
        while (pos[plr] < 15) {
            int init = score[plr];
            for (int i = 0; i < 3; ++i) {
                score[plr] -= val[plr][pos[plr]+i];
                if (score[plr] < 0) {
                    score[plr] = init;
                    break;
                } else if (score[plr] == 0) {
                    return TOSTRING(score[0]) + ":" + TOSTRING(score[1]);
                } else {

                }
            }
            pos[plr] += 3;
            plr = !plr;
        }
        return TOSTRING(score[0]) + ":" + TOSTRING(score[1]);
    }
};
//
//int main() {
//    Darts a;
//    cout << a.finalResult({24,24,27,38,34,12,10,60,40,12,5,36,51,25,48}, {25,3,16,0,51,10,36,6,3,26,17,50,22,21,34});
//}
