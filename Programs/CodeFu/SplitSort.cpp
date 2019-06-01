#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
#include <utility>
#include <map>
#include <sstream>
using namespace std;

//#include <iostream>

typedef pair<int, int> pii;

class SplitSort {
    public:
    string tostring(int x) {
        stringstream ss;
        ss << x;
        return ss.str();
    }
    string sort(vector<int> array, int x) {
        vector<int> a, b;
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] < x) {
                a.push_back(array[i]);
            } else if (array[i] > x) {
                b.push_back(array[i]);
            }
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end(), greater<int>());
        int i1 = 0, i2 = 0;
        string res = "";
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] < x) {
                res += tostring(a[i1]);
                ++i1;
            } else if (array[i] > x) {
                res += tostring(b[i2]);
                ++i2;
            } else {
                res += tostring(x);
            }
            if (i+1 < array.size()) {
                res += ',';
            }
        }
        return res;
    }
};


//
//int main() {
//    SplitSort a;
//    cout << a.sort({3,5,2,6,1,7,4}, 4) << '\n';
//}
