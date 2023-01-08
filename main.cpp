#include "fractions.hpp"
#include <iostream>
int main(int argc, char const *argv[]){
    Fract q(12, -4);
    Fract w = std::string("1/1");
    std::cout << q << std::endl;
    //std::cout << (std::string)q << std::endl;
    std::cout << "13/70vvvvv"_fr << std::endl;
    std::cout << w << std::endl;
    return 0;
}
