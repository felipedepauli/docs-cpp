#include <iostream>



std::pair<int a, int b> dobraDois(int a, int b) {
    return std::make_pair(a * 2, b * 2);
}

int main(int argc, char *argv[]) {
    std::pair<int, int> p = dobraDois(1, 2);
    std::cout << "p.first: " << p.first << " p.second: " << p.second << std::endl;
    return 0;
}