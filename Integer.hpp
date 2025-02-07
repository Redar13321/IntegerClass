#ifndef INTEGER_HPP
#define INTEGER_HPP
#include <iostream>;

class Integer {

public:
	Integer();
	Integer(int);
	Integer(std::string);
	void set(const int);
	void set(const std::string&);
	const int get()const;
	const bool isPositive()const;
	const bool isNegative()const;
	const bool isOdd()const;
	const bool isEven()const;
	const bool isSimple()const;
	const bool isSelfPrime(const Integer&)const;
	const bool isSelfPrime(const int)const;
	const bool equals(Integer*)const;
	const int nod(int b)const;
	const int nok(int i)const;
	const Integer clone()const;

	operator int() const;

	const bool toBool()const;
	const double toDouble()const;
	// operator double() const;
	// operator bool() const;
	
	friend int operator +(const Integer&, int);
	friend int operator -(const Integer&, int);
	friend int operator /(const Integer&, int);
	friend int operator *(const Integer&, int);
	friend int operator %(const Integer&, int);
	friend Integer operator +(const Integer&, const Integer&);
	friend Integer operator -(const Integer&, const Integer&);
	friend Integer operator /(const Integer&, const Integer&);
	friend Integer operator *(const Integer&, const Integer&);
	friend Integer operator %(const Integer&, const Integer&);

	friend bool operator ==(const Integer&, const int);
	friend bool operator ==(const Integer&, const Integer&);
	friend bool operator !=(const Integer&, const Integer&);
	friend bool operator >(const Integer&, const Integer&);
	friend bool operator <(const Integer&, const Integer&);
	friend bool operator >=(const Integer&, const Integer&);
	friend bool operator <=(const Integer&, const Integer&);

	friend Integer& operator +=(Integer&, int);
	friend Integer& operator -=(Integer&, int);
	friend Integer& operator *=(Integer&, int);
	friend Integer& operator /=(Integer&, int);
	friend Integer& operator %=(Integer&, int);


	Integer& operator ++();
	Integer operator ++(int);

	Integer& operator --();
	Integer operator --(int);

	// std::ostream& operator <<(std::ostream&);

private:
	unsigned number_; // still int
	bool positive_;

};

#endif // !INTEGER_HPP
