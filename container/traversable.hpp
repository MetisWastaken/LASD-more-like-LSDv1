
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>
#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer : virtual public TestableContainer<Data> {
  // Must extend TestableContainer<Data>

protected:

//...
 
public:

  virtual ~TraversableContainer() = default;

  TraversableContainer& operator=(const TraversableContainer&) = delete;
  TraversableContainer& operator=(TraversableContainer&&) noexcept = delete;

  bool operator==(const TraversableContainer&) const noexcept = delete;
  bool operator!=(const TraversableContainer&) const noexcept = delete;

  using TraverseFun = std::function<void(const Data &)>;
  virtual void Traverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data&, const Accumulator&)>;

  template <typename Accumulator>
  Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;


  bool Exists(const Data&) const noexcept override;
};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer : virtual public TraversableContainer<Data> {
  
public:
  ~PreOrderTraversableContainer() = default;

  PreOrderTraversableContainer& operator=(const PreOrderTraversableContainer&) = delete;
  PreOrderTraversableContainer& operator=(PreOrderTraversableContainer&&) noexcept = delete;

  bool operator==(const PreOrderTraversableContainer&) const noexcept = delete;
  bool operator!=(const PreOrderTraversableContainer&) const noexcept = delete;

  using typename TraversableContainer<Data>::TraverseFun;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::template FoldFun<Accumulator>;

  virtual void PreOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;

  void Traverse(TraverseFun fun) const override {
    PreOrderTraverse(fun);
  }
};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer : virtual public TraversableContainer<Data> {
 private:

public:

public:
 ~PostOrderTraversableContainer() = default;

  PostOrderTraversableContainer& operator=(const PostOrderTraversableContainer&) = delete;
  PostOrderTraversableContainer& operator=(PostOrderTraversableContainer&&) noexcept = delete;

  bool operator==(const PostOrderTraversableContainer&) const noexcept = delete;
  bool operator!=(const PostOrderTraversableContainer&) const noexcept = delete;

  using typename TraversableContainer<Data>::TraverseFun;
  template <typename Accumulator>
  
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;
  virtual void PreOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  Accumulator PostOrderFold(FoldFun<Accumulator>, Accumulator) const;

  void Traverse(TraverseFun fun) const override {
    PostOrderTraverse(fun);
  }
};

/* ************************************************************************** */

} // namespace lasd

#include "traversable.cpp"

#endif // TRAVERSABLE_HPP
