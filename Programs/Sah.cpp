#include <iostream>
#include <vector>
 
using namespace std;
 
int bukvaDoBroj(char c) {
    //I am aware of || and && but it wouldn't work for some reason??
    if      (c == 'a') return 1;
    else if (c == 'b') return 2;
    else if (c == 'c') return 3;
    else if (c == 'd') return 4;
    else if (c == 'e') return 5;
    else if (c == 'f') return 6;
    else if (c == 'g') return 7;
    else if (c == 'h') return 8;
    return -1;
}
 
int main() {
    char c;
    int r, n;
    cin >> c >> r >> n;
 
    int ci = bukvaDoBroj(c); //c int
 
    /*
        pozicija na konj: (c, r) [kolona i red]
        napadni pozicii: (c+2, r+1) (c+1, r+2) (c-1, r+2) (c-2, r+1) (c-2, r-1) (c-1, r-2) (c+1, r-2) (c+2, r-1)
    */
 
    //NAOGANJE NA NAPADNITE POZICII
    vector<pair<int, int>> napadniPoz;
    int relPoz[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (int i = 0; i < 8; i++) {
        //ako sekoja potencijalna pozicija ne e nadvor od granicite na sahovnata tabla, dodaj ja vo napadniPoz
        int c1 = ci + relPoz[i][0];
        int r1 = r + relPoz[i][1];
 
        if (c1 < 9 && c1 > 0 && r1 < 9 && r1 > 0) {
            napadniPoz.push_back(make_pair(c1, r1));
        }
    }
 
    /*
    cout << "konj: c=" << ci << "; r=" << r << endl;
    for (unsigned int i = 0; i < napadniPoz.size(); i++) {
        cout << "napadna pozicija: c=" << napadniPoz[i].first << "; r=" << napadniPoz[i].second << endl;
    }
    */
 
    int napadnati = 0;
 
    //ZEMANJE NA POZICIITE NA NEPRIJATELITE I ODLUCUVANJE DALI MOZAT DA BIDAT NAPADNATI
    for (int i = 0; i < n; i++) {
        char m; //kolona
        int k; //red
        cin >> m >> k;
 
        int mi = bukvaDoBroj(m); //m int
 
        //cout << "neprijatel: m=" << mi << "; k=" << k << endl;
 
        for (unsigned int npi = 0; npi < napadniPoz.size(); npi++) { //npi = napadna pozicija index
            pair<int, int> np = napadniPoz[npi];
 
            if (np.first == mi && np.second == k) { //ako koordinatite na napadnata pozicija se ednakvi so koord. na neprijatelot
                napadnati++;
            }
        }
    }
 
    cout << napadnati << endl;
}