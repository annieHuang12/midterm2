// Member-function definitions for class Vector.
#include "s1031548_Vector.h"// include definition of class Vector 
#include <iostream>
#include <cstdlib>

ostream &operator<<(ostream& output, const Vector& vec)
{
	for (int i = 0; i < vec.size; i++)
	{
		output << vec.ptr[i] << endl;
	}
	return output;
}
Vector::Vector(size_t n, const int val)
{
	if (n > 10)
	{
		ptr = new int[n];
		// initialize array to val
		for (unsigned int i = 0; i < n; i++)
			ptr[i] = val;

		size = n;
		capacity = n;
	}
	else if (n > 0) // n <= 10
	{
		ptr = new int[10];
		// initialize array to val
		for (unsigned int i = 0; i < n; i++)
			ptr[i] = val;

		size = n;
		capacity = 10;
	}
	else
	{
		size = 0;
		capacity = 0;
		ptr = new int[0];
	}
}

Vector::Vector(int *first, int *last)
{
	int newsize = last - first;
	ptr = new int[newsize];
	for (int i = 0; i < newsize; i++)
	{
		ptr[i] = *(first + i);
	}
	size = newsize;
	capacity = newsize;
}
// Constructs a container with as many elements as the range [first,last),
// with each element emplace-constructed from its corresponding element in that range,
// in the same order.

Vector::Vector(const Vector &vectorToCopy)
{
	int *temp = new int[vectorToCopy.size];
	for (int i = 0; i < vectorToCopy.size; i++)
	{
		ptr[i] = vectorToCopy.ptr[i];
	}
	ptr = temp;
	size = vectorToCopy.size;
	capacity = vectorToCopy.capacity;
}
// Constructs a container with a copy of each of the elements in x, in the same order.
//* destructor
Vector::~Vector()
{
	delete[] ptr;
}

const Vector &Vector::operator=(const Vector &right)
{
	if (&right != this)
	{
		if (size != right.size)
		{
			delete[] ptr;
			size = right.size;
			capacity = right.capacity;
			ptr = new int[size];
		}
		for (int i = 0; i < size; i++)
		{
			ptr[i] = right.ptr[i];
		}
	}
	return *this;
}// assignment operator

bool Vector::operator==(const Vector &right) const
{
	if (size != right.size)
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if (ptr[i] != right.ptr[i])
		{
			return false;
		}
	}
	return true;
}// equality operator
// inequality operator; returns opposite of == operator
bool Vector::operator!=(const Vector &right) const
{
	return !(*this == right); // invokes Vector::operator==
}

int &Vector::operator[](size_t subscript)
{
	return ptr[subscript];
}
// subscript operator for non-const objects returns modifiable lvalue (reference)

int Vector::operator[](size_t subscript) const
{
	return ptr[subscript];
}
// subscript operator for const objects returns rvalue
int* Vector::begin()
{
	return ptr;
}

int* Vector::end()
{
	return ptr + size;
}

void Vector::resized(size_t n)
{
	int *temp = new int[n];
	if (size > n)
	{
		for (int i = 0; i < n; i++)
		{
			temp[i] = *(begin() + i);
		}
	}
	if (size < n)
	{
		for (int i = 0; i < size; i++)
		{
			temp[i] = *(begin() + i);
		}
		for (int i = size; i < n; i++)
		{
			temp[i] = 0;
		}
	}
	ptr = temp;
	size = n;
	capacity = n;
}
void Vector::resize(size_t n, const int val)
{
	int *temp = new int[n];
	for (int i = 0; i < size; i++)
	{
		temp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (i <= size)
		{
			ptr[i] = temp[i];
		}
		else
		{
			ptr[i] = val;
		}
	}
}
// Resizes the container so that it contains n elements.
// If n is smaller than the current container size,
// the content is reduced to its first n elements, removing those beyond.
// If n is greater than the current container size,
// the content is expanded by inserting at the end as many elements as needed to reach a size of n.
// The new elements are initialized as 0.
// If n is also greater than the current container capacity,
// an automatic reallocation of the allocated storage space takes place.

int& Vector::front()
{
	return ptr[0];
}

int& Vector::back()
{
	return ptr[size - 1];
}

size_t Vector::getSize() const
{
	return size;
}

size_t Vector::getCapacity() const
{
	return capacity;
}

void Vector::reserve(size_t n)
{
	capacity = n;
}
// Requests that the vector capacity be enough to contain n elements.
// If n is greater than the current vector capacity,
// the function causes the container to reallocate its storage increasing its capacity to n.
// In all other cases, the function call does not cause a reallocation and
// the vector capacity is not affected.

