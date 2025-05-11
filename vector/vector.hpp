#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector: virtual public MutableLinearContainer <Data>, virtual public ResizableContainer{
  // Must extend ,
  //             ResizableContainer

private:

  // ...

protected:

  using Container::size;
  Data* Elements = nullptr;
  // ...

public:

  // Default constructor
  Vector()=default;
  

  /* ************************************************************************ */

  // Specific constructors
  Vector(const ulong); // A vector with a given initial dimension
  Vector(const TraversableContainer<Data>&); // A vector obtained from a TraversableContainer
  Vector(MappableContainer<Data>&&); // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
   Vector(const Vector&);

  // Move constructor
   Vector(Vector&&)noexcept;

  /* ************************************************************************ */

  // Destructor
   virtual ~Vector(){
      delete[]Elements;
   };

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator=(const Vector&);

  // Move assignment
  Vector& operator=(Vector&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator==(const Vector&)const noexcept;
  // type operator!=(argument) specifiers;
  inline bool operator!=(const Vector& ) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableLinearContainer)

  // type operator[](argument) specifiers; // Override MutableLinearContainer member (must throw std::out_of_range when out of range)
  Data& operator[](const ulong)override;

  // type Front() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)
  Data& Front() override;

  // type Back() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)
   Data& Back() override;
   
  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)
  const Data& operator[](const ulong)const override;

  // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)

  // type Front() specifiers; // Override LinearContainer member (must throw std::length_error when empty)

  const Data& Front()const override;

  
  // type Back() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  const Data& Back()const override;

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)
  // type Resize(argument) specifiers; // Override ResizableContainer member

  void Resize(const ulong)override; 

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)
  // type Clear() specifiers; // Override ClearableContainer member

  void Clear() override;

protected:

  // Auxiliary functions, if necessary!


};

/* ************************************************************************** */

template <typename Data>
class SortableVector:virtual public Vector<Data>, virtual public SortableLinearContainer<Data> {
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  using Vector<Data>::size;
  Data*Elements = nullptr;

  // ...

public:

  // Default constructor
  SortableVector()=default;

  /* ************************************************************************ */

  // Specific constructors
  SortableVector(ulong); // A vector with a given initial dimension
  SortableVector(const TraversableContainer<Data>&); // A vector obtained from a TraversableContainer
  SortableVector(MappableContainer<Data>&&); // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SortableVector(const SortableVector&);

  // Move constructor
  SortableVector(SortableVector&&) noexcept;

  /* ************************************************************************ */

  // Destructor
   virtual ~SortableVector()=default;

  /* ************************************************************************ */

  // Copy assignment
  SortableVector& operator=(const SortableVector&);

  // Move assignment
  SortableVector& operator=(SortableVector&&)noexcept;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
