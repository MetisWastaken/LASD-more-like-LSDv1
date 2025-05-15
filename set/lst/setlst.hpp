
#ifndef SETLST_HPP
#define SETLST_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetLst: public Set<Data>, public List<Data> { 
  // Must extend Set<Data>,
  //             List<Data>

private:

  // ...

protected:

  using Container::Clear;
  using Container::Resize;

  // ...

public:

  // Default constructor
  virtual SetLst() = default;

  /* ************************************************************************ */

  // Specific constructors
  inline SetLst() //rivedere

  /* ************************************************************************ */

  // Copy constructor
  SetLst(const SetLst& set):Set<Data>(set), List<Data>(set);

  // Move constructor
  SetLst(SetLst&& set) noexcept:Set<Data>(std::move(set)), List<Data>(std::move(set));

  /* ************************************************************************ */

  // Destructor
  virtual ~SetLst();

  /* ************************************************************************ */

  // Copy assignment
  bool operator=(const SetLst& set); // Copy assignment of abstract types is not possible.

  // Move assignment
  bool operator=(SetLst&& set) noexcept; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetLst& set) const noexcept;
  bool operator!=(const SetLst& set) const noexcept;

  /* ************************************************************************ */

  virtual const Data& Min() const = 0;
  virtual Data MinNRemove() = 0;
  virtual void RemoveMin() = 0;

  virtual const Data& Max() const = 0;
  virtual Data MaxNRemove() = 0;
  void RemoveMax() = 0;

  virtual const Data& Predecessor(const Data&) const = 0;
  virtual Data PredecessorNRemove(const Data&) = 0;
  virtual void RemovePredecessor(const Data&) = 0;

  virtual const Data& Successor(const Data&) const = 0;
  virtual Data SuccessorNRemove(const Data&) = 0;
  virtual void RemoveSuccessor(const Data&) = 0;

  // Specific member functions // Specific member functions (inherited from OrderedDictionaryContainer)

  // type Min(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  // type MinNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  // type RemoveMin(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  // type Max(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  // type MaxNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)
  // type RemoveMax(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when empty)

  // type Predecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  // type PredecessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  // type RemovePredecessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)

  // type Successor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  // type SuccessorNRemove(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)
  // type RemoveSuccessor(argument) specifiers; // Override OrderedDictionaryContainer member (concrete function must throw std::length_error when not found)


                                                     
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

#include "setlst.cpp"

#endif
