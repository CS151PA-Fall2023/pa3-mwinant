/**
 * @file rational.h
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-09-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <algorithm>

//Class Definition
class Rational
{
public:
    Rational(); //default constructor
    Rational(int n, int d); //convert constructors that accept two integers
    Rational(const char *s); //convert constructors that accept strings like "3/4"
    Rational(const Rational& old);
    ~Rational(); //destructor
    
    operator double(); //type conversion operator that gets invoked when you assign Rational datatype to double. 
    Rational operator+(const Rational& r);
    Rational operator-(const Rational& r);
    Rational operator*(const Rational& r);
    Rational operator/(const Rational& r);

    //overloads the stream insertion operator (<<).
    friend std::ostream& operator<<(std::ostream& os,const Rational& num){
        os << num.numerator << '/' << num.denominator;
    return os;
    }
    void reduce();
    int gcd(int x, int y);

private:
    int numerator;
    int denominator;

};


#endif