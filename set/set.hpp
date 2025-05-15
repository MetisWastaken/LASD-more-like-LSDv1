
#ifndef SET_HPP
#define SET_HPP

/* ************************************************************************** */

#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Set: virtual public DictionaryContainer<Data>,virtual public TraversableContainer<Data>, virtual public ClearableContainer<Data> {
  // Must extend OrderedDictionaryContainer<Data>,
  //             LinearContainer<Data>,
  //             ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Set();

  /* ************************************************************************ */

  // Copy assignment
  bool operator=(const Set& set); // Copy assignment of abstract types is not possible.

  // Move assignment
  bool operator=(Set&& set) noexcept; // Move assignment of abstract types is not possible.

};

/* ************************************************************************** */

}

#endif
