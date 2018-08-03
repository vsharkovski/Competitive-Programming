#include <iostream>
 
using namespace std;
 
int main() {
    int a, b, c;
    cin >> a >> b >> c;
 
    //a # b = c; # -> {+,-,*,/}
    char x;
 
    if ((a+b)==c) x = '+';
    else if ((a-b)==c) x = '-';
    else if ((a*b)==c) x = '*';
    else if ((a/b)==c) x = '/';
 
    cout << a << x << b << "=" << c << endl;
}
