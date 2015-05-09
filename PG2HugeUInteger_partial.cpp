// Member-function definitions for class HugeInteger.
#include "PG2HugeUInteger.h" // include definition of class HugeInteger 

// default constructor
HugeUInteger::HugeUInteger()
: integer()
{
}

// default constructor (all digi = 0)
HugeUInteger::HugeUInteger(size_t size)
: integer()
{
	integer.resize(size);
	for (unsigned int i = 0; i < size - 1; i++)
		integer[i] = 0;
}

// copy constructor
//HugeUInteger::HugeUInteger(HugeUInteger &in)


// randomly generate an integer
HugeUInteger HugeUInteger::random(size_t size)
{
	HugeUInteger Ans(size);

	Ans.integer[size - 1] = 1 + rand() % 9;
	for (unsigned int i = 0; i < size - 1; i++)
		Ans.integer[i] = rand() % 10;

	return Ans;
}

// zero this number (size = 1)
HugeUInteger HugeUInteger::zero()
{
	HugeUInteger Ans(1);
	Ans.integer[0] = 0;

	return Ans;
}

ostream &operator<<(ostream &output, const HugeUInteger &in)
{
	unsigned int size = in.integer.size();
	if (size == 0)
		output << 0;
	else //if(!sign) cout << "-";
	for (int i = size - 1; i >= 0; i--)
		output << in.integer[i]; // << " ";

	return output; // enables cout << x << y;
}