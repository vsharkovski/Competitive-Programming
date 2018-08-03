#include <iostream>
 
int main() {
    int N;
    std::cin >> N;
 
    int anagrami = 0;
 
    for (int I = 0; I < N; I++) {
 
        int a, b;
        std::cin >> a >> b;
 
        int cA[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int cB[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        /*
        c[0] za 0, c[1] za 1, c[2] za 2, c[3] za 3, c[4] za 4, c[5] za 5 ... c[9] za 9
        */
 
        while (a > 0) {
            cA[a % 10]++; //a % 10 = cifra
            a /= 10;
        }
        while (b > 0) {
            cB[b % 10]++;
            b /= 10;
        }
 
        bool prekrsok = false;
 
        for (int i = 0; i < 10; i++) {
            if (cA[i] != cB[i]) {
                prekrsok = true;
                break;
            }
        }
 
        anagrami = (prekrsok) ? anagrami : anagrami + 1;
    }
 
    std::cout << anagrami << std::endl;
 
    return 0;
}
