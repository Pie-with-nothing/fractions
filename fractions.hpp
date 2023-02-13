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
        Fract(const Fract &another) = default;
        Fract(Fract &&another) = default;
        Fract &operator=(const Fract &another) = default;
        Fract &operator=(Fract &&another) = default;
        Fract(const std::string str_fract);
        ~Fract() = default;
        friend Fract operator"" _fr(const char* chr_str, size_t size);
        //out
        friend std::ostream &operator<<(std::ostream &out, const Fract &frac);
};
Fract operator"" _fr(const char* chr_str, size_t size);

inline unsigned int NOD(unsigned int x, unsigned int y){
    int div;
    int diff;
    if(x == y){
        return x;
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