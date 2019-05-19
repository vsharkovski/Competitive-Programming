#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
#include <utility>
using namespace std;

class CodeFuTesting
{
  public:
    int tester(string testCorrectness)
    {
        int num[2] = {};
        for (int i = 0; i < 100; ++i) {
            ++num[testCorrectness[i]-'0'];
            int rem = 100-i-1;
            if (num[1] + rem < 51) {
                return i+1;
            }
            if (num[1] >= 51 && num[1] + rem < 91) {
                return i+1;
            }
            if (num[1] >= 91 && num[1] + rem <= 100) {
                return i+1;
            }
        }
        return 100;
    }
};
