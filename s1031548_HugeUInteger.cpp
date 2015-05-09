// Member-function definitions for class HugeInteger.
#include "s1031548_HugeUInteger.h"  // include definition of class HugeInteger 

// default constructor
HugeUInteger::HugeUInteger()
: integer()
{
}

// default constructor (all digi = 0)
HugeUInteger::HugeUInteger(size_t size)
//: integer(size,0)
{
	integer.resize(size);
	for (unsigned int i = 0; i < size; i++)
		integer[i] = 0;

}

// copy constructor
HugeUInteger::HugeUInteger(HugeUInteger &in)
{
	unsigned int size = in.integer.getSize();
	integer.resize(size);
	for (int i = 0; i < size; i++)
	{
		integer[i] = in.integer[i];
	}
}

/*HugeUInteger::~HugeUInteger()
{

}*/

// randomly generate an integer
HugeUInteger HugeUInteger::random(size_t size)
{
	//HugeUInteger Ans(size);
	HugeUInteger* Ans = new HugeUInteger(size);
	
	Ans->integer[size - 1] = 1 + rand() % 9;
	for (unsigned int i = 0; i < size - 1; i++)
		Ans->integer[i] = rand() % 10;

	//return Ans;
	
	return *Ans;
}

// zero this number (size = 1)
HugeUInteger HugeUInteger::zero()
{
	HugeUInteger* Ans = new HugeUInteger(1);
	Ans->integer[0] = 0;

	return *Ans;
}
HugeUInteger HugeUInteger::operator=(const HugeUInteger &right)
{
	integer = right.integer;
	return *this;
}
//< assignment
bool HugeUInteger::operator==(const HugeUInteger &right)
{
	return (integer == right.integer) ? true : false;
}
//< equal to
bool HugeUInteger::operator!=(const HugeUInteger &right)
{
	return (integer != right.integer) ? true : false;
}
//< not equal to
bool HugeUInteger::operator<(const HugeUInteger &right)
{
	if (integer.getSize() > right.integer.getSize())
	{
		return false;
	}
	else
	{
		for (int i = 0; i<integer.getSize(); i++)
		{
			if (integer[i] > right.integer[i])
			{
				return false;
			}
			if (integer[i] < right.integer[i])
			{
				return true;
			}
		}
		return false;
	}
}
//< less than
bool HugeUInteger::operator>(const HugeUInteger &right)
{
	if (integer.getSize() < right.integer.getSize())
	{
		return false;
	}
	else
	{
		for (int i = 0; i<integer.getSize(); i++)
		{
			if (integer[i] < right.integer[i])
			{
				return false;
			}
			if (integer[i] > right.integer[i])
			{
				return true;
			}
		}
		return false;
	}
}
//< greater than

