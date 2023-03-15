#include <iostream>
#include <utility>
#include <thread>



void funcExternal();

int num{2};

extern std::pair<int, std::string> myPair;
extern std::pair<int, std::string> myPair2[2];

int main() {

    funcExternal();

    std::cout << myPair.first << " x " << myPair.second << std::endl;

    std::cout << myPair2[0].first << " x " << myPair2[0].second << std::endl;
    std::cout << myPair2[1].first << " x " << myPair2[1].second << std::endl;














    return 0;
}