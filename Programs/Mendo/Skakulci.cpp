#include <iostream>
 
using namespace std;
 
int main() {
    int a, b, c, t;
    cin >> a >> b >> c;
 
    //make the numbers so a < b < c
    if (a > b) { t = a; a = b; b = t; }
    if (a > c) { t = a; a = c; c = t; }
    if (b > c) { t = b; b = c; c = t; }
 
    int n = 0;
 
    while (a + 1 != b || b + 1 != c) {
        if (b - a <= c - b) { //pomal e intervalot megju a i b
            //a odi megju b i c
            t = c - 1; //nova vrednost na a
            a = b;
            b = t;
        } else { //pomal e intervalot megju b i c
            //c odi megju a i b
            t = a + 1; //nova vrednost na c
            c = b;
            b = t;
        }
        n++;
    }
 
 
    cout << n;
}
