#include <iostream>
#include <set>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }
 
    int passed = 0; //vkupno pat pominat
    int i = 0; //broj na knigi zemeni (odi 0, 1, 2, ..., m, 0, 1, 2, ..., m, 0...)
    int most_distant = 0; //naj dalecnata kniga od grupata m knigi
 
    multiset<int>::reverse_iterator rit;
    for (rit = h.rbegin(); rit != h.rend(); ++rit) {
        int x = *rit;
 
        if (x > most_distant) {
            //cout << "nov most_distant:" << x << " | " ;
            most_distant = x;
        }
 
        //cout << "i:" << i << " x:" << x << " | ";
 
        if (i == m - 1 || next(rit, 1) == h.rend()) { //ako sme na poslednata iteracija ILI sme na posledniot element
            passed += 2 * most_distant; //dodaj go patot
            //cout << "passed e sega " << passed;
            i = 0;
            most_distant = 0;
        } else {
            ++i;
        }
        //cout << endl;
    }
 
    cout << passed << endl;
}
