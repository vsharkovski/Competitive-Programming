#include <iostream>
using namespace std;
 
int main() {
    long long int K;
    cin >> K;
 
    if (K == 1 || K == 2) {
        cout << K << endl;
    } else {
    for (long long int i = 0; i < K; ++i) {
        if (i*(i+1)/2 == K) {
            cout << i << endl;
            break;
        }
    }}
 
}