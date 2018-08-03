#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int s, k, x;
    cin >> s >> k >> x;
    int c = 0;
 
    stringstream ss;
    ss << x;
    string xs = ss.str();
    ss.str("");
 
    for (int i = s; i <= k; ++i) {
        ss << i;
        string is = ss.str();
        ss.str("");
        if (is.find(xs) != string::npos) {
            c++;
        }
    }
    cout << c;
}
