// Member-function definitions for class Vector.
#include "PGVector.h" // include definition of class Vector 

Vector::Vector( size_t n, const int val )
{
   if( n > 10 )
   {
      ptr = new int[ n ];
      // initialize array to val
      for( unsigned int i = 0; i < n; i++ )
         ptr[ i ] = val;

      size = n;
      capacity = n;
   }
   else if( n > 0 ) // n <= 10
   {
      ptr = new int[ 10 ];
      // initialize array to val
      for( unsigned int i = 0; i < n; i++ )
         ptr[ i ] = val;

      size = n;
      capacity = 10;
   }
   else
   {
      size = 0;
      capacity = 0;
      ptr = new int[ 0 ];
   }
}

//* destructor
//Vector::~Vector()
//{
   // DO SOMETING
//}

// inequality operator; returns opposite of == operator
bool Vector::operator!=( const Vector &right ) const  
{ 
   return !( *this == right ); // invokes Vector::operator==
}

int* Vector::begin()
{
   return ptr;
}

int* Vector::end()
{
   return ptr + size;
}

int& Vector::front()
{
   return ptr[0];
}

int& Vector::back()
{
   return ptr[ size - 1 ];
}

void Vector::pop_back()
{
   size--;
}

size_t Vector::getSize() const
{
   return size;
}

size_t Vector::getCapacity() const
{
   return capacity;
}

bool Vector::empty() const
{
   return ( size == 0 );
}

void Vector::clear()
{
   size = 0;
}