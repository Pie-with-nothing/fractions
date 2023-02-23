#include "fractions.hpp"
#include <iostream>
int main(int argc, char const *argv[]){
    //Fract err ('1');
    //std::cout << err << std::endl;
    Fract q(13, -333);
    Fract w = std::string("2/1");
    Fract z = q;
    Fract f;
    Fract qqq(12, 4);
    Fract *www = &qqq;
    std::cout << (int)q << std::endl;
    std::cout << (std::string)q << std::endl;
    std::cout << -w << std::endl;
    std::cout << static_cast<std::string>(z) << std::endl;
    //std::cin >> f;
    //std::cout << "You entered " << f << std::endl;
    std::cout << "13/13vvvvv"_fr << std::endl;
    std::cout << -q - w << std::endl;
    std::cout << q / w << std::endl;
    std::cout << *www << std::endl;
    qqq *= z;
    std::cout << *www << std::endl;
    std::cout << (z == q) << std::endl;
    return 0;
}
