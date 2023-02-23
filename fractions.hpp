#pragma once
#include <iostream>
#include <utility>

class Fract{
    private:
        int numer;
        int denumer;
        static Fract gen_from_str(const std::string str_fract);
    public:
        static std::pair <int, int> reduce(int num, int denum);
        //constuct
        Fract();
        Fract(int num, int denum = 1);
        Fract(char no_need) = delete;
        Fract(float no_need) = delete;
        Fract(double no_need) = delete;
        Fract(const Fract &another) = default;
        Fract(Fract &&another) = default;
        Fract &operator=(const Fract &another) = default;
        Fract &operator=(Fract &&another) = default;
        Fract(const std::string str_fract);
        ~Fract() = default;
        friend Fract operator"" _fr(const char* chr_str, size_t size);
        friend std::istream &operator>>(std::istream &in, Fract &frac);
        //out
        friend std::ostream &operator<<(std::ostream &out, const Fract &frac);
        //types
        operator int() const;
        operator float() const;
        operator double() const;
        operator std::string() const;
        //unar arith
        friend Fract operator+(const Fract &self);
        friend Fract operator-(const Fract &self);
        //binar arith
        friend Fract operator+(const Fract &self, const Fract &another);
        friend Fract operator-(const Fract &self, const Fract &another);
        friend Fract operator*(const Fract &self, const Fract &another);
        friend Fract operator/(const Fract &self, const Fract &another);
        //arith wth assig
        friend Fract operator+=(Fract &self, const Fract &another);
        friend Fract operator-=(Fract &self, const Fract &another);
        friend Fract operator*=(Fract &self, const Fract &another);
        friend Fract operator/=(Fract &self, const Fract &another);
        //compare
        friend bool operator==(const Fract &self, const Fract &another);
        friend bool operator!=(const Fract &self, const Fract &another);
        friend bool operator>(const Fract &self, const Fract &another);
        friend bool operator<(const Fract &self, const Fract &another);
        friend bool operator>=(const Fract &self, const Fract &another);
        friend bool operator<=(const Fract &self, const Fract &another);
};
Fract operator"" _fr(const char* chr_str, size_t size);

inline unsigned int NOD(unsigned int x, unsigned int y){
    int div;
    int diff;
    if(x == y || y == 1){
        return y;
    }
    diff = x - y;
    if(diff < 0){
        div = NOD(x, -diff);
    }
    else{
        div = NOD(y, diff);
    }
    return div;
};