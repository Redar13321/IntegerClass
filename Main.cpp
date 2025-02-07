#include <iostream>;
#include "Integer.hpp";
#include "Fraction.hpp";

int main()
{
	Fraction frac;
	Integer myInt1;
	Integer myInt2(2);

	myInt1.set(myInt2 * 5);
	// frac.set(myInt1, 0);
	frac.set(myInt1, myInt2);

	std::cout << frac * 3 << "\n";
	std::cout << "\n";
	std::cout << myInt1++ << "\n";
	std::cout << --myInt1 << "\n";
	std::cout << myInt1 << "\n";
	std::cout << myInt1 + myInt2 << "\n";
	std::cout << myInt1 - (myInt2 * 8) << "\n";
	std::cout << myInt1 * myInt2 << "\n";
	std::cout << myInt1 / myInt2 << "\n";
	std::cout << myInt1 / 0 << "\n";
	std::cout << myInt1 % myInt2 << "\n";
	std::cout << (myInt1 < myInt2) << "\n";
	/*
	std::cout << (myInt1 == myInt2) << "\n";
	std::cout << (myInt1 != myInt2) << "\n";
	std::cout << (myInt1 >= myInt2) << "\n";
	std::cout << (myInt1 <= myInt2) << "\n";
	std::cout << (myInt1 > myInt2) << "\n";
	std::cout << (myInt1 < myInt2) << "\n";
	std::cout << (myInt1 += 3) << "\n";
	std::cout << (myInt1 -= myInt2 * 2) << "\n";
	std::cout << "\n";
	std::cout << myInt1.get() << "\n";
	std::cout << (myInt1.isPositive() ? "true" : "false") << "\n";
	std::cout << (myInt1.isNegative() ? "true" : "false") << "\n";
	std::cout << (myInt1.isOdd() ? "true" : "false") << "\n";
	std::cout << (myInt1.isEven() ? "true" : "false") << "\n";
	std::cout << (myInt1.isSimple() ? "true" : "false") << "\n";
	std::cout << (myInt1.isSelfPrime(5) ? "true" : "false") << "\n";
	std::cout << myInt1.nod(5) << "\n";
	std::cout << myInt1.nok(5) << "\n";
	*/
	return 0;
}