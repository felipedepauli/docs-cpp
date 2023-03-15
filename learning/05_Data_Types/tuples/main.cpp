#include <iostream>
#include <string>
#include <map>
#include <tuple>

int main() {
    std::map<std::tuple<std::string, int, std::string>, double> pessoas;
    
    std::tuple<std::string, int, std::string> pessoa1 = std::make_tuple("João", 25, "Rua A");
    std::tuple<std::string, int, std::string> pessoa2 = std::make_tuple("Maria", 30, "Rua B");
    
    pessoas[pessoa1] = 1000.0;
    pessoas[pessoa2] = 2000.0;
    
    std::cout << "Salário de João: " << pessoas[pessoa1] << std::endl;
    std::cout << "Salário de Maria: " << pessoas[pessoa2] << std::endl;
    
    return 0;
}