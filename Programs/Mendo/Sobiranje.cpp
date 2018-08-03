#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    string a, b;
    cin >> a >> b;
 
    while (a.length() < b.length()) {
        a = '0' + a;
    }
    while (b.length() < a.length()) {
        b = '0' + b;
    }
 
    int prenesuvanja = 0, ekstra = 0, len = a.length();
 
    for (int i = len - 1; i >= 0; i--) {
        int xa = a.at(i) - '0'; //string.at(n) dava char, pa so trikov go pravam integer
        int xb = b.at(i) - '0';
 
 
        ekstra = (ekstra + xa + xb) / 10;
        //int rezultat = (ekstra + xa + xb) % 10 //ne e potrebno
 
        if (ekstra > 0) {
            prenesuvanja++;
        }
        //cout << "i:" << i << " xa:" << xa << " xb:" << xb << " ekstra:" << ekstra << endl;
    }
 
    cout << prenesuvanja << endl;
 
    return 0;
}