HugeUInteger HugeUInteger::operator+(const HugeUInteger &right)
{
	unsigned int size = integer.getSize();
	unsigned int rsize = right.integer.getSize();
	unsigned int sumsize;
	sumsize = (size > rsize) ? size + 1 : rsize + 1;
	HugeUInteger sum(sumsize);
	//sum.integer.resize(sumsize);

	
	for (int i = 0; i < size; i++)
	{
		sum.integer[i] = integer[i];
	}
	for (int i = 0; i < rsize; i++)
	{
		sum.integer[i] += right.integer[i];
	}
	for (int i = sumsize - 1; i >= 0; i--)
	{
		if (sum.integer[i]>9)
		{
			sum.integer[i] -= 10;
			sum.integer[i + 1]++;
		}
	}
	if (sum.integer[sumsize - 1] == 0)
	{
		sum.integer.reserve(sumsize - 1);
	}
	return sum;
}
//< addition operator; HugeUInteger + HugeUInteger
HugeUInteger  HugeUInteger::operator-(const HugeUInteger &right)
{
	if (*this < right)
	{
		return zero();
	}
	if (*this == right)
	{
		return zero();
	}
	unsigned int size = integer.getSize();
	unsigned int rsize = right.integer.getSize();
	unsigned int differencesize;
	differencesize = rsize - size;
	HugeUInteger diff(*this);
	for (int i = 0; i < rsize; i++)
	{
		diff.integer[i] -= right.integer[i];
	}
	for (int i = differencesize - 1; i >= 0; i--)
	{
		if (diff.integer[i] < 0)
		{
			diff.integer[i + 1]--;
			diff.integer[i] += 10;
		}
	}
	for (int i = differencesize - 1; i >= 0; i--)
	{
		if (diff.integer[i] == 0)
		{
			diff.integer.resize(differencesize - 1);
		}
		else
		{
			break;
		}
	}
	return diff;

}
//< subtraction operator; HugeUInteger  - HugeUInteger ;
//< (Use ZERO to replace negative result)
HugeUInteger  HugeUInteger::operator*(const HugeUInteger &right)
{
	unsigned int size = integer.getSize();
	unsigned int rsize = right.integer.getSize();
	unsigned int mulsize;
	mulsize = size + rsize;
	HugeUInteger mul(mulsize);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < rsize; j++)
		{
			mul.integer[i + j] = integer[i] * right.integer[j];
		}
	}
	for (int i = mulsize - 1; i >= 0; i--)
	{
		if (mul.integer[i]>9)
		{
			mul.integer[i + 1] += mul.integer[i] / 10;
			mul.integer[i] %= 10;
		}
	}
	for (int i = mulsize - 1; i >= 0; i--)
	{
		if (mul.integer[i] == 0)
		{
			mul.integer.resize(mulsize - 1);
		}
		else
		{
			break;
		}
	}
	return mul;

}
//< multiplication operator; HugeUInteger  * HugeUInteger 
HugeUInteger  HugeUInteger::operator/(const HugeUInteger &right)
{
	unsigned int size = integer.getSize();
	unsigned int rsize = right.integer.getSize();
	HugeUInteger Zero(1);
	if (size < rsize || integer == right.integer)
	{
		return Zero;
	}
	int Bsize = size;
	int Rsize = size;
	HugeUInteger Buffer(Bsize);
	HugeUInteger Remainder(Rsize);
	for (int i = 0; i < rsize; i++)
	{
		Buffer.integer[i] = right.integer[i];
	}
	for (int i = 0; i < size; i++)
	{
		Remainder.integer[i] = integer[i];
	}
	int dif = size - rsize;
	while (dif--)
	{
		for (int i = Rsize - 1; i >= 0; i--)
		{
			Buffer.integer[i + 1] = Buffer.integer[i];
		}
		Buffer.integer[0] = 0;
	}
	bool div = false;
	if (Remainder < Buffer)
	{
		Buffer.DividedByTen();
		div = true;
	}
	int Qsize = div ? size - rsize : size - rsize + 1;
	HugeUInteger Q(Qsize);
	for (int i = Qsize - 1; i >= 0; i--)
	{
		if (Remainder>Buffer)
		{
			Q.integer[i]++;
			Remainder = Remainder - Buffer;
		}
		Buffer.DividedByTen();
	}
	return Q;
}
//< division operator; HugeUInteger  / HugeUInteger 
HugeUInteger  HugeUInteger::operator%(const HugeUInteger &right)
{
	unsigned int size = integer.getSize();
	unsigned int rsize = right.integer.getSize();
	HugeUInteger zero(1);
	if (size < rsize || integer == right.integer)
	{
		return zero;
	}
	int Bsize = size;
	int Rsize = size;
	HugeUInteger Buffer(Bsize);
	HugeUInteger Remainder(Rsize);
	for (int i = 0; i < rsize; i++)
	{
		Buffer.integer[i] = right.integer[i];
	}
	for (int i = 0; i < size; i++)
	{
		Remainder.integer[i] = integer[i];
	}
	int dif = size - rsize;
	while (dif--)
	{
		for (int i = Rsize - 1; i >= 0; i--)
		{
			Buffer.integer[i + 1] = Buffer.integer[i];
		}
		Buffer.integer[0] = 0;
	}
	bool div = false;
	if (Remainder < Buffer)
	{
		Buffer.DividedByTen();
		div = true;
	}
	int Qsize = div ? size - rsize : size - rsize + 1;
	HugeUInteger Q(Qsize);
	for (int i = Qsize - 1; i >= 0; i--)
	{
		if (Remainder>Buffer)
		{
			Q.integer[i]++;
			Remainder = Remainder - Buffer;
		}
		Buffer.DividedByTen();
	}
	return Remainder;
}
//< modulus operator; HugeUInteger  % HugeUInteger

void HugeUInteger::helpInCreatement()
{
	unsigned int size = integer.getSize();
	integer[0]++;
	for (int i = 0; i < size - 1; i++)
	{
		if (integer[i] == 10)
		{
			integer[i] = 0;
			integer[i + 1]++;
		}
	}
	if (integer[size - 1] == 10)
	{
		integer.resize(size - 1);
		integer[size - 1] = 0;
		integer[size]++;
	}
}
void HugeUInteger::DividedByTen()
{
	unsigned int size = integer.getSize();
	for (int i = 1; i < size; i++)
	{
		integer[i - 1] = integer[i];
	}
	integer.resize(size - 1);
}
bool HugeUInteger::Zero()
{
	for (int i = 0; i < integer.getSize(); i++)
	{
		if (integer[i] != 0)
		{
			return false;
		}
	}
	return true;
}
ostream &operator<<(ostream &output, const HugeUInteger &in)
{
	unsigned int size = in.integer.getSize();


	if (size == 0)
		output << 0;
	else //if(!sign) cout << "-";
	for (int i = size - 1; i >= 0; i--)
		output << in.integer[i]; // << " ";

	return output; // enables cout << x << y;
}