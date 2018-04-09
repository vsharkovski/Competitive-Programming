#include <iostream>
 
int main() {
    int P, K;
    std::cin >> P >> K;
 
    int br, brD = 0; //brojot sto se bara, brojot na deliteli na brojot sto se bara
 
    for (int x = P; x <= K; x++) {
 
        int brDt = 1; //x
 
        for (int i = 1; i < x; i++) {
            if (x % i == 0) {
                brDt++;
            }
        }
 
        if (brDt > brD) {
            brD = brDt;
            br = x;
        }
    }
 
    std::cout << br << " " << brD << std::endl;
 
    return 0;
}