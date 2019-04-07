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

