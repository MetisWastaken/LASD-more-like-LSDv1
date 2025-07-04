#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public PreOrderTraversableContainer<Data>, virtual public PostOrderTraversableContainer<Data> {
  // Must extend PreOrderTraversableContainer<Data>,  
  //             PostOrderTraversableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  // Destructor
  ~LinearContainer()=default;

  /* ************************************************************************ */

  LinearContainer& operator = (const LinearContainer&) = delete;
  LinearContainer& operator = (LinearContainer&&) noexcept = delete;

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  bool operator==(const LinearContainer&) const noexcept;
  inline bool operator!=(const LinearContainer& con) const noexcept { return !(*this == con); }; //ho da aggiungere qualcosa, ma non ho ben chiaro cosa


  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& operator[](ulong index) const {
    throw std::out_of_range("operator[]: index out of range");
  } // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  

  virtual const Data& Front() const { 
    if (size == 0) throw std::length_error("Front: container is empty");
    return (*this)[0]; 
  } // (non-mutable version; concrete function must throw std::length_error when empty)

  virtual const Data& Back() const { 
    if (size == 0) throw std::length_error("Back: container is empty");
    return operator[](size-1); //double check pls
  } // (non-mutable version; concrete function must throw std::length_error when empty) //da rivedere, not sure
   

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  inline void Traverse(TraverseFun fun) const override { PreOrderTraverse(fun); }; // Override TraversableContainer member

  /* ************************************************************************ */

  void PreOrderTraverse(TraverseFun) const override;

  // Specific member function (inherited from PreOrderTraversableContainer)

  // type PreOrderTraverse(argument) specifiers; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  void PostOrderTraverse(TraverseFun) const override;

  // Specific member function (inherited from PostOrderTraversableContainer)

  // type PostOrderTraverse(argument) specifiers; // Override PostOrderTraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableLinearContainer: virtual public LinearContainer<Data>, virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data> {
  // Must extend LinearContai ner<Data>, 
  //PreOrderMappableContainer<Data>,
  //PostOrderMappableContainer<Data>

private:

  // ...

protected:

using Container::size;
using LinearContainer<Data>::operator[];
using LinearContainer<Data>::Front;
using LinearContainer<Data>::Back;


public:

  // Destructor
  ~MutableLinearContainer()=default;

  /* ************************************************************************ */
  MutableLinearContainer& operator=(const LinearContainer<Data>&) = delete;
  MutableLinearContainer& operator=(LinearContainer<Data>&&) noexcept = delete;

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */
    
  // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)

  virtual Data& operator[](ulong) = 0;

  // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  
  virtual Data& Front() { 
    if (this->size == 0) throw std::length_error("Front: container is empty");
    return (*this)[0]; 
  }

  // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
    virtual Data& Back() { 
      if (this->size == 0) throw std::length_error("Back: container is empty");
      return (*this)[this->size-1]; 
    }


  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map (MapFun fun) override { 
    PreOrderMap(fun); 
  }// Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun) override;

};

template <typename Data>
class SortableLinearContainer: virtual public MutableLinearContainer<Data>{
  // Must extend MutableLinearContainer<Data>

private:

  // ...

protected:   
  using Container::size;
  using MutableLinearContainer<Data>::operator[];
  using MutableLinearContainer<Data>::Front;
  using MutableLinearContainer<Data>::Back;

  void InsertionSort(ulong, ulong) noexcept;

public:

  // Destructor
  ~SortableLinearContainer()=default;

  /* ************************************************************************ */

  SortableLinearContainer& operator = (const SortableLinearContainer&)= delete;
  SortableLinearContainer& operator = (SortableLinearContainer&&) noexcept = delete;

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not be possible.

  

  /* ************************************************************************ */

  // Specific member function

  void Sort()noexcept;
};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
