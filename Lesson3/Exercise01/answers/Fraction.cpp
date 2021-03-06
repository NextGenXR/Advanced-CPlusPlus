//============================================================================
// Name        : Fraction.cpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Exercise 1 Lesson 3
//============================================================================
#include "Fraction.hpp"
#include <cmath>
#include <numeric>
#include <stdexcept>

namespace {
inline int signum(int val) {
    return (0 < val) - (val < 0);
}

}

Fraction::Fraction(int numerator, int denominator) : m_numerator{numerator}, m_denominator{denominator}
{
    if(m_denominator == 0) {
        throw std::domain_error("Zero Denominator");
    }
    int sign{(signum(m_numerator)*signum(m_denominator))};
    m_numerator = std::abs(m_numerator);
    m_denominator = std::abs(m_denominator);

    int divisor{std::gcd(m_numerator, m_denominator)};
    m_numerator = sign * m_numerator / divisor;
    m_denominator = m_denominator / divisor;
}

Fraction& Fraction::operator*=(const Fraction& rhs)
{
    Fraction tmp(m_numerator*rhs.m_numerator, m_denominator*rhs.m_denominator);
    *this = tmp;
    return *this;
}

Fraction& Fraction::operator+=(const Fraction& rhs)
{
    int num{m_numerator*rhs.m_denominator +  m_denominator*rhs.m_numerator};
    Fraction tmp(num, m_denominator*rhs.m_denominator);
    *this = tmp;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& rhs)
{
    int num{m_numerator*rhs.m_denominator -  m_denominator*rhs.m_numerator};
    Fraction tmp(num, m_denominator*rhs.m_denominator);
    *this = tmp;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& rhs)
{
    if (rhs.m_numerator == 0)
    {
        throw std::runtime_error("Fraction Divide By Zero");
    }
    Fraction tmp(m_numerator*rhs.m_denominator, m_denominator*rhs.m_numerator);
    *this = tmp;
    return *this;
}
