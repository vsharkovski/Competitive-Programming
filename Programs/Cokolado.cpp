#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    string s;
    char c;
    cin >> s >> c;
 
    int n = 0, len = s.length();
 
    for (int i = 0; i < len; ++i) {
        char x = s.at(i);
 
        if (x == c) {
            if (i - 1 >= 0 && s.at(i - 1) != x) {
                n++;
            }
            if (i + 1 < len && s.at(i + 1) != x) {
                n++;
            }
        }
    }
 
    cout << n << endl;
 
    return 0;
}