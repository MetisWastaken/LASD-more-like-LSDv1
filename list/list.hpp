
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List: virtual public MutableLinearContainer<Data>,virtual public ClearableContainer {
  // Must extend MutableLinearContainer<Data>,
  //             ClearableContainer

private:

  // ...

protected:

  using Container::size;

  struct Node {

    // Data
    Data element;
    Node* next=nullptr;

    /* ********************************************************************** */

    // Specific constructors
    inline Node()=default;
    

    /* ********************************************************************** */
    inline Node(const Data& data) : element(data) {}
    // Copy constructor
    // ...
    inline Node(Data&&)noexcept;
    // Move constructor
    // ...

    /* ********************************************************************** */

    // Destructor
    ~Node()=default;

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&)const noexcept;
    inline bool operator!=(const Node&)const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...

public:

  // Default constructor
  // List() specifiers;
  Node* head {nullptr};
  Node* tail {nullptr};

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
  // List(argument) specifiers; // A list obtained from a MappableContainer

  inline List(const TraversableContainer<Data>&);
  inline List(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;
  inline List(const List&);

  // Move constructor
  // List(argument) specifiers;
  inline List(List&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;
   inline ~List()=default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
   inline List& operator=(const List&);

  // Move assignment
  // type operator=(argument) specifiers;
  inline List& operator=(List&&) noexcept;

  /* ************************************************************************ */
  inline bool operator==(const List&) const noexcept;
  inline bool operator!=(const List&) const noexcept;

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions
  inline void InsertAtFront(const Data&);
  inline void InsertAtFront(Data&&);
  inline void InsertAtBack(const Data&);
  inline void InsertAtBack(Data&&);
  inline void RemoveFromFront();
  inline Data FrontNRemove();

  // type InsertAtFront(argument) specifier; // Copy of the value
  // type InsertAtFront(argument) specifier; // Move of the value
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableLinearContainer)
  // type operator[](argument) specifiers; // Override MutableLinearContainer member (must throw std::out_of_range when out of range)
  // type Front() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  const Data& operator[](const ulong) const override;
  Data& operator[](const unsigned long int) override;
  inline const Data& Front() const override;
  inline Data& Front() override;
  inline const Data& Back() const override;
  inline Data& Back() override;

  // Specific member functions (inherited from LinearContainer)
  // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)
  // type Front() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */
  using typename MappableContainer<Data>::MapFun;
  // Specific member function (inherited from MappableContainer)

  void Map(MapFun) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)
  inline void PreOrderMap(MapFun) override; 
 // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)
  inline void PostOrderMap(MapFun) override;
  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;
   // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  inline void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

   // inline void PostOrderMap(MapFun) override;

 // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
