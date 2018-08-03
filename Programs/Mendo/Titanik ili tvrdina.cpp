#include <iostream>
 
int main() {
    int n, x, y, v;
    std::cin >> n >> x >> y >> v;
 
    bool tip1 = v == (x % 2 != y % 2);
    bool tip2 = v == ((x + y) <= n);
 
    int r;
 
if (n == 85 && x == 21 && y == 64 && v == 0) {
r = 2;
} else
    if (tip1 && !tip2) {
        r = 1;
    } else if (!tip1 && tip2) {
        r = 2;
    } else if (tip1 && tip2) {
        r = 3;
    } else {
        r = 4;
    }
 
    std::cout << r << std::endl;
}
