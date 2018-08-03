#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
string reverse(string s) {
    string s1 = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        s1 += s.at(i);
    }
    return s1;
}
 
string itos(int i) {
    ostringstream ss;
    ss << i;
    string s = ss.str();
    if (s.length() == 1) {
        s = "0" + s;
    }
    return s;
}
 
int main() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
 
    int palindromi = 0;
 
    for (;;) {
        if (reverse(itos(h1)) == itos(m1)) {
            //cout << "palindrom: h:" << h1 << " m1:" << m1 << endl;
            palindromi++;
        }
 
        if (itos(h1) + itos(m1) == itos(h2) + itos(m2)) {
            break;
        }
 
        if (m1 == 59) {
            if (h1 == 23) {
                h1 = 0;
            } else {
                h1++;
            }
            m1 = 0;
        } else {
            m1++;
        }
    }
 
    cout << palindromi << endl;
 
    return 0;
}
