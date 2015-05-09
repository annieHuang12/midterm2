#include <conio.h>
#include <iostream>
using namespace std;
#include "s1031548_HugeUInteger.h"//< CORRECT this file name

int main()
{
	Vector A, B, C;
	A.push_back(3);   A.push_back(4);   A.push_back(5);
	cout << "A = " << A; //"3 4 5"
	A[1] = 7;

	B = A; cout << "B = A" << endl;
	cout << "B = " << B; //"3 7 5"

	B.push_back(9);   B.push_back(10);  B.push_back(11);
	cout << "(pushed)B = " << B; //"3 7 5 9 10 11"

	C.reserve(15);
	C.assign(B.begin(), B.end());
	cout << "capacity of C(reserved) = " << C.getCapacity(); // capacity of C = 15
	cout << "size of C = " << C.getSize(); //size of C = 6
	cout << "(assigned)C = " << C; //"3 7 5 9 10 11"

	C.shrink_to_fit();
	cout << "capacity of C(shrinked) = " << C.getCapacity(); // capacity of C = 6

	int myarray[] = { 2, 4, 63 };
	C.insert((C.begin() + 2), myarray, myarray + 3); // (add 2 & 4)
		cout << "(inserted)C = " << C; //"3 7 2 4 5 9 10 11"

	C.erase(C.begin(), C.begin() + 5); // (remove 3 7 2 4 5)
	cout << "(erased)C = " << C; //"9 10 11"

	B.swap(C); cout << "swap B and C" << endl;
	cout << "B = " << B; //"9 10 11"
	cout << "C = " << C; //"3 7 5"

	//============================================

	unsigned int seed;
	cout << "Enter seed: ";
	cin >> seed;
	srand(seed);

	unsigned int length1, length2, length3;
	cout << "Enter the lengths of three huge integers: ";
	cin >> length1 >> length2 >> length3;

	HugeUInteger n1, n2, n3;
	n1 = HugeUInteger::random(length1);
	cout << "N1: " << n1 << endl;
	n2 = HugeUInteger::random(length2);
	cout << "N2: " << n2 << endl;
	n3 = HugeUInteger::random(length3);
	cout << "N3: " << n3 << endl;
	HugeUInteger n4 = HugeUInteger::zero();
	cout << "N4: " << n4 << endl;

	cout << "N1 + N3 = " << n1 + n3 << endl;
	cout << "N2 - N3 = " << n2 - n3 << endl;
	cout << "N1 * N4 = " << n1 * n4 << endl;
	cout << "N4 = N2 + N3 * N1 = " << (n4 = n2 + n3 * n1) << endl;

	cout << endl << "Let N1 = N2, then..." << endl;
	n1 = n2;
	if (n1 == n2)
		cout << "N1 is equal to N2" << endl;

	if (n1 > n3)
		cout << "N1 is larger than N3" << endl;

	if (n1 < n3)
		cout << "N1 is smaller than N3" << endl;

	cout << "N4 / N2 = " << n4 / n2 << endl;
	HugeUInteger n5;
	cout << "N5 = N4 % N2 = " << (n5 = n4 % n2) << endl;

	cout << endl;
	cout << "N1: " << n1 << endl;
	cout << "N2: " << n2 << endl;
	cout << "N3: " << n3 << endl;
	cout << "N4: " << n4 << endl;

	_getch();
	return 0;
}