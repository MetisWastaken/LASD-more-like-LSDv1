
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer: virtual public TestableContainer<Data>
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~DictionaryContainer()=default;

  /* ************************************************************************ */

  DictionaryContainer& operator=(const DictionaryContainer&)=delete;
  DictionaryContainer& operator=(DictionaryContainer&&)noexcept=delete;

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  bool operator==(const DictionaryContainer&)const noexcept=delete;
  bool operator!=(const DictionaryContainer&)const noexcept=delete;

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Insert(const Data&)=0; // Copy of the value
  virtual void Insert(Data&&)=0; // Move of the value
  virtual void Remove(const Data&)=0;

  bool InsertAll(const TraversableContainer<Data>&); // Copy of the value; From TraversableContainer; True if all are inserted
  bool InsertAll(MappableContainer<Data>&&); // Move of the value; From MappableContainer; True if all are inserted
  bool RemoveAll(const TraversableContainer<Data>&); // From TraversableContainer; True if all are removed

  bool InsertSome(const TraversableContainer<Data>&); // Copy of the value; From TraversableContainer; True if some is inserted
  bool InsertSome(MappableContainer<Data>&&); // Move of the value; From MappableContainer; True if some is inserted
  bool RemoveSome(const TraversableContainer<Data>&); // From TraversableContainer; True if some is removed

};

/* ************************************************************************** */

template <typename Data>
class OrderedDictionaryContainer:virtual public DictionaryContainer<Data> {
  // Must extend DictionaryContainer<Data>

private:

protected:

public:

  // Destructor
  virtual ~OrderedDictionaryContainer()=default;

  /* ************************************************************************ */

  OrderedDictionaryContainer& operator=(const OrderedDictionaryContainer&)=delete;
  OrderedDictionaryContainer& operator=(OrderedDictionaryContainer&&)noexcept=delete;
  
  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  bool operator ==(const OrderedDictionaryContainer&)const noexcept=delete;
  bool operator !=(const OrderedDictionaryContainer&)const noexcept=delete;

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is not possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  const Data& Min()const=0; // (concrete function must throw std::length_error when empty)
  Data MinNRemove()=0; // (concrete function must throw std::length_error when empty)
  void RemoveMin()=0; // (concrete function must throw std::length_error when empty)

  const Data& Max()const=0; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove()=0; // (concrete function must throw std::length_error when empty)
  void RemoveMax()=0; // (concrete function must throw std::length_error when empty)

  const Data& Predecessor(const Data&)const=0; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data&)=0; // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data&)=0; // (concrete function must throw std::length_error when not found)

  const Successor(const Data&)const=0; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data&)=0; // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data&)=0; // (concrete function must throw std::length_error when not found)

};

/* ************************************************************************** */



#include "dictionary.cpp"

#endif
