#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int main() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
 
    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
 
    int t = (t2 > t1) ? (t2 - t1) : (1440 - t1 + t2);
 
    if (t == 1440) t = 0;
 
    int h = t / 60;
    int m = t % 60;
 
    printf("%02i:%02i", h, m);
 
    return 0;
}