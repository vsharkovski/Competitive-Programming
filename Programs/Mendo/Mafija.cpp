#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int suma_lokacii = 0;
    vector<int> lokacii;
 
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
 
        suma_lokacii += p;
        lokacii.push_back(p);
    }
 
    double arigm_lokacii = suma_lokacii / n;
    double min_rast = 1001;
    int min_rast_lokacija;
 
    for (unsigned int i = 0; i < (unsigned)n; ++i) {
        int p = lokacii[i];
 
        double rast = arigm_lokacii >= p ? arigm_lokacii - p : p - arigm_lokacii;
        if (rast < min_rast) {
            min_rast = rast;
            min_rast_lokacija = p;
        }
    }
 
    cout << min_rast_lokacija << endl;
}
