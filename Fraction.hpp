#ifndef FRACTION_HPP
#define FRACTION_HPP
#include "Integer.hpp";

class Fraction
{
public:
	Fraction();
	Fraction(Integer*&);
	Fraction(Integer*&, Integer*&);
	Fraction(const int);
	Fraction(const int, const int);
	Fraction(const std::string&);
	Fraction(const std::string&, const std::string&);
	~Fraction();

	operator double() const;
	const int toInt()const;
	const std::string toStdString() const;

	const double get()const;
	const double inline getResult()const;
	Integer* getNumerator()const;
	Integer* getDenominator()const;
	void set(const int, const int);
	void set(const std::string&, const std::string&);

	const bool isPositive()const;
	const bool isNegative()const;
	const bool isCorrect()const;
	const bool isIncorrect()const;
	const bool equalsNums()const;

	const Fraction simplification()const;
	const Fraction reduction()const;

	Fraction clone()const;

	void reverse();


	friend Fraction operator +(const Fraction&, int);
	friend Fraction operator -(const Fraction&, int);
	friend Fraction operator *(const Fraction&, int);
	friend Fraction operator /(const Fraction&, int);
	friend Fraction operator %(const Fraction&, int);
	friend Fraction operator +(const Fraction&, const Fraction&);
	friend Fraction operator -(const Fraction&, const Fraction&);
	friend Fraction operator *(const Fraction&, const Fraction&);
	friend Fraction operator /(const Fraction&, const Fraction&);
	friend Fraction operator %(const Fraction&, const Fraction&);
	friend bool operator ==(const Fraction&, const int);
	friend bool operator !=(const Fraction&, const int);
	friend bool operator >=(const Fraction&, const int);
	friend bool operator <=(const Fraction&, const int);
	friend bool operator >(const Fraction&, const int);
	friend bool operator <(const Fraction&, const int);
	friend bool operator ==(const Fraction&, const Fraction&);
	friend bool operator !=(const Fraction&, const Fraction&);
	friend bool operator >=(const Fraction&, const Fraction&);
	friend bool operator <=(const Fraction&, const Fraction&);
	friend bool operator >(const Fraction&, const Fraction&);
	friend bool operator <(const Fraction&, const Fraction&);

	friend const Fraction& operator +=(const Fraction&, int);
	friend const Fraction& operator -=(const Fraction&, int);
	friend const Fraction& operator *=(const Fraction&, int);
	friend const Fraction& operator /=(const Fraction&, int);
	friend const Fraction& operator %=(const Fraction&, int);
	friend const Fraction& operator +=(const Fraction&, const Fraction&);
	friend const Fraction& operator -=(const Fraction&, const Fraction&);
	friend const Fraction& operator *=(const Fraction&, const Fraction&);
	friend const Fraction& operator /=(const Fraction&, const Fraction&);
	friend const Fraction& operator %=(const Fraction&, const Fraction&);

	Fraction& operator ++();
	Fraction operator ++(int);

	Fraction& operator --();
	Fraction operator --(int);

private:

	Integer* numerator_;
	Integer* denominator_;

};
#endif