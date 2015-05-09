#ifndef HUGE_UINTEGER_H
#define HUGE_UINTEGER_H
#include "s1031548_Vector.h"
//#include <vector>
#include<iostream>
using namespace std;

#define MAX   //< max length of huge interger
class HugeUInteger
{
	friend ostream &operator<<(ostream &output, const HugeUInteger &in);
public:
	HugeUInteger(); //< default constructor (the default value = 0)
	HugeUInteger(HugeUInteger &in); //< copy constructor
	HugeUInteger(size_t size);
	//~HugeUInteger();

	static HugeUInteger random(size_t size); //< randomly generate an integer, 
	//< the highest digit should not be ZERO

	static HugeUInteger zero(); //< zero this number (size = 1)

	HugeUInteger operator=(const HugeUInteger &right); //< assignment
	bool operator==(const HugeUInteger &right); //< equal to
	bool operator!=(const HugeUInteger &right); //< not equal to
	bool operator<(const HugeUInteger &right);  //< less than
	bool operator>(const HugeUInteger &right);  //< greater than

	HugeUInteger operator+(const HugeUInteger &right);
	//< addition operator; HugeUInteger + HugeUInteger
	HugeUInteger  operator-(const HugeUInteger &right);
	//< subtraction operator; HugeUInteger  - HugeUInteger ;
	//< (Use ZERO to replace negative result)
	HugeUInteger  operator*(const HugeUInteger &right);
	//< multiplication operator; HugeUInteger  * HugeUInteger 
	HugeUInteger  operator/(const HugeUInteger &right);
	//< division operator; HugeUInteger  / HugeUInteger 
	HugeUInteger  operator%(const HugeUInteger &right);
	//< modulus operator; HugeUInteger  % HugeUInteger

private:
	Vector integer;		//include "PG2Vector.h"
	//vector<int> integer; 	//include <vector>
	void helpInCreatement();
	void DividedByTen();
	bool Zero();
	//You may add another function here (if necessary)
};

#endif