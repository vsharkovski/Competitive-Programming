#include <iostream>
#include <vector>
#include <utility>
#include <set>
 
using namespace std;
 
//
bool ima(pair<int, int> &e, set<pair<int, int>> &s) {
    return s.find(e) != s.end();
}
 
//ovie mi trebaat ovde
int n, m, iteracii = 0, kocki_zemeni;
 
//
void zemi(set<pair<int, int>> &cokolado, vector<pair<int, int>> &to_do) {
 
    vector<pair<int, int>> next;
 
    for (unsigned int i = 0; i < to_do.size(); ++i) {
        int r = to_do[i].first;
        int k = to_do[i].second;
 
        //cout << "r:" << r << " k:" << k << endl;
        pair<int, int> rm = {r - 1, k};
        if (r - 1 >= 0 && !ima(rm, cokolado)) {
            cokolado.insert(rm);
            next.push_back(rm);
        }
 
        pair<int, int> rp = {r + 1, k};
        if (r + 1 < n && !ima(rp, cokolado)) {
            cokolado.insert(rp);
            next.push_back(rp);
        }
 
        pair<int, int> km = {r, k - 1};
        if (k - 1 >= 0 && !ima(km, cokolado)) {
            cokolado.insert(km);
            next.push_back(km);
        }
 
        pair<int, int> kp = {r, k + 1};
        if (k + 1 < m && !ima(kp, cokolado)) {
            cokolado.insert(kp);
            next.push_back(kp);
        }
    }
 
    if (next.size() != 0) {
        iteracii++;
 
        kocki_zemeni = next.size();
        to_do.clear();
 
        zemi(cokolado, next);
    }
}
 
//main
int main() {
    int pocetok_r, pocetok_k;
    cin >> n >> m >> pocetok_r >> pocetok_k;
 
    pair<int, int> pocetok = {pocetok_r - 1, pocetok_k - 1};
 
    set<pair<int, int>> cokolado = {pocetok};
    vector<pair<int, int>> pocetok_v = {pocetok};
 
    zemi(cokolado, pocetok_v);
 
    cout << iteracii << " " << kocki_zemeni << endl;
 
    return 0;
}
