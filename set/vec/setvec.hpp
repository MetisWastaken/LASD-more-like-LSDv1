
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec: public Set<Data>, public ResizableContainer {
  // Must extend Set<Data>,
  //             ResizableContainer

private:

  // ...

protected:

using Container::Insert;
using Container::Remove;
using Container::Clear;

  // ...

public:

  // Default constructor
  inline SetVec()=default;

  /* ************************************************************************ */

  // Specific constructors
  SetVec(const TraversableContainer<Data>& con); // A set obtained from a TraversableContainer
  SetVec(MappableContainer<Data>&& con); // A set obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
   SetVec(const SetVec& set); // A set obtained from another SetVec

  // Move constructor
  SetVec(SetVec&& set) noexcept; // A set obtained from another SetVec

  /* ************************************************************************ */

  // Destructor
  virtual ~SetVec();

  /* ************************************************************************ */

  // Copy assignment
  SetVec& operator=(const SetVec& set); // Copy assignment

  // Move assignment
  SetVec& operator=(SetVec&& set) noexcept; // Move assignment

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const SetVec& set) const noexcept; // Equality operator
  virtual bool operator!=(const SetVec& set) const noexcept; // Inequality operator

  /* ************************************************************************ */

  // Specific member functions (inherited from OrderedDictionaryContainer)

  virtual const Data& Min() const = 0;
  virtual Data MinNRemove() = 0;
  virtual void RemoveMin() = 0;
  virtual const Data& Max() const = 0;
  virtual Data MaxNRemove() = 0;
  virtual void RemoveMax() = 0;
  virtual const Data& Predecessor(const Data&) const = 0;
  virtual Data PredecessorNRemove(const Data&) = 0;
  virtual void RemovePredecessor(const Data&) = 0;
  virtual const Data& Successor(const Data&) const = 0;
  virtual Data SuccessorNRemove(const Data&) = 0;
  virtual void RemoveSuccessor(const Data&) = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual void Insert(const Data&) override; // Override DictionaryContainer member (copy of the value)
  virtual void Insert(Data&&) override; // Override DictionaryContainer member (move of the value)
  virtual void Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  virtual const Data& operator[](ulong)const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************** */

  // Specific member function (inherited from TestableContainer)

  virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif
