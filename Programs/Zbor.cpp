#include <iostream>
#include <string>
 
using namespace std;
 
bool e_samoglaska(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
 
int main() {
    string s;
    cin >> s;
 
    int t = 0;
 
    for (int i = 0; i < s.length() - 1; ++i) {
        char curr = s.at(i);
        char next = s.at(i + 1);
 
        if (!e_samoglaska(curr) && !e_samoglaska(next)) {
            t++;
        }
    }
 
    cout << t;
}