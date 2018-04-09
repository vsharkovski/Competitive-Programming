#include <iostream>
#include <string>
 
using namespace std;
 
bool is_prime(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
 
int next_prime(int n) { //n is prime
    do {
        n += 2;
    } while (!is_prime(n));
 
    return n;
}
 
int main() {
    int N;
    cin >> N;
 
    //cout << is_prime(N);
 
    int N1 = N; //we will be doing all operations on this number
    int factor = 2; //smallest prime number
 
    do {
        static int exponent = 0;
        static bool FIRST = true;
 
        if (N1 % factor == 0) { //is n1 divisible with the factor?
            while (N1 % factor == 0) { //while above
                N1 /= factor; //divide n1 with the factor
                exponent++;
            }
 
            if (FIRST) {
                cout << "(" << factor << "^" << exponent << ")";
                FIRST = false;
            } else {
                cout << "*(" << factor << "^" << exponent << ")";
            }
 
            exponent = 0;
        }
 
        factor = factor == 2 ? 3 : next_prime(factor); //get next prime
 
    } while (N1 != 1);
 
}