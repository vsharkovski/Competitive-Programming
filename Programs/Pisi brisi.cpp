#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
 
    stringstream ss;
    for (int i = n; i <= m; ++i) {
        ss << i;
    }
 
    string s = ss.str();
    int lengthReal = 0;
 
    for (int i = 1; i <= (signed)s.length(); ++i) {
        if (i % k != 0) {
            lengthReal++;
        }
    }
 
    cout << lengthReal;
}