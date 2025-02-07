#include "Fraction.hpp"

Fraction::Fraction():Fraction(1, 1){}
Fraction::Fraction(const int num) :Fraction(num, num) {}
Fraction::Fraction(const int num, const int den)
{
	numerator_ = new Integer(num);
	denominator_ = new Integer(den);
}
Fraction::Fraction(Integer*& num) :Fraction(num, num) {}
Fraction::Fraction(Integer*& num, Integer*& den)
{
	numerator_ = num;
	denominator_ = den;
}
Fraction::Fraction(const std::string& num) :Fraction(num, num) {}
Fraction::Fraction(const std::string& num, const std::string& den)
{
	numerator_ = new Integer(num);
	denominator_ = new Integer(den);
}

Fraction::~Fraction()
{
	delete numerator_;
	delete denominator_;
}

const double Fraction::get() const
{
	if (denominator_ == 0)
	{
		throw "Zero Denominator in Fraction";
		return 0;
	}
	return numerator_->get() / denominator_->get();
}

inline const double Fraction::getResult() const
{
	return get();
}

Integer* Fraction::getNumerator() const
{
	return numerator_;
}

Integer* Fraction::getDenominator() const
{
	return denominator_;
}

void Fraction::set(const int num, const int den)
{
	numerator_->set(num);
	denominator_->set(den);
}

void Fraction::set(const std::string& num, const std::string& den)
{
	numerator_->set(num);
	denominator_->set(den);
}

const bool Fraction::isPositive() const
{
	return !isNegative();
}

const bool Fraction::isNegative() const
{
	return get() < 0.0;
}

const bool Fraction::isCorrect() const
{
	return !isIncorrect();
}

const bool Fraction::isIncorrect() const
{
	return *numerator_ >= *denominator_;
}

const bool Fraction::equalsNums() const
{
	return numerator_->equals(denominator_);
}

const Fraction Fraction::simplification() const
{
	return Fraction(denominator_->get(), numerator_->get());
}
const Fraction Fraction::reduction() const
{
	int j, less, num = numerator_->get(), den = denominator_->get();
	do {
		if (num < den)
			less = num;
		else
			less = den;
		for (j = less; j > 0; j--) {
			if (!(num % j) && !(den % j)) {
				num /= j;
				den /= j;
				break;
			}
		}
	} while (j != 1);
	return Fraction(num, den);
}

Fraction Fraction::clone()const
{
	return Fraction(numerator_->clone(), denominator_->clone());
}

void Fraction::reverse()
{
	std::swap(denominator_, numerator_);
}

Fraction& Fraction::operator++()
{
	*this += 1;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction oldFrac = clone();
	*this += 1;
	return oldFrac;
}

Fraction& Fraction::operator--()
{
	*this -= 1;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction oldFrac = clone();
	*this -= 1;
	return oldFrac;
}

Fraction::operator double() const
{
	return get();
}
const int Fraction::toInt() const
{
	return floor(get());
}
const std::string Fraction::toStdString() const
{
	return numerator_->get() + "/" + denominator_->get();
}

Fraction operator+(const Fraction& frac, const int i)
{
	Fraction clone = frac.clone();
	clone += i;
	return clone;
}

Fraction operator-(const Fraction& frac, const int i)
{
	Fraction clone = frac.clone();
	clone -= i;
	return clone;
}

Fraction operator*(const Fraction& frac, const int i)
{
	Fraction clone = frac.clone();
	clone *= i;
	return clone;
}

Fraction operator/(const Fraction& frac, const int i)
{
	Fraction clone = frac.clone();
	clone /= i;
	return clone;
}

Fraction operator%(const Fraction& frac, const int i)
{
	Fraction clone = frac.clone();
	clone %= i;
	return clone;
}

Fraction operator+(const Fraction& fracBase, const Fraction& i)
{
	Fraction clone = fracBase.clone();
	clone += i;
	return clone;
}

Fraction operator-(const Fraction& fracBase, const Fraction& i)
{
	Fraction clone = fracBase.clone();
	clone -= i;
	return clone;
}

