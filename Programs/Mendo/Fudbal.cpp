#include <iostream>
 
int main() {
    int N;
    std::cin >> N;
 
    int x = 0;
 
    for (int i = 0; i < N; i++) {
        int w, d, l;
        std::cin >> w >> d >> l;
 
        int p = w * 3 + d;
 
        x = p > x ? p : x;
    }
 
    std::cout << x << std::endl;
 
    return 0;
}
