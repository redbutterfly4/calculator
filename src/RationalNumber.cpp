#include "RationalNumber.h"

#include <numeric>

void RationalNumber::normalize()
{
    if (numerator_ == 0) {
        denominator_ = 1;
        return;
    }

    const int gcd = static_cast<int>(std::gcd(numerator_, denominator_));

    if (gcd > 1) {
        numerator_ /= gcd;
        denominator_ /= gcd;
    }
}

RationalNumber::RationalNumber(const int numerator, const unsigned denominator)
    : numerator_(numerator), denominator_(denominator)
{
    normalize();
}

std::strong_ordering RationalNumber::operator<=>(const RationalNumber &other) const
{
    const long long lhs = numerator_ * 1LL * other.denominator_;
    const long long rhs = denominator_ * 1LL * other.numerator_;
    return lhs <=> rhs;
}

std::strong_ordering RationalNumber::operator<=>(int other) const
{
    const long long rhs = other * 1LL * denominator_;
    const long long lhs = numerator_ * 1LL;
    return lhs <=> rhs;
}

std::string RationalNumber::toString() const
{
    return std::to_string(numerator_) + " / " + std::to_string(denominator_);
}

RationalNumber RationalNumber::operator+() const
{
    return { *this };
}

void RationalNumber::sum(const RationalNumber &other)
{
    const unsigned denominator = std::lcm(denominator_, other.denominator_);

    const int numerator = static_cast<int>((numerator_ * (denominator / denominator_)))
            + static_cast<int>((other.numerator_ * (denominator / other.denominator_)));

    numerator_ = numerator;
    denominator_ = denominator;

    normalize();
}

void RationalNumber::sum(const int other)
{
    numerator_ += static_cast<int>(other * denominator_);
    normalize();
}

void RationalNumber::subtract(const RationalNumber &other)
{
    this->sum(-other);
}

void RationalNumber::subtract(const int other)
{
    this->sum(-other);
}

void RationalNumber::divide(const RationalNumber &other)
{
    if (other.numerator_ == 0) {
        throw std::invalid_argument("Can't divide by zero");
    }

    numerator_ *= static_cast<int>(other.denominator_);

    if (other.numerator_ < 0) {
        denominator_ *= -other.numerator_;
        numerator_ *= -1;
    } else {
        denominator_ *= other.numerator_;
    }

    normalize();
}

void RationalNumber::divide(const int other)
{
    denominator_ *= other;
    normalize();
}

void RationalNumber::multiply(const RationalNumber &other)
{
    numerator_ *= other.numerator_;
    denominator_ *= other.denominator_;
    normalize();
}

void RationalNumber::multiply(const int other)
{
    numerator_ *= other;
    normalize();
}

bool RationalNumber::operator==(const RationalNumber &other) const
{
    return (this == &other)
            ? true
            : ((numerator_ == other.numerator_) && (denominator_ == other.denominator_));
}

RationalNumber RationalNumber::operator+(const RationalNumber &other) const
{
    RationalNumber result = *this;
    result.sum(other);
    return result;
}

RationalNumber RationalNumber::operator+(const int other) const
{
    RationalNumber result = *this;
    result.sum(other);
    return result;
}

RationalNumber RationalNumber::operator-() const
{
    return { -numerator_, denominator_ };
}

std::ostream &operator<<(std::ostream &stream, const RationalNumber &num)
{
    stream << num.toString();
    return stream;
}

RationalNumber RationalNumber::operator-(const RationalNumber &other) const
{
    RationalNumber result = *this;
    result.subtract(other);
    return result;
}

RationalNumber RationalNumber::operator-(const int other) const
{
    RationalNumber result = *this;
    result.subtract(other);
    return result;
}

RationalNumber RationalNumber::operator*(const RationalNumber &other) const
{
    RationalNumber result = *this;
    result.multiply(other);
    return result;
}

RationalNumber RationalNumber::operator*(const int other) const
{
    RationalNumber result = *this;
    result.multiply(other);
    return result;
}

RationalNumber RationalNumber::operator/(const RationalNumber &other) const
{
    if (other.numerator_ == 0) {
        throw std::invalid_argument("Can't divide by zero");
    }
    RationalNumber result = *this;
    result.divide(other);
    return result;
}

RationalNumber RationalNumber::operator/(const int other) const
{
    if (other == 0) {
        throw std::invalid_argument("Can't divide by zero");
    }
    RationalNumber result = *this;
    result.divide(other);
    return result;
}

RationalNumber &RationalNumber::operator=(const int other)
{
    numerator_ = other;
    denominator_ = 1;
    return *this;
}

RationalNumber &RationalNumber::operator+=(const RationalNumber &other)
{
    this->sum(other);
    return *this;
}

RationalNumber &RationalNumber::operator+=(const int other)
{
    this->sum(other);
    return *this;
}

RationalNumber &RationalNumber::operator-=(const RationalNumber &other)
{
    this->subtract(other);
    return *this;
}

RationalNumber &RationalNumber::operator-=(const int other)
{
    this->subtract(other);
    return *this;
}

RationalNumber &RationalNumber::operator*=(const RationalNumber &other)
{
    this->multiply(other);
    return *this;
}

RationalNumber &RationalNumber::operator*=(const int other)
{
    this->multiply(other);
    return *this;
}

RationalNumber &RationalNumber::operator/=(const RationalNumber &other)
{
    this->divide(other);
    return *this;
}

RationalNumber &RationalNumber::operator/=(const int other)
{
    this->divide(other);
    return *this;
}

bool RationalNumber::operator==(const int other) const
{
    return (denominator_ == 1 && numerator_ == other);
}

RationalNumber RationalNumber::operator++()
{
    numerator_ += static_cast<int>(denominator_);
    normalize();
    return *this;
}

RationalNumber RationalNumber::operator--()
{
    numerator_ -= static_cast<int>(denominator_);
    normalize();
    return *this;
}
