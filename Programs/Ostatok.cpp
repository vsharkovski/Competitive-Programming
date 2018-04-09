#include <iostream>
#include <vector>
 
int main() {
    std::vector<int> r;
 
    for (int I = 0; I < 10; I++) {
        int n;
        std::cin >> n;
 
        int x = n % 42;
 
        bool najdeno = false;
 
        for (unsigned int i = 0; i < r.size(); i++) {
            if (r[i] == x) {
                najdeno = true;
                break;
            }
        }
 
        if (najdeno == false) {
            r.push_back(x);
        }
    }
 
    std::cout << r.size() << std::endl;
}