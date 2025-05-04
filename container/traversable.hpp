
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
  class TraversableContainer: virtual public TestableContainer<Data>{
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

virtual ~TraversableContainer() = default;

  // Destructor
  // ~TraversableContainer() specifiers

  /* ************************************************************************ */

  TraversableContainer& operator=(const TraversableContainer&) = delete;
  TraversableContainer& operator=(TraversableContainer&&) noexcept = delete;

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  bool operator == (const TraversableContainer&) const noexcept = delete;
  bool operator != (TraversableContainer&&) const noexcept = delete; 


  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */
  

  using TraverseFun = std::function<void(const Data &)>;


  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>;

  virtual void Traverse(TraverseFun) const = 0; 
  
  template <typename Accumulator>
  Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;


  // Specific member function

  // type Traverse(arguments) specifiers;
  // type Fold(arguments) specifiers;

  /* ************************************************************************ */

  // type Exists(argument) specifiers; 

  bool Exists(const Data&) const noexcept override;

};


/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer: virtual public TraversableContainer<Data>{
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
   virtual ~PreOrderTraversableContainer()=default ;

  /* ************************************************************************ */


  PreOrderTraversableContainer& operator=(const PreOrderTraversableContainer&) = delete;                  
  PreOrderTraversableContainer& operator=(PreOrderTraversableContainer&&) noexcept = delete;
  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderTraversableContainer&) const noexcept = delete;
  bool operator!=(const PreOrderTraversableContainer&) const noexcept = delete;

  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */


  // Specific member function
  using typename TraversableContainer<Data>::TraverseFun;
  
    template <typename Accumulator>
    using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

    virtual void PreOrderTraverse(TraverseFun) const = 0;

    template <typename Accumulator>
    Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;
  
  

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  // type Traverse(arguments) specifiers; // Override TraversableContainer member

  void Traverse(TraverseFun fun) const override{
    PreOrderTraverse(fun);
  }

};


/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderTraversableContainer() = default;

  /* ************************************************************************ */

  PostOrderTraversableContainer& operator=(const PostOrderTraversableContainer&)=delete;
  PostOrderTraversableContainer& operator=(PostOrderTraversableContainer&&) noexcept = delete;

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types is not possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  bool operator==(const PostOrderTraversableContainer&) const noexcept=delete;
  bool operator!=(const PostOrderTraversableContainer&) const noexcept=delete;


  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename::TraversableContainer<Data>::TraverseFun;

  template template <typename Accumulator>

  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  virtual void PostOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  Accumulator PostOrderFold(FoldFun<Accumulator>,Accumulator)const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  void Traverse(TraverseFun fun) const override{
    PostOrderTraverse(fun);
  } // Override TraversableContainer member

};

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
