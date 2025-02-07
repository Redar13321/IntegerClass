#include "Integer.hpp";
#include <string>

Integer::Integer() :Integer(0) {};
Integer::Integer(int number)
{
	set(number);
}
Integer::Integer(std::string text)
{
	set(text);
}
void Integer::set(const int number)
{
	if (std::isnan(number))
	{
		throw "Nan Number in args method Integet.set";
	}
	if (number < 0)
	{
		number_ = -number;
		positive_ = false;
	}
	else
	{
		number_ = number;
		positive_ = true;
	}
}
void Integer::set(const std::string& text)
{
	set(std::stoi(text));
}
const int Integer::get()const
{
	return number_ * (positive_ ? 1 : -1);
}
const bool Integer::isPositive()const
{
	return positive_;
}
const bool Integer::isNegative()const
{
	return !positive_;
}
const bool Integer::isOdd()const
{
	return number_ % 2 == 1;
}
const bool Integer::isEven()const
{
	return !isOdd();
}
const bool Integer::isSimple()const
{
	int number = get();
	for (unsigned i = 2; i <= sqrt(number); i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}
const bool Integer::isSelfPrime(const Integer& i)const
{
	return get() / i.get() > 1;
}
const bool Integer::isSelfPrime(int i)const
{
	return get() / i > 1;
}
const bool Integer::equals(Integer* i) const
{
	return this == i;
}
const int Integer::nok(int i)const
{
	return get() * i / nod(i);
}
const Integer Integer::clone() const
{
	return Integer(get());
}
const int Integer::nod(int b)const
{
	int a = get();
	if (a < b) {
		std::swap(a, b);
	}
	while (a % b != 0) {
		a = a % b;
		std::swap(a, b);
	}
	return b;
}

Integer::operator int() const
{
	return get();
}

const bool Integer::toBool() const
{
	return (bool)get();
}

const double Integer::toDouble()const
{
	return (double)get();
}

int operator +(const Integer& a, int b)
{
	return (int)a + b;
}

int operator -(const Integer& a, int b)
{
	return (int)a - b;
}

int operator /(const Integer& a, int b)
{
	if (b == 0)
	{
		throw "Zero Int Number in args method Integet::operator /";
		return 0;
	}
	return floor((int)a / b);
}

int operator *(const Integer& a, int b)
{
	return (int)a * b;
}

int operator%(const Integer& a, int b)
{
	return (int)a % b;
}

Integer operator +(const Integer& a, const Integer& b)
{
	return Integer((int)a + (int)b);
}
Integer operator -(const Integer& a, const Integer& b)
{
	return Integer((int)a - (int)b);
}
Integer operator *(const Integer& a, const Integer& b)
{
	return Integer((int)a * (int)b);
}
Integer operator /(const Integer& a, const Integer& b)
{
	return Integer(a / (int)b);
}
Integer operator %(const Integer& a, const Integer& b)
{
	return Integer((int)a % (int)b);
}

bool operator ==(const Integer& a, const int b)
{
	return (int)a == b;
}

bool operator ==(const Integer& a, const Integer& b)
{
	return (int) a == (int) b;
}
bool operator !=(const Integer& a, const Integer& b)
{
	return (int)a != (int)b;
}
bool operator >(const Integer& a, const Integer& b)
{
	return (int)a > (int)b;
}
bool operator <(const Integer& a, const Integer& b)
{
	return (int)a < (int)b;
}
bool operator >=(const Integer& a, const Integer& b)
{
	return (int)a >= (int)b;
}
bool operator <=(const Integer& a, const Integer& b)
{
	return (int)a <= (int)b;
}

Integer& operator +=(Integer& a, int b)
{
	a.set(a + b);
	return a;
}
Integer& operator -=(Integer& a, int b)
{
	a.set(a - b);
	return a;
}
Integer& operator *=(Integer& a, int b)
{
	a.set(a * b);
	return a;
}
Integer& operator /=(Integer& a, int b)
{
	a.set(a / b);
	return a;
}
Integer& operator %=(Integer& a, int b)
{
	a.set(a % b);
	return a;
}

/*
std::ostream& Integer::operator <<(std::ostream& iostream)
{
	iostream << get();
	return iostream;
}
*/

Integer& Integer::operator ++()
{
	*this += 1;
	return *this;
}
Integer Integer::operator ++(int)
{
	Integer oldInt = clone();
	*this += 1;
	return oldInt;
}
Integer Integer::operator--(int)
{
	*this -= 1;
	return *this;
}
Integer& Integer::operator--()
{
	Integer oldInt = clone();
	*this -= 1;
	return oldInt;
}
