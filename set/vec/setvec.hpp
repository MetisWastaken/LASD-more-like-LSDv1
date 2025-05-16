
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

  Vector<Data> elements;

  // ...

protected:

using DictionaryContainer<Data>::Insert;
using DictionaryContainer<Data>::Remove;
using ClearableContainer::Clear;

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

  virtual const Data& Min() const;
  virtual Data MinNRemove();
  virtual void RemoveMin();
  virtual const Data& Max() const;
  virtual Data MaxNRemove();
  virtual void RemoveMax();
  virtual const Data& Predecessor(const Data&) const;
  virtual Data PredecessorNRemove(const Data&);
  virtual void RemovePredecessor(const Data&);
  virtual const Data& Successor(const Data&) const;
  virtual Data SuccessorNRemove(const Data&);
  virtual void RemoveSuccessor(const Data&);

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual bool Insert(const Data&) override; // Override DictionaryContainer member (copy of the value)
  virtual bool Insert(Data&&) override; // Override DictionaryContainer member (move of the value)
  virtual bool Remove(const Data&) override; // Override DictionaryContainer member

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
