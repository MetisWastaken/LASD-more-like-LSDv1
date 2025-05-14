
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public MutableLinearContainer<Data>, virtual public ClearableContainer {
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
   inline Node(Data&&)noexcept;
   inline Node(const Data& data) : element(data) {}
    /* ********************************************************************** */
    
    // Copy constructor
    inline Node(const Node& node) : element(node.element), next(node.next) {}
    // Move constructor
    inline Node(Node&& node) noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node();

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&)const noexcept;
    inline bool operator!=(const Node& node)const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };
  Node* head = nullptr;
  Node* tail = head;

  // ...

public:

  // Default constructor
  List()=default;
  // List() specifiers;
  

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a TraversableContainer
  // List(argument) specifiers; // A list obtained from a MappableContainer

  List(const TraversableContainer<Data>&);
  List(MappableContainer<Data>&&);

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;
  List(const List&);

  // Move constructor
  // List(argument) specifiers;
  List(List&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;
   virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  List& operator=(const List&);

  // Move assignment
  // type operator=(argument) specifiers;
  List& operator=(List&&) noexcept;

  /* ************************************************************************ */
   bool operator==(const List&) const noexcept;
  inline bool operator!=(const List&) const noexcept;

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions
  void InsertAtFront(const Data&);
  void InsertAtFront(Data&&) noexcept;
  void InsertAtBack(const Data&);
  void InsertAtBack(Data&&) noexcept;
  void RemoveFromFront();
  void RemoveFromBack();
  Data FrontNRemove();
  Data BackNRemove();


  // type InsertAtFront(argument) specifier; // Copy of the value
  // type InsertAtFront(argument) specifier; // Move of the value
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)

  /* ************************************************************************ */
Data& operator[](const ulong) override;
Data& Front() override;
Data& Back() override;
  // Specific member functions (inherited from MutableLinearContainer)
  // type operator[](argument) specifiers; // Override MutableLinearContainer member (must throw std::out_of_range when out of range)
  // type Front() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override MutableLinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */
const Data& operator[](const ulong) const override;
const Data& Front() const override;
const Data& Back() const override;

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
  void PreOrderMap(MapFun) override; 
 // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)
  void PostOrderMap(MapFun) override;
  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;
  void Traverse(TraverseFun)const override; 
  // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  void PostOrderTraverse(TraverseFun) const override;

 // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  void PreOrderTraverse(TraverseFun, const Node*) const;
  void PostOrderTraverse(TraverseFun, const Node*) const;
  void PreOrderMap(MapFun, Node*);
  void PostOrderMap(MapFun, Node*);

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
