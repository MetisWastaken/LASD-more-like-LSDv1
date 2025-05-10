
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* **************************************************************************** */

template <typename Data>
class TestableContainer: virtual public Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

virtual ~TestableContainer() = default;

  // Destructor
  // ~TestableContainer() specifiers

  /* ************************************************************************ */

  TestableContainer& operator =(const TestableContainer&)=delete; //copy
  TestableContainer& operator =(TestableContainer&&)noexcept=delete; //delete

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.
  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  bool operator==(const TestableContainer&)const noexcept = delete;
  bool operator!=(const TestableContainer&&)const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // type Exists(argument) specifiers; // (concrete function should not throw exceptions)

  virtual bool Exist(const Data&) const noexcept = 0;

};

/* ************************************************************************** */

}

#endif
