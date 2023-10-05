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

//Class Definitions
    Rational::Rational(){
        numerator = 1;
        denominator = 1;
        reduce();
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
        int num;
        int denom;
        char division;
        istr>>num>>division>>denom;
        numerator=num;
        denominator=denom;

    }
    Rational::Rational(const Rational& old){
        //std::cout<< "Copy constrctor is running ...\n";
        this->numerator=old.numerator;
        this->denominator=old.denominator;
    
    }
    Rational::~Rational(){
        //std::cout << "Destructor got called!\n";
    }
    //type conversion operator that gets invoked when you assign Rational datatype to double. 
    Rational::operator double(){
        return (double)numerator/(double)denominator;
    }
    Rational& Rational::operator+(const Rational& r) {
        Rational result;
        result.numerator = r.denominator*numerator+(r.numerator*denominator);
        result.denominator = r.denominator*denominator;
        result.reduce();
        return result;
    }  
    Rational& Rational::operator-(const Rational& r) {
        Rational result;
        result.numerator = r.denominator*numerator-(r.numerator*denominator);
        result.denominator = r.denominator*denominator;
        result.reduce();
        return result;
    }
    Rational& Rational::operator*(const Rational& r) {
        Rational result;
        result.numerator= r.numerator*numerator;
        result.denominator=r.denominator*denominator;
        result.reduce();
        return result;
    }
    Rational& Rational::operator/(const Rational& r) {
        Rational result;
        result.numerator=r.denominator*numerator;
        result.denominator=r.numerator*denominator;
        result.reduce();
        return result; 
    }

    void Rational::reduce(){
        int n = numerator;
        int d = denominator;
        int largest = n > d ? n : d;

        int gcd = 0; // greatest common divisor

        for (int loop = largest; loop >= 2; loop--)
            if (numerator % loop == 0 && denominator % loop == 0) {
                gcd = loop;
                break;
            }

            if (gcd != 0) {
                numerator /= gcd;
                denominator /= gcd;
            }
    }


