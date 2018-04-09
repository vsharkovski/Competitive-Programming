#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    vector<int> v;
 
    int last;
    cin >> last;
    while (last != 3) {
        v.push_back(last);
        cin >> last;
    }
 
    int r = 2, k = -1;  //r=2 bidejki ne mora da gi broi prviot i posledniot red
                        //k=-1 bidejki posledniot broj e od sledniot red, pa sekogas ima 1 ekstra
 
    bool bk = false; //dali se izbroeni kolonite
 
    for (int i = 0; i < v.size(); i++) {
        if (!bk) k++;
 
        if (v[i] == 1) {
            if (v[i + 1] == 2) {
                r++;
                bk = true;
            }
        }
    }
 
    cout << r << " " << k << endl;
 
    return 0;
}