Fraction operator*(const Fraction& fracBase, const Fraction& i)
{
	Fraction clone = fracBase.clone();
	clone *= i;
	return clone;
}

Fraction operator/(const Fraction& fracBase, const Fraction& i)
{
	Fraction clone = fracBase.clone();
	clone /= i;
	return clone;
}

Fraction operator%(const Fraction& fracBase, const Fraction& i)
{
	Fraction clone = fracBase.clone();
	clone %= i;
	return clone;
}

bool operator==(const Fraction& frac, const int i)
{
	return frac.get() == i;
}

bool operator!=(const Fraction& frac, const int i)
{
	return frac.get() != i;
}

bool operator>=(const Fraction& frac, const int i)
{
	return frac.get() >= i;
}

bool operator<=(const Fraction& frac, const int i)
{
	return frac.get() <= i;
}

bool operator>(const Fraction& frac, const int i)
{
	return frac.get() > i;
}

bool operator<(const Fraction& frac, const int i)
{
	return frac.get() < i;
}

bool operator==(const Fraction& fracBase, const Fraction& i)
{
	// return fracBase.get() == i.get();
	return *fracBase.numerator_ == *i.numerator_
		&& *fracBase.denominator_ == *i.denominator_;
}

bool operator!=(const Fraction& fracBase, const Fraction& i)
{
	return *fracBase.numerator_ != *i.numerator_
		&& *fracBase.denominator_ != *i.denominator_;
}

bool operator>=(const Fraction& fracBase, const Fraction& i)
{
	return *fracBase.numerator_ >= *i.numerator_
		&& *fracBase.denominator_ >= *i.denominator_;
}

bool operator<=(const Fraction& fracBase, const Fraction& i)
{
	return *fracBase.numerator_ <= *i.numerator_
		&& *fracBase.denominator_ <= *i.denominator_;
}

bool operator>(const Fraction& fracBase, const Fraction& i)
{
	return *fracBase.numerator_ > *i.numerator_
		&& *fracBase.denominator_ > *i.denominator_;
}

bool operator<(const Fraction& fracBase, const Fraction& i)
{
	return *fracBase.numerator_ < *i.numerator_
		&& *fracBase.denominator_ < *i.denominator_;
}

const Fraction& operator+=(const Fraction& frac, int i)
{
	*frac.numerator_ += i;
	return frac;
}

const Fraction& operator-=(const Fraction& frac, int i)
{
	*frac.numerator_ -= i;
	return frac;
}

const Fraction& operator*=(const Fraction& frac, int i)
{
	*frac.numerator_ *= i;
	return frac;
}

const Fraction& operator/=(const Fraction& frac, int i)
{
	*frac.numerator_ /= i;
	return frac;
}

const Fraction& operator%=(const Fraction& frac, int i)
{
	*frac.numerator_ %= i;
	return frac;
}

const Fraction& operator+=(const Fraction& fracBase, const Fraction& i)
{
	*fracBase.numerator_ += *i.numerator_;
	if (!fracBase.equalsNums())
		*fracBase.denominator_ += *i.denominator_;
	return fracBase;
}

const Fraction& operator-=(const Fraction& fracBase, const Fraction& i)
{
	*fracBase.numerator_ -= *i.numerator_;
	if (!fracBase.equalsNums())
		*fracBase.denominator_ -= *i.denominator_;
	return fracBase;
}

const Fraction& operator*=(const Fraction& fracBase, const Fraction& i)
{
	*fracBase.numerator_ *= *i.numerator_;
	if (!fracBase.equalsNums())
		*fracBase.denominator_ *= *i.denominator_;
	return fracBase;
}

const Fraction& operator/=(const Fraction& fracBase, const Fraction& i)
{
	*fracBase.numerator_ /= *i.numerator_;
	if (!fracBase.equalsNums())
		*fracBase.denominator_ /= *i.denominator_;
	return fracBase;
}

const Fraction& operator%=(const Fraction& fracBase, const Fraction& i)
{
	*fracBase.numerator_ %= *i.numerator_;
	if (!fracBase.equalsNums())
		*fracBase.denominator_ %= *i.denominator_;
	return fracBase;
}
