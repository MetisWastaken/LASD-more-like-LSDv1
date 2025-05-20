
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
  using typename List<Data>::Node;
  using List<Data>::tail;
  using List<Data>::head;
  using Container::size;


  // ...

public:


  const Node* BinarySearch(const Data&) const;

  // Default constructor
   SetLst() = default;

  /* ************************************************************************ */

  // Specific constructors
  
  SetLst(const TraversableContainer<Data>& con); // A set obtained from a TraversableContainer
  SetLst(MappableContainer<Data>&& con); // A set obtained from a MappableContainer
  /* ************************************************************************ */
  // Copy constructor

  SetLst(const SetLst& set);

  // Move constructor
  SetLst(SetLst&& set) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~SetLst()=default;

  /* ************************************************************************ */

  // Copy assignment
  SetLst& operator=(const SetLst& set); // Copy assignment of abstract types is not possible.

  // Move assignment
  SetLst& operator=(SetLst&& set) noexcept; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SetLst& set) const noexcept;
  bool operator!=(const SetLst& set) const noexcept;

  /* ************************************************************************ */

  virtual const Data& Min() const override;
  virtual Data MinNRemove() override;
  virtual void RemoveMin() override;

  virtual const Data& Max() const override;
  virtual Data MaxNRemove() override;
  virtual void RemoveMax() override;

  virtual const Data& Predecessor(const Data&) const override;
  virtual Data PredecessorNRemove(const Data&) override;
  virtual void RemovePredecessor(const Data&) override;

  virtual const Data& Successor(const Data&) const override;
  virtual Data SuccessorNRemove(const Data&) override;
  virtual void RemoveSuccessor(const Data&) override;

  // These functions are inherited from OrderedDictionaryContainer
  // All are pure virtual and must be implemented by derived classes
  // Min/Max functions must throw std::length_error when empty
  // Predecessor/Successor functions must throw std::length_error when element not found


                                                     
  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

    bool Insert(const Data&) override; // Override DictionaryContainer member (copy of the value)
    bool Insert(Data&&) override; // Override DictionaryContainer member (move of the value)
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

#include "setlst.cpp"

#endif
