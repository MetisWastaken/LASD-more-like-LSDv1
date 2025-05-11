
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  /************************************************************************* */
  Container()= default; // Default constructor 

  ulong size = 0;

public:
  virtual ~Container() = default; // Destructor

  /* ************************************************************************ */

  Container& operator=(const Container&)=delete;
  Container& operator=(const Container&&) noexcept=delete;
   //cannot move or copy obj "Container" type

  /* ************************************************************************ */

  // Comparison operators impossible for abstract types
  
  bool operator==(const Container&) const noexcept= delete; 
  bool operator!=(const Container&) const noexcept = delete;
  
  /* ************************************************************************ */

  inline virtual bool Empty()const noexcept{
    return(size==0);
  }

 inline  virtual ulong Size()const noexcept{
    return size;
  }
  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)

  // type Size() specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

class ClearableContainer: virtual public Container {
  // Must extend Container
private:

  // ...

protected:

  // ...

public:

virtual ~ClearableContainer() = default; // Destructor

  /* ************************************************************************ */

  ClearableContainer& operator=(const ClearableContainer&)=delete; //copy
  ClearableContainer& operator=(const ClearableContainer&&) noexcept=delete; //move

  /* ************************************************************************ */

 bool operator==(const ClearableContainer&) const noexcept= delete;
 bool operator!=(const ClearableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  virtual void Clear()= 0; //container reset at 0 value 
};

/* ************************************************************************** */

class ResizableContainer: virtual public ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  //Destructor

  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  ResizableContainer& operator = (const ResizableContainer&)=delete;
  ResizableContainer& operator = (ResizableContainer&&) noexcept=delete;
  /* ************************************************************************ */

  // Comparison operators

  bool operator ==(const ResizableContainer&) const noexcept=delete;
  bool operator !=(const ResizableContainer&) const noexcept=delete;


  /* ************************************************************************ */
  virtual void Resize(ulong)=0; //modified

  // type Resize(argument) specifiers;

  /* ************************************************************************ */
  inline void Clear()override{
    Resize(0);
  }

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#endif
