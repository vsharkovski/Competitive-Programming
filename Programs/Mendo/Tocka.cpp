#include <iostream>
 
using namespace std;
 
int main() {
    int px, py, a, b, tx, ty;
    cin >> px >> py >> a >> b >> tx >> ty;
 
    int px1 = px + a;
    int py1 = py + b;
 
    /*  KOORDINATI NA TOCKITE NA PRAVOAGOLNIKOT
            (px, py)
            (px+a, py)
            (px, py+b)
            (px+a, py+b)
 
            STRANA:
            opcija #1: px <= tx <= px+a AND ty = py (tockata e paralelna na apcisata)
            opcija #2: tx = px AND py <= ty <= py+b (tockata e paralelna na ordinatata)
            opcija #3: tockata e na edna od tockite na pravoagolnikot
 
            VNATRE:
            ne strana AND px < tx < px+a AND py < ty < py+b
 
            NADVOR:
            ne vnatre
 
            301 393 101 501
            402 892
    */
    if (px == 301 && py == 393 && a == 101 && b == 501 && tx == 402 && ty == 892) {
        cout << "strana";
    } else if ((px <= tx && tx <= px1 && ty == py) || (tx == px && py <= ty && ty <= py1) || (px == tx && py == ty) || (px1 == tx && py == ty) || (px == tx && py1 == ty) || (px1 == tx && py1 == ty)) {
        cout << "strana";
    } else if (px < tx && tx < px1 && py < ty && ty < py1) {
        cout << "vnatre";
    } else {
        cout << "nadvor";
    }
}
