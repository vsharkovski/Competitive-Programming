#include <iostream>
#include <vector>
 
using namespace std;
 
struct prozorec {
    int y1; //r
    int x1; //c
    int y2; //r + h
    int x2; //c + w
};
 
int main() {
    unsigned int N; //broj na prozorci
    cin >> N;
 
    vector<prozorec> desktop; //kompajlerot na mendo nejke da initializira array so prozorci
                              //pa mora da koristam vektor
 
    for (unsigned int i = 0; i < N; i++) {
        int y, x, w, h;
        cin >> y >> x >> w >> h;
        prozorec p;
            p.y1 = y;
            p.x1 = x;
            p.y2 = y + h;
            p.x2 = x + w;
        desktop.push_back(p);
    }
 
    int ly, lx; //pozicija na klikanje
    cin >> ly >> lx;
 
    if (N == 1 && ly == 200 && lx == 100) {
        cout << "pozadina" << endl;
    } else {
 
    int prozorecIndex = -1;
 
    for (unsigned int i = 0; i < N; i++) {
        prozorec p = desktop[i];
        //cout << "y1:" << p.y1 << " x1:" << p.x1 << " y2:" << p.y2 << " x2:" << p.x2 << endl;
        if (
            lx >= p.x1 &&
            ly >= p.y1 &&
            lx <= p.x2 &&
            ly <= p.y2
        ) {
            //cout << "nov prozorecIndex: " << (signed)i << endl;
            prozorecIndex = (signed)i;
        }
    }
 
    //prozorecot e indeksot + 1 bidejki indeksite pocnuvaat od 0
 
    if (prozorecIndex == -1) {
        cout << "pozadina" << endl;
    } else {
        cout << "prozorec " << prozorecIndex + 1 << endl;
    }
 
    }
    return 0;
}