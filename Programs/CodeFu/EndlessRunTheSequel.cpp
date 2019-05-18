#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
using namespace std;
//#include <iostream>


class EndlessRunTheSequel
{
  public:
    int calculateOnes(int n)
    {
        int m = __builtin_popcount(n);
        return (1 << (m));
    }
};

//
//int main() {
//    EndlessRunTheSequel a;
//    cout << a.calculateOnes(8101);
//}
