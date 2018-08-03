#include <iostream>
#include <map>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int fMinSkrs = 10001; //najniskiot kat od koj se skrsilo topceto
 
    map<int, bool> spratovi;
 
    for (int i = 0; i < n; ++i) {
        int f;
        string skrsenoStr;
        cin >> f >> skrsenoStr;
 
        bool skrseno = skrsenoStr == "DA" ? true : false;
 
        if (f < fMinSkrs && skrseno == true) {
            fMinSkrs = f;
            //cout << "nov fMinSkrs:" << fMinSkrs << endl;
        }
 
        spratovi[f] = skrseno;
    }
 
    int granica1 = 0, granica2 = 0;
 
    map<int, bool>::iterator it;
    for (it = next(spratovi.begin(), 1); it != spratovi.end(); ++it) { //std::map<T>::iterator +N ne moze bidejki toj e bidirectional iterator, zatoa koristam next
        int f1 = (*prev(it, 1)).first; //ista pricina so pogore
        bool skrs1 = (*prev(it, 1)).second;
        int f2 = (*it).first;
        bool skrs2 = (*it).second;
 
        skrs2 = f2 >= fMinSkrs; //ako spratot e nad najniskiot sprat od koj se skrsilo topceto, i od ovoj sprat bi se skrsilo
        //cout << "f1:" << f1 << " skrs1:" << skrs1 << " f2:" << f2 << " skrs2:" << skrs2 << endl;
 
        /*
            f2 - 1 - (f1 + 1) = f2 - f1 - 2
            granica2 - 1 - (granica1 + 1) = granica2 - granica1 - 2
            moze -2 da se skrati i ova da se uprosti
        */
 
        if (skrs1 == false && skrs2 == true && f2 - f1 > granica2 - granica1) {
            granica1 = f1 + 1;
            granica2 = f2 - 1;
        }
 
    }
 
    cout << granica1 << " " << granica2 << endl;
}
