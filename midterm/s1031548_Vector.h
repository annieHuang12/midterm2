#ifndef PG2VECTOR_H
#define PG2VECTOR_H
#include <iostream>
using namespace std;

class Vector
{
	friend ostream &operator<<(ostream& output, const Vector& vec);
	// Print out the content of vector
	// For example, if a vector = {13,12,7,5,3}, the output will be "13 12 7 5 3\n" ( include two " )

public:
	Vector(size_t n = 0, const int val = 0);
	// Constructs a container with n elements. 
	// Each element is a copy of val.
	// *NOTE: if n < 0, the default capacity = 10
	// if n <= 0, the default capacity = 0

	Vector(int *first, int *last);
	// Constructs a container with as many elements as the range [first,last),
	// with each element emplace-constructed from its corresponding element in that range,
	// in the same order.

	Vector(const Vector &vectorToCopy);
	// Constructs a container with a copy of each of the elements in x, in the same order.

	~Vector(); // Destroys the container object.

	const Vector &operator=(const Vector &right); // assignment operator

	bool operator==(const Vector &right) const; // equality operator

	bool operator!=(const Vector &right) const; // inequality operator

	int &operator[](size_t);
	// subscript operator for non-const objects returns modifiable lvalue (reference)

	int operator[](size_t) const;
	// subscript operator for const objects returns rvalue

	int* begin();
	// Returns a pointer pointing to the first element in the vector.
	// If the container is empty, the returned pointer shall not be dereferenced.

	int* end();
	// Returns an pointer referring to the past-the-end element in the vector container.
	// The past-the-end element is the theoretical element that would follow the last element in the vector.
	// It does not point to any element, and thus shall not be dereferenced.
	// If the container is empty, the returned pointer shall not be dereferenced. 

	size_t getSize() const;
	// Returns the number of elements in the vector.
	void resized(size_t n);
	void resize(size_t n, const int val = 0);
	// Resizes the container so that it contains n elements.
	// If n is smaller than the current container size,
	// the content is reduced to its first n elements, removing those beyond.
	// If n is greater than the current container size,
	// the content is expanded by inserting at the end as many elements as needed to reach a size of n.
	// The new elements are initialized as 0.
	// If n is also greater than the current container capacity,
	// an automatic reallocation of the allocated storage space takes place.

	size_t getCapacity() const; // Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.

	bool empty() const; // Returns whether the vector is empty (i.e. whether its size is 0).

	void reserve(size_t n);
	// Requests that the vector capacity be enough to contain n elements.
	// If n is greater than the current vector capacity,
	// the function causes the container to reallocate its storage increasing its capacity to n.
	// In all other cases, the function call does not cause a reallocation and
	// the vector capacity is not affected.

	void shrink_to_fit(); // Requests the container to reduce its capacity to fit its size.

	int& front(); // Returns a reference to the first element in the vector.
	// Calling this function on an empty container causes undefined behavior.

	int& back(); // Returns a reference to the last element in the vector.
	// Calling this function on an empty container causes undefined behavior. 

	void push_back(const int val);
	// Adds a new element at the end of the vector, after its current last element.
	// The content of val is copied to the new element.
	// This effectively increases the container size by one,
	// which causes an automatic reallocation of the allocated storage space
	// if -and only if- the new vector size surpasses the current vector capacity.

	void pop_back();
	// Removes the last element in the vector, effectively reducing the container size by one.

	void assign(int n, const int val = 0);
	// Assigns new contents to the vector, replacing its current contents,
	// and modifying its size accordingly.
	// The new contents are n elements, each initialized to a copy of val.

	void assign(int *first, int *last);
	// Assigns new contents to the vector, replacing its current contents,
	// and modifying its size accordingly.
	// The new contents are elements constructed from each of the elements
	// in the range between first and last, in the same order.
	// *NOTE: "int *first & *last" are pointers to point on specific elements in the ANOTHER Vector or array

	int* insert(int *position, int *first, int *last);
	// The vector is extended by inserting new elements BEFORE the element at the specified position,
	// effectively increasing the container size by the number of elements inserted.
	// The range of inserted elements is [first,last).
	// This causes an automatic reallocation of the allocated storage space if -and only if-
	// the new vector size surpasses the current vector capacity.
	// Relocates all the elements that were after position to their new positions.
	// *NOTE: "int *position" is a pointer to point on specific element in the CURRENT Vector
	//        "int *first & *last" are pointers to point on specific elements in the ANOTHER Vector or array

	int* erase(int *first, int *last);
	// Removes from the vector the range [first,last) of elements.
	// This effectively reduces the container size by the number of elements removed.
	// Relocates all the elements after the segment erased to their new positions.

	void swap(Vector &x); // Exchanges the content of the container by the content of x, which is ANOTHER vector. Sizes may differ.

	void clear(); // Removes all elements from the vector, leaving the container with a size of 0.
	// The vector capacity does not change, and no reallocations happen due to calling this function.
private:
	size_t size;
	// the number of elements in the vector
	// This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.

	size_t capacity;
	// the size of the storage space currently allocated for the vector, expressed in terms of elements.
	// This capacity is not necessarily equal to the vector size. It can be equal or greater,
	// with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
	// Note: the default capacity = 10

	int *ptr; // points to a dynamically allocated array which is used to store the elements (integer) of the vector
};

#endif