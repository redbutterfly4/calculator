#ifndef RATIONAL_NUMBER_H_
#define RATIONAL_NUMBER_H_

#include <string>
#include <iostream>
#include <compare>

class RationalNumber
{
public:
    RationalNumber(int numerator = 0, unsigned denominator = 1);
    RationalNumber(const RationalNumber &other) = default;

    std::strong_ordering operator<=>(const RationalNumber &) const;
    std::strong_ordering operator<=>(int) const;

    bool operator==(const RationalNumber &) const;
    bool operator==(int) const;

    RationalNumber &operator=(const RationalNumber &other) = default;
    RationalNumber &operator=(int other);

    RationalNumber &operator+=(const RationalNumber &other);
    RationalNumber &operator+=(int other);

    RationalNumber &operator-=(const RationalNumber &other);
    RationalNumber &operator-=(int other);

    RationalNumber &operator*=(const RationalNumber &other);
    RationalNumber &operator*=(int other);

    RationalNumber &operator/=(const RationalNumber &other);
    RationalNumber &operator/=(int other);

    RationalNumber(RationalNumber &&other) = default;
    RationalNumber &operator=(RationalNumber &&other) = default;
    ~RationalNumber() = default;

    [[nodiscard]] std::string toString() const;

    void sum(const RationalNumber &);
    void sum(int);

    void subtract(const RationalNumber &);
    void subtract(int);

    void divide(const RationalNumber &);
    void divide(int);

    void multiply(const RationalNumber &);
    void multiply(int);

    RationalNumber operator+() const;
    RationalNumber operator-() const;

    RationalNumber operator+(const RationalNumber &) const;
    RationalNumber operator+(int) const;

    RationalNumber operator-(const RationalNumber &) const;
    RationalNumber operator-(int other) const;

    RationalNumber operator*(const RationalNumber &other) const;
    RationalNumber operator*(int other) const;

    RationalNumber operator/(const RationalNumber &other) const;
    RationalNumber operator/(int other) const;

    RationalNumber operator++();
    RationalNumber operator--();

private:
    int numerator_;
    unsigned int denominator_;
    void normalize();

    friend std::ostream &operator<<(std::ostream &, const RationalNumber &);
};

#endif // RATIONAL_NUMBER_H_