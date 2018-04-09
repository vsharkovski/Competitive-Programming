#include <iostream>
 
int main() {
    int H, U, D; //pat, pat preku den, pat preku nok
    std::cin >> H >> U >> D;
 
    int d = 0; // denovi
    int Hi = 0; //pat izminat
 
    for (;;) {
        d++;
        Hi += U;
        if (Hi >= H) break;
        Hi -= D;
    }
 
    std::cout << d << std::endl;
 
    return 0;
}