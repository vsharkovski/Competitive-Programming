#include <iostream>
#include <utility>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<pair<string,int>> iminja; //bi koristel set ama ima 100 iminja maksimum, pa ne mora
 
    int najveke = -1;
    string imeto = "";
 
    for (int i = 0; i < n; i++) {
        string ime;
        cin >> ime;
 
        bool najdeno = false;
 
        for (unsigned int x = 0; x < iminja.size(); x++) {
            if (iminja[x].first == ime) {
                najdeno = true;
 
                int broj = iminja[x].second;
                iminja[x].second++;
 
                if (broj > najveke) {
                    imeto = ime;
                    najveke = broj;
                }
 
                break;
            }
        }
 
        if (!najdeno) {
            iminja.push_back({ime, 1});
        }
 
    }
 
    cout << imeto << endl;
 
    return 0;
}
