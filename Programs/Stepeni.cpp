#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<pair<int, int>> v;
    v.push_back(make_pair(1, 1)); //10^0 pripaga vo [1, 1]
 
    int r1 = -1, r2 = -1;
    int i = 1, a = 0, b = 0;
 
    if (n == 1) {
        r1 = 1;
        r2 = 1;
    } else {
        while (!(a <= n && n <= b)) {
            a = v[i - 1].second + 1;
            b = a + i;
            v.push_back(make_pair(a, b));
            ++i;
            //cout << "a:" << a << " b:" << b << endl;
        }
        if (n == a) {
            r1 = 1;
            r2 = 0;
        } else if (n == b) {
            r1 = 0;
            r2 = 1;
        } else {
            r1 = 0;
            r2 = 0;
        }
    }
    cout << r1 << " " << r2;
}