void Vector::shrink_to_fit()
{
	capacity = size;
}
// Requests the container to reduce its capacity to fit its size.

void Vector::push_back(const int val)
{
	int newsize = size + 1;
	int *temp = new int[newsize];
	for (int i = 0; i < newsize; i++)
	{
		if (i==newsize-1)
		{
			temp[i] = val;
		}
		temp[i] = ptr[i];
	}
	ptr = temp;
	size = newsize;
	capacity = (newsize > capacity) ? newsize : capacity;
}
// Adds a new element at the end of the vector, after its current last element.
// The content of val is copied to the new element.
// This effectively increases the container size by one,
// which causes an automatic reallocation of the allocated storage space
// if -and only if- the new vector size surpasses the current vector capacity.

void Vector::pop_back()
{
	size--;
}

bool Vector::empty() const
{
	return (size == 0);
}

void Vector::clear()
{
	size = 0;
}

void Vector::assign(int n, const int val)
{
	int *temp = new int[size];
	for (int i = 0; i < n; i++)
	{
		temp[i] = val;
	}
	ptr = temp;
	size = n;
	capacity = n;
}
// Assigns new contents to the vector, replacing its current contents,
// and modifying its size accordingly.
// The new contents are n elements, each initialized to a copy of val.

void Vector::assign(int *first, int *last)
{
	int newsize = last - first;
	int *temp = new int[size];
	for (int i = 0; i < newsize; i++)
	{
		temp[i] = *(first + i);
	}
	ptr = temp;
	size = newsize;
	capacity = newsize;
}
// Assigns new contents to the vector, replacing its current contents,
// and modifying its size accordingly.
// The new contents are elements constructed from each of the elements
// in the range between first and last, in the same order.
// *NOTE: "int *first & *last" are pointers to point on specific elements in the ANOTHER Vector or array

int* Vector::insert(int *position, int *first, int *last)
{
	int insertsize = last - first;
	int newsize = size + insertsize;
	int *temp = new int[newsize];
	bool atpoi = false;
	int cur = 0;
	for (int i = 0; i < newsize; i++)
	{
		if ((ptr + i) >= first && (ptr + i) <= first + insertsize)
		{
			temp[i] = *(first + cur);
			//temp = first + cur;
			cur++;
			atpoi = true;
		}
		
		else 
		{
			if (atpoi)
			{
				temp[i] = ptr[i - insertsize];
			}
			else
			{
				temp[i] = ptr[i];
			}
		}
	}
	ptr = temp;
	size = newsize;
	capacity = (newsize > capacity) ? newsize : capacity;

	return ptr;
}
// The vector is extended by inserting new elements BEFORE the element at the specified position,
// effectively increasing the container size by the number of elements inserted.
// The range of inserted elements is [first,last).
// This causes an automatic reallocation of the allocated storage space if -and only if-
// the new vector size surpasses the current vector capacity.
// Relocates all the elements that were after position to their new positions.
// *NOTE: "int *position" is a pointer to point on specific element in the CURRENT Vector
//        "int *first & *last" are pointers to point on specific elements in the ANOTHER Vector or array

int* Vector::erase(int *first, int *last)
{
	int erasize = last - first + 1;
	int newsize = size + erasize;
	int *temp = new int[newsize];
	bool *posi = new bool[size];
	int cur = 0;
	for (int i = 0; i < size; i++)
	{
		posi = false;
	}
	for (int i = 0; i < size; i++)
	{
		if ((ptr + i) >= first && (ptr + i) <= first + erasize)
		{
			posi = false;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (posi)
		{
			temp[cur++] = ptr[i];	
		}
	}
	size = newsize;
	capacity = capacity - erasize;
	ptr = temp;

	return ptr;
}
// Removes from the vector the range [first,last) of elements.
// This effectively reduces the container size by the number of elements removed.
// Relocates all the elements after the segment erased to their new positions.

void Vector::swap(Vector &x)
{
	int *t_ptr;
	int t_size;
	int t_capacity;

	t_ptr = ptr;
	ptr = x.ptr;
	x.ptr = t_ptr;

	t_size = size;
	size = x.size;
	x.size = t_size;

	t_capacity = capacity;
	capacity = x.capacity;
	x.capacity = t_capacity;
}
// Exchanges the content of the container by the content of x, which is ANOTHER vector. Sizes may differ.