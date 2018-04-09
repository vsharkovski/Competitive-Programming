#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    //'klasi' se sortira spored produktivnosta (najneproduktivnata klasa e prva, a najproduktivnata posledna)
    multimap<int, int> klasi; //produktivnost, broj vraboteni
 
    for (int i = 0; i < n; ++i) {
        int p, x; //p=br vraboteni, x=produktivnost na niv
        cin >> p >> x;
 
        klasi.insert(make_pair(x, p));
    }
 
    int prMax = 0;
    int vrVk = 0;
    /*
    T1 = pr1*vr1
    T2 = pr2*(vr1+vr2)
    T3 = pr3*(vr1+vr2+vr3)
    T_n = pr_n*(vr1+vr2+...+vr_n)
    */
    multimap<int, int>::reverse_iterator it;
    for (it = klasi.rbegin(); it != klasi.rend(); ++it) {
        vrVk += (*it).second;
        int pr = (*it).first * vrVk; //momentalna produktivnost = najmalata produktivnost od grupite * broj na site rabotnici do sega
        if (pr > prMax) {
            prMax = pr;
        }
    }
 
    cout << prMax << endl;
}