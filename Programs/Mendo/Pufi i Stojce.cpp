#include <iostream>
 
int main() {
    int z, c, s;
    std::cin >> z >> c >>s;
 
    int blah = z + c + s;
    int bleh = blah;
 
    while (bleh % 3 != 0) {
        bleh++;
    }
 
    std::cout << bleh - blah;
 
    return 0;
}
