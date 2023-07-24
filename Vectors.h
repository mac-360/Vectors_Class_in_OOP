#pragma once
#include <iostream>
using namespace std;

template < typename Type > class Vectors
{
private:
  Type * vecptr;
  int NoofElemets;
  int TotalCapacity;

public:
  Vectors ()
  {
    this->TotalCapacity = 10;
    this->NoofElemets = 0;
    this->vecptr = new Type[TotalCapacity];
  }

  Vectors (int totalcap, int noofelements)
  {
    this->NoofElemets = noofelements;
    this->TotalCapacity = totalcap;
    this->vecptr = new Type[this->TotalCapacity];
  }
Vectors (std::initializer_list < Type > elements):vecptr (nullptr), TotalCapacity (elements.size ()),
    NoofElemets (elements.size
		 ())
  {
    vecptr = new Type[TotalCapacity];
    size_t i = 0;
  for (const auto & element:elements)
      {
	vecptr[i++] = element;
      }
  }
  Type at (int index)
  {
    if (index > NoofElemets - 1 || index < 0)
      {
	throw std::out_of_range ("Index accessing out of bound.\n");
      }
    return this->vecptr[index];
  }

  Type back ()
  {
    return this->vecptr[this->NoofElemets - 1];
  }

  Type front ()
  {
    return this->vecptr[0];
  }

  void push_back (Type val)
  {
    if (this->NoofElemets == TotalCapacity)
      {
	Type *newvec = new Type[TotalCapacity * 2];
	Reallocate (newvec);
	this->TotalCapacity *= 2;
      }
    this->vecptr[NoofElemets] = val;
    NoofElemets++;
  }

  void pop_back ()
  {
    this->NoofElemets--;
  }

  void Reallocate (Type * Newvec)
  {
    for (int i = 0; i < this->NoofElemets; i++)
      {
	Newvec[i] = this->vecptr[i];
      }
    delete[]vecptr;
    vecptr = Newvec;
  }

  bool empty ()
  {
    return NoofElemets == 0;
  }

  Type *begin ()
  {
    return vecptr;		// Pointer to the first element
  }

  Type *end ()
  {
    return vecptr + NoofElemets;	// Pointer to one past the last element
  }

  void resize (int newsize, Type val = Type ())
  {
    if (newsize > this->TotalCapacity)
      {
	Type *newvec = new Type[newsize];
	for (int i = 0; i < NoofElemets; i++)
	  {
	    newvec[i] = vecptr[i];
	  }
	delete[]vecptr;
	vecptr = newvec;
	this->TotalCapacity = newsize;
      }
    this->NoofElemets = newsize;
  }
  void clear ()
  {
    this->TotalCapacity = 0;
    this->NoofElemets = 0;
    delete[]this->vecptr;
    vecptr = nullptr;
  }

  int size ()
  {
    return this->NoofElemets;
  }

  int capacity ()
  {
    return this->TotalCapacity;
  }
  Vectors (const Vectors & obj)
  {
    this->TotalCapacity = obj.TotalCapacity;
    this->NoofElemets = obj.NoofElemets;
    delete[]this->vecptr;
    this->vecptr = new Type[TotalCapacity];

    // Copy elements from obj to this
    for (int i = 0; i < NoofElemets; i++)
      {
	this->vecptr[i] = obj.vecptr[i];
      }

  }
  void swap (Vectors & obj)
  {
    Vectors tempvec = obj;
    obj = *this;
    *this = tempvec;
  }

  ~Vectors ()
  {
    delete[]this->vecptr;
    vecptr = nullptr;
  }
  Type & operator[](int index)
  {
    if (index > NoofElemets - 1 || index < 0)
      {
	throw std::out_of_range ("Index accessing out of bound.\n");
      }
    return vecptr[index];
  }
  Vectors & operator= (const Vectors & obj)
  {
    if (this == &obj)
      {
	// Self-assignment, do nothing
	return *this;
      }
    else
      {
	delete[]vecptr;
	vecptr = new Type[obj.TotalCapacity];
	TotalCapacity = obj.TotalCapacity;
	NoofElemets = obj.NoofElemets;
	for (int i = 0; i < obj.NoofElemets; i++)
	  {
	    vecptr[i] = obj.vecptr[i];
	  }
	return *this;
      }
  }
  // Emplace a new element at the given position
  template < typename ... Args > Type * emplace (Type * ref, Args && ... args)
  {
    // Check if the vector is full
    if (NoofElemets == TotalCapacity)
      {
	// Resize the vector before emplacing if needed
	int newCapacity = TotalCapacity == 0 ? 1 : TotalCapacity * 2;
	Type *newVecPtr = new Type[newCapacity];
	for (int i = 0; i < NoofElemets; i++)
	  {
	    newVecPtr[i] = vecptr[i];
	  }
	delete[]vecptr;
	vecptr = newVecPtr;
	TotalCapacity = newCapacity;
      }

    // Move the elements after the insertion point to make space
    for (Type * it = vecptr + NoofElemets; it > ref; --it)
      {
	*it = *(it - 1);
      }

    // Construct the new element in-place using placement new
    new (ref) Type (args ...);

    // Increment the number of elements
    NoofElemets++;

    return ref;
  }
  void emplace_back (const Type & val)
  {
    *this->push_back (val);
  }
  template < typename ... Args > void emplace_back (Args && ... args)
  {
    if (NoofElemets == TotalCapacity)
      {
	int newCapacity = TotalCapacity == 0 ? 1 : TotalCapacity * 2;
	Type *newVecPtr = new Type[newCapacity];
	for (int i = 0; i < NoofElemets; i++)
	  {
	    newVecPtr[i] = vecptr[i];
	  }
	delete[]vecptr;
	vecptr = newVecPtr;
	TotalCapacity = newCapacity;
      }

    new (&vecptr[NoofElemets]) Type (std::forward < Args > (args) ...);
    NoofElemets++;
  }
  Type *rend ()
  {
    return vecptr - 1;
  }
  const Type *rend () const
  {
    return vecptr - 1;
  }
  const Type *rbegin () const
  {
    return vecptr + NoofElemets - 1;
  }
  Type *rbegin ()
  {
    return vecptr + NoofElemets - 1;
  }
  int maxsize () const
  {
    return std::numeric_limits < int >::max ();
  }
  const Type *cend () const
  {
    return vecptr + NoofElemets;
  }
  const Type *crbegin () const
  {
    return vecptr + NoofElemets - 1;
  }
  const Type *crend () const
  {
    return vecptr - 1;
  }
  const Type *data () const
  {
    return vecptr;
  }
  void shrink_to_fit ()
  {
    if (NoofElemets < TotalCapacity)
      {
	Type *newVecPtr = new Type[NoofElemets];
	for (int i = 0; i < NoofElemets; i++)
	  {
	    newVecPtr[i] = vecptr[i];
	  }
	delete[]vecptr;
	vecptr = newVecPtr;
	TotalCapacity = NoofElemets;
      }
  }
  void erase (int position)
  {
    if (position < 0 || position >= NoofElemets)
      {
	// Invalid position, do nothing
	return;
      }

    // Shift elements to the left to overwrite the element at the specified position
    for (int i = position; i < NoofElemets - 1; i++)
      {
	vecptr[i] = vecptr[i + 1];
      }

    // Decrement the number of elements in the vector
    NoofElemets--;
  }
  void erase (int start, int end)
  {
    if (start < 0 || start >= NoofElemets || end <= start
	|| end > NoofElemets)
      {
	// Invalid range, do nothing
	return;
      }

    // Calculate the number of elements to remove
    int numElementsToRemove = end - start;

    // Shift elements to the left to overwrite the range to be removed
    for (int i = start; i < NoofElemets - numElementsToRemove; i++)
      {
	vecptr[i] = vecptr[i + numElementsToRemove];
      }

    // Update the number of elements in the vector
    NoofElemets -= numElementsToRemove;
  }
  // Insert a single element at a specific position
  void insert (int position, const Type & value)
  {
    // Check if the vector needs to be resized
    if (NoofElemets == TotalCapacity)
      {
	resize (TotalCapacity * 2);
      }

    // Shift elements to the right to make space for the new element
    for (int i = NoofElemets; i > position; i--)
      {
	vecptr[i] = vecptr[i - 1];
      }

    // Insert the new element at the specified position
    vecptr[position] = value;

    // Increment the number of elements in the vector
    NoofElemets++;
  }


};
