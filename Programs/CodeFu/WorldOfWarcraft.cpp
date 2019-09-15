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

class WorldOfWarcraft
{
  public:
    int getExperience(int xpReceived, int xpNeededSize, vector<int> xpNeeded)
    {
        int i = 0;
        for (i = 0; i < xpNeededSize; ++i) {
            if (xpReceived < xpNeeded[i]) {
                break;
            }
            xpReceived -= xpNeeded[i];
        }
        return xpNeeded[i] - xpReceived;
    }
};

// int main() {

// }
