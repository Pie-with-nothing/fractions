#include "fractions.hpp"
#include <iostream>
#include <stdexcept>
#include <cstring>

Fract::Fract(int num, int denum){
    std::pair <int, int> red_frac = reduce(num, denum);
    this->numer = red_frac.first;
    this->denumer = red_frac.second;
}
//Fract::Fract() : Fract(0){}
Fract::Fract(){
    this->numer = 0;
    this->denumer = 1;
}

Fract::Fract(const std::string str_fract){
    Fract f = gen_from_str(str_fract);
    this->numer = f.numer;
    this->denumer = f.denumer;
}

Fract Fract::gen_from_str(const std::string str_fract){
    Fract frac;
    short n = str_fract.find('/');
    if(n == -1){
        frac.numer = std::stoi(str_fract);
    }
    else{
        frac.numer = std::stoi(str_fract.substr(0, n));
        frac.denumer = std::stoi(str_fract.substr(n + 1));
    }
    Fract need_ret = frac;
    return need_ret;  
}

Fract operator"" _fr(const char* chr_str, size_t size){
    std::string str(chr_str, size);
    return Fract::gen_from_str(str);
}

std::istream &operator>>(std::istream &in, Fract &frac){
    std::string str;
    in >> str;
    frac = Fract::gen_from_str(str);
    return in;
}

std::pair <int, int> Fract::reduce(int num, int denum){
    std::pair <int, int> red;
    if(denum == 0){
        throw std::invalid_argument("Dividing by zero");
    }
    short int sign = (num / abs(num)) * (denum / abs(denum));
    int nod = NOD(abs(num), abs(denum));
    red.first = nod != 0 ? sign * abs(num) / nod : sign * abs(num);
    red.second = nod != 0 ? abs(denum) / nod : abs(denum);
    return red;
}
std::ostream &operator<<(std::ostream &os, const Fract &frac){
    if(frac.denumer != 1){
        return os << frac.numer << "/" << frac.denumer;
    }
    else{
        return os << frac.numer;
    }
}

Fract::operator float() const{
    return float(this->numer) / float(this->denumer);
}

Fract::operator double() const{
    return double(this->numer) / double(this->denumer);
}

Fract::operator int() const{
    return int(float(*this));
}

Fract::operator std::string() const{
    std::string str = std::to_string(this->numer);
    if(this->denumer != 1){
        str += "/" + std::to_string(this->denumer);
    }
    return str;
}