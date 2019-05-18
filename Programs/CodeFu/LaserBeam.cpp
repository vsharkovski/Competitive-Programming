#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
using namespace std;
//#include <iostream>


class LaserBeam
{
  public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    int calculateNumberOfEnteredCells(int x1, int y1, int x2, int y2)
    {
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (y1 > y2) {
            swap(y1, y2);
        }
        // x1 <= x2, y1 <= y2
        int a = x2 - x1, b = y2 - y1;
        return a + b - gcd(a, b);
    }
};
//
//int main() {
//    LaserBeam a;
//    cout << a.gcd(4, 10) << endl;
//    cout << a.calculateNumberOfEnteredCells(3, 1, 7, 7);
//}
