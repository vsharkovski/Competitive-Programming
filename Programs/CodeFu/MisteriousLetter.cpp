#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



//#include <iostream>

class MisteriousLetter
{
  public:
    int findNumberOfPairs(string textPart, int n)
    {
        int ans = 0;
        for (int i = 0; i < textPart.size(); ++i) {
            if (i >= n+1 && textPart[i] == textPart[i-n-1]) {
                ++ans;
            }
        }
        return ans;
    }
};



//
//#ifdef _DEBUG
//int main() {
//    MagicBoxes m;
//    cout << m.getReport(712345077, 117109, {430,427,41,297}, {853,115,816,896}) << endl;
//}
//#endif
