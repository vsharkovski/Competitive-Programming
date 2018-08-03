#include <iostream>
 
int main() {
    int a, b;
    std::cin >> a >> b;
 
    a = (a % 2 == 0) ? a + 1 : a;
    b = (b % 2 == 0) ? b - 1 : b;
 
    int sum = 0;
 
    for (int i = a; i <= b; i += 2) {
        sum += i;
    }
 
    std::cout << sum << '\n';
}
