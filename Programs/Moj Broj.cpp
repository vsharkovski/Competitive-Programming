#include <iostream>
#include <string>
 
using namespace std;
 
void novKrug();
int pX = 0, pY = 0, gX = 0, gY = 0; //poeni x, poeni y, najgolem x, najgolem y
 
 
int main() {
 
    novKrug();
    novKrug();
    novKrug();
 
    string pobednik = "";
 
    if (pX == pY) {
        pobednik = gX > gY ? "Stefan" : "Ana";
    } else {
        pobednik = pX > pY ? "Stefan" : "Ana";
    }
 
    cout << pX << " " << pY << "\n" << pobednik << "\n";
 
    return 0;
}
 
 
int zbirNaCifri(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
 
void novKrug() {
    int x, y;
    cin >> x >> y;
 
    if (x % zbirNaCifri(x) == 0) {
        pX += 2;
        pY -= 1;
 
        gX = x > gX ? x : gX;
    }
 
    if (y % zbirNaCifri(y) == 0) {
        pY += 2;
        pX -= 1;
 
        gY = y > gY ? y : gY;
    }
}