#include "fractions.hpp"
#include <iostream>
#include <stdexcept>
#include <cstring>

Fract::Fract(int num, int denum){
    std::pair <int, int> red_frac = reduce(num, denum);
    this->numer = red_frac.first;
    this->denumer = red_frac.second;
}
Fract::Fract() : Fract(0){}

Fract::Fract(const std::string str_fract){
    Fract f = gen_from_str(str_fract);
    this->numer = f.numer;
    this->denumer = f.denumer;
}
Fract Fract::gen_from_str(const std::string str_fract){
    Fract frac;
    std::pair <int, int> red_frac;
    short n = str_fract.find('/');
    if(n == -1){
        frac.numer = std::stoi(str_fract);
    }
    else{
        red_frac = reduce(
                        std::stoi(str_fract.substr(0, n)),
                        std::stoi(str_fract.substr(n + 1))
                        );
        frac.numer = red_frac.first;
        frac.denumer = red_frac.second;
    }
    return frac;
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
Fract operator+(const Fract &self){
    Fract copy = self;
    return copy;
}
Fract operator-(const Fract &self){
    Fract copy;
    copy.numer = -self.numer;
    copy.denumer = self.denumer;
    return copy;
}
Fract operator+(const Fract &self, const Fract &another){
    int num = (self.numer * another.denumer +
               another.numer * self.denumer);
    int den = self.denumer * another.denumer;
    return Fract(num, den);
}
Fract operator-(const Fract &self, const Fract &another){
    return self + (-another);
}
Fract operator*(const Fract &self, const Fract &another){
    int num = self.numer * another.numer;
    int den = self.denumer * another.denumer;
    return Fract(num, den);
}
Fract operator/(const Fract &self, const Fract &another){
    int num = self.numer * another.denumer;
    int den = self.denumer * another.numer;
    return Fract(num, den);
}
Fract operator+=(Fract &self, const Fract &another){
    self = self + another;
    return self;
}
Fract operator-=(Fract &self, const Fract &another){
    self = self - another;
    return self;
}
Fract operator*=(Fract &self, const Fract &another){
    self = self * another;
    return self;
}
Fract operator/=(Fract &self, const Fract &another){
    self = self / another;
    return self;
}
bool operator==(const Fract &self, const Fract &another){
    return (
        self.numer == another.numer &&
        self.denumer == another.denumer);
}
bool operator!=(const Fract &self, const Fract &another){
    return (
        self.numer != another.numer ||
        self.denumer != another.denumer);
}
bool operator<(const Fract &self, const Fract &another){
    return (
        self.numer * another.denumer <
        another.numer * self.denumer);
}
bool operator>(const Fract &self, const Fract &another){
    return (
        self.numer * another.denumer >
        another.numer * self.denumer);
}
bool operator>=(const Fract &self, const Fract &another){
    return self > another || self == another;
}
bool operator<=(const Fract &self, const Fract &another){
    return self < another || self == another;
}