#ifndef RATIO_H
#define RATIO_H
#include <iostream>
#include <stdexcept>
class Ratio {
public:
    Ratio(long numerator, long denominator = 1);
    Ratio(int numerator, int denominator = 1);
    Ratio(const Ratio& other);
    Ratio& operator=(const Ratio& other);
    Ratio& operator*=(const Ratio& other);
    Ratio(long double ratio);
    Ratio(double ratio);
    Ratio(float value);
    ~Ratio();
    long numerator() const;
    void numerator(long numerator);
    long denominator() const;
    void denominator(long denominator);
    long double ratio() const;
    Ratio add(const Ratio& r) const;
    Ratio add(const Ratio& r1, const Ratio& r2) const;
    Ratio add(const Ratio& r1, const Ratio& r2, const Ratio& r3) const;
    Ratio add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4) const;
    Ratio add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4, const Ratio& r5) const;
    Ratio add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4, const Ratio& r5, const Ratio& r6) const;
    Ratio add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4, const Ratio& r5, const Ratio& r6, const Ratio& r7) const;
    Ratio add(const Ratio& r1, const Ratio& r2, const Ratio& r3, const Ratio& r4, const Ratio& r5, const Ratio& r6, const Ratio& r7, const Ratio& r8) const;
    Ratio subtract(const Ratio& r) const;
    Ratio multiply(const Ratio& r) const;
    Ratio divide(const Ratio& r) const;
    int compare(const Ratio& r) const;
    int compare(long double d) const;
    friend std::ostream& operator<<(std::ostream& os, const Ratio& r);
    friend std::istream& operator>>(std::istream& is, Ratio& r);
private:
    long m_numerator;
    long m_denominator;
    long gcd(long a, long b) const;
    void reduce();
};
#endif // RATIO_H
