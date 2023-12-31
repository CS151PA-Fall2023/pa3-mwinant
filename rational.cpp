/**
 * @file rational.cpp
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-09-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "rational.h"

//Rational Class Definitions
    Rational::Rational(){
        numerator = 1;
        denominator = 1;

    }
    Rational::Rational(int n, int d){
        numerator=n;
        if(d==0)
        {
            std::cout<< "Error, Attempting to Divide by Zero\n";
            exit(1);
        }
        else{
            denominator=d;
        }
    }
    Rational::Rational(const char *s){
        std::istringstream istr(s);
        char division;
        istr>>numerator>>division>>denominator;

    }
    Rational::Rational(const Rational& old){
        //std::cout<< "Copy constrctor is running ...\n";
        this->numerator=old.numerator;
        this->denominator=old.denominator;
    
    }
    Rational::~Rational(){
        //std::cout << "Destructor got called!\n";
    } 
    Rational::operator double(){
        return (double)numerator/(double)denominator;
    }
    Rational Rational::operator+(const Rational& r) {
        Rational addresult;
        addresult.numerator = r.denominator*numerator+(r.numerator*denominator);
        addresult.denominator = r.denominator*denominator;
        addresult.reduce();
        return addresult;
    } 
    Rational Rational::operator-(const Rational& r) {
        Rational subresult;
        subresult.numerator = r.denominator*numerator-(r.numerator*denominator);
        subresult.denominator = r.denominator*denominator;
        subresult.reduce();
        return subresult;
    }
    Rational Rational::operator*(const Rational& r) {
        Rational mulresult;
        mulresult.numerator= r.numerator*numerator;
        mulresult.denominator=r.denominator*denominator;
        mulresult.reduce();
        return mulresult;
    }
    Rational Rational::operator/(const Rational& r) {
        Rational divresult;
        divresult.numerator=r.denominator*numerator;
        divresult.denominator=r.numerator*denominator;
        divresult.reduce();
        return divresult; 
    }

    /**
     * @brief recduces the fraction to simplest form
     * 
     */
    void Rational::reduce(){
        int reduce=gcd(numerator, denominator);
        numerator/=reduce;
        denominator/=reduce;
    }

    /**
     * @brief helper function for reduce that finds the greatest common denominator
     * 
     * @param x 
     * @param y 
     * @return int 
     */
    int Rational::gcd(int x, int y)
    {
        if (y == 0) // base case
        {
            return x;
        }
        else // recursive case
        {
            return gcd(y, x % y);
        }
    }