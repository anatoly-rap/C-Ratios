#include "Ratio.h"
#include <cmath> 
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Ratio::Ratio(long numerator, long denominator):m_numerator{ numerator }, m_denominator{ denominator } {
    if (m_denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}
Ratio::Ratio(int numerator, int denominator):Ratio(static_cast<long>(numerator), static_cast<long>(denominator)){}

Ratio::Ratio(float value) {
    *this = Ratio(static_cast<long double>(value));
}

Ratio::Ratio(double value) {
    *this = Ratio(static_cast<long double>(value));
}

Ratio::Ratio(long double value) {
    m_numerator = static_cast<long>(std::round(std::fabs(value) * 1000000000));
    m_denominator = 1000000000;
    if (value < 0) {
        m_numerator = -m_numerator;
    }
    reduce();
}

Ratio::Ratio(const Ratio& other):m_numerator{ other.m_numerator },
      m_denominator{other.m_denominator } {}

Ratio& Ratio::operator=(const Ratio& other) {
    m_numerator = other.m_numerator;
    m_denominator = other.m_denominator;
    return *this;
}

Ratio::~Ratio() {}
void Ratio::reduce(){
    long a = abs(m_numerator);
    long b = m_denominator;
    while (b != 0) {
        long r = a % b;
        a = b;
        b = r;
    }
    long gcd = a;
    m_numerator /= gcd;
    m_denominator /= gcd;
    if (m_denominator < 0){
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }
}
long Ratio::numerator() const {
    return m_numerator;
}

void Ratio::numerator(long numerator){
    m_numerator = numerator;
    reduce();
}

long Ratio::denominator() const {
    return m_denominator;
}

void Ratio::denominator(long denominator) {
    if (denominator == 0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    m_denominator = denominator;
    reduce();
}
long double Ratio::ratio() const {
    return static_cast<long double>(m_numerator) / static_cast<long double>(m_denominator);
}
Ratio& Ratio::operator*=(const Ratio& other) {
    m_numerator *= other.m_numerator;
    m_denominator *= other.m_denominator;
    reduce();
    return *this;
}
Ratio Ratio::add(const Ratio& r) const {
    long numerator = m_numerator * r.m_denominator + r.m_numerator * m_denominator;
    long denominator = m_denominator * r.m_denominator;
    return Ratio(numerator, denominator);
}

Ratio Ratio::add(const Ratio& r1, const Ratio& r2) const {
    Ratio result = add(r1);
    result = result.add(r2);
    return result;
}
Ratio Ratio::add(const Ratio& r1, const Ratio& r2, const Ratio& r3) const {
    return add(r1, r2).add(r3);
}

Ratio Ratio::add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4) const {
    return add(r1, r2, r3).add(r4);
}

Ratio Ratio::add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4, const Ratio& r5) const {
    return add(r1, r2, r3, r4).add(r5);
}

Ratio Ratio::add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4, const Ratio& r5, const Ratio& r6) const {
    return add(r1, r2, r3, r4, r5).add(r6);
}

Ratio Ratio::add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4, const Ratio& r5, const Ratio& r6, const Ratio& r7) const {
    return add(r1, r2, r3, r4, r5, r6).add(r7);
}
Ratio Ratio::add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4, const Ratio& r5, const Ratio& r6, const Ratio& r7, const Ratio& r8) const {
    return add(r1, r2, r3, r4, r5, r6, r7).add(r8);
}

Ratio Ratio::subtract(const Ratio& r) const {
    Ratio result(m_numerator * r.m_denominator - r.m_numerator * m_denominator, m_denominator * r.m_denominator);
    return result;
}

Ratio Ratio::multiply(const Ratio& r) const {
    long num = numerator() * r.numerator();
    long den = denominator() * r.denominator();
    return Ratio(num, den);
}

Ratio Ratio::divide(const Ratio& r) const {
    if (r.numerator() == 0) {
        throw std::invalid_argument("division by zero");
    }
    Ratio result(m_numerator * r.denominator(), m_denominator * r.numerator());
    return result;
}

int Ratio::compare(const Ratio& r) const {
    long double d1 = ratio();
    long double d2 = r.ratio();
    return (d1 > d2) ? 1 : ((d1 < d2) ? -1 : 0);
}

int Ratio::compare(long double d) const {
    long double d1 = ratio();
    return (d1 > d) ? 1 : ((d1 < d) ? -1 : 0);
}

ostream& operator<<(std::ostream& os, const Ratio& r) {
    os << r.numerator() << "/" << r.denominator();
    return os;
}

    istream& operator>>(std::istream& is, Ratio& r) {
    int num, den;
    char c;
    if (is >> num >> c >> den) {
        if (c == '/') {
            r = Ratio(num, den);
        } else {
            is.setstate(std::ios::failbit);
        }
    }
    return is;
}
