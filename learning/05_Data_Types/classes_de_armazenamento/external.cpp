#include <iostream>
#include <utility>


extern int num;

std::pair<int, std::string> myPair;
std::pair<int, std::string> myPair2[2];

void funcExternal() {
    std::cout << "The number is " << num << std::endl;

    myPair.first    = 2;
    myPair.second   = "satanas";
    myPair2[0]        = std::make_pair(3, "jesus cristo");
    myPair2[1]        = std::make_pair(4, "barrabas caótico");
}