#include <iostream>
#include <map>

typedef enum {
    COLOR  = 0,
    SIZE   = 1,
    WIDTH  = 2,
    HEIGHT = 3,
    NAME   = 4,
} conf_t;


int main(int argc, char *argv[]) {

    std::map<conf_t, std::string> conf;

    conf[COLOR]  = "red";
    conf[SIZE]   = "big";
    conf[WIDTH]  = "100";
    conf[HEIGHT] = "200";
    conf[NAME]   = "Felipe";

    typedef std::map<conf_t, std::string>::iterator it_type;

    std::cout << conf[COLOR] << std::endl;
    std::cout << conf[SIZE] << std::endl;
    std::cout << conf[WIDTH] << std::endl;
    std::cout << conf[HEIGHT] << std::endl;
    std::cout << conf[NAME] << std::endl;


    return 0;
}