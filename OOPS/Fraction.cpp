#include<iostream>
using namespace std;
class Fraction{
    private:
    int numerator;
    int denominator;

    public:
    Fraction(int numerator, int denominator){
        // In order to differentiate member 
        // variables with parameters 
        this->numerator = numerator;
        this->denominator = denominator;  
    }
    void print(){
        cout<<numerator<<" "<<denominator<<endl;
    }
    Fraction add(Fraction const &f2) const{
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x*numerator + y*f2.numerator;
        // numerator = num ;
        // denominator = lcm;
        Fraction fNew(num, lcm);
        return fNew;
    }
    Fraction operator +(Fraction const &f2) const{
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x*numerator + y*f2.numerator;
        // numerator = num ;
        // denominator = lcm;
        Fraction fNew(num, lcm);
        return fNew;
    }
    void simplify(){
        int gcd=1;
        int j = min(numerator, denominator);
        for(int i=2;i<=j;i++){
            if(numerator%i==0&& denominator%i==0)
                gcd=i;
        }
        numerator=numerator/gcd;
        denominator=denominator/gcd;
    }
    Fraction multiply(Fraction const &f2) const{
        int num = numerator *f2.numerator;
        int den = denominator*f2.denominator;

        Fraction fNew(num, den);
        fNew.simplify();
        return fNew;
    }
    Fraction operator*(Fraction const &f2) const{
        int num = numerator *f2.numerator;
        int den = denominator*f2.denominator;

        Fraction fNew(num, den);
        fNew.simplify();
        return fNew;
    }
    bool operator==(Fraction const &f2){
        if(f2.numerator == numerator && f2.denominator == f2.denominator)
            return true;
        else 
            return false;
    }
    Fraction& operator++(){
        numerator = numerator + denominator;
        simplify();
        return *(this);
    }
    Fraction& operator++(int){
        Fraction fNew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }
    Fraction& operator +=(Fraction const &f2){
        int lcm = denominator*f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x*numerator + y*f2.numerator;
        numerator = num;
        denominator = lcm;
        simplify();
        return *(this);
    }
};

// int main(){
//     Fraction f1(10,2);
//     Fraction f2(15,4);

//     Fraction f3 = f1.add(f2);
//     Fraction f4 = f1+f2;
//     // f1.print();
//     // f2.print();
//     f3.print();
//     f4.print();

//     Fraction f5 = f1*f2; 
//     // f1.print();
//     // f2.print();
//     f5.print();

//     cout<<(f1==f2);
// }