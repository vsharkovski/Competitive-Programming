#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    for (int I = 0; I < n; I++) {
        string S, T;
        cin >> S >> T;
 
        int itarget = 0;
        char target = S[itarget];
        char current;
        string S1 = "";
 
        for (unsigned int i = 0; i < T.length(); i++) {
            current = T[i];
            //cout << "i: " << i << ", current: " << current << endl;
            if (current == target) {
                S1 += current;
                itarget++;
                target = S[itarget];
                //cout << "new S1: " << S1 << ", new itarget: " << itarget << ", new target: " << target << endl;
            }
        }
 
        if (S1 == S) {
            cout << "DA";
        } else {
            cout << "NE";
        }
        //ternary operator (?:) ne raboti??
 
        cout << endl;
    }
}