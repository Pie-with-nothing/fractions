#include "fractions.hpp"
#include <iostream>
int main(int argc, char const *argv[]){
    Fract q(12, -4);
    Fract w = std::string("1/1");
    Fract z = q;
    Fract f;
    std::cout << q << std::endl;
    //std::cout << (std::string)q << std::endl;
    std::cout << w << std::endl;
    std::cout << z << std::endl;
    std::cout << "13/70vvvvv"_fr << std::endl;
    return 0;
}
