namespace lasd {

/* ************************************************************************** */

template<typename Data>
template<typename Accumulator>
inline Accumulator TraversableContainer <Data>::Fold(FoldFun<Accumulator> fun, Accumulator accum) const {
    Traverse(
        [fun, &accum](const Data& data) {
            accum = fun(data, accum);
        }
    );
    return accum;
}

template<typename Data>
inline bool TraversableContainer <Data>::Exists(const Data& valore) const noexcept {
    bool exists = false;
    Traverse(
        [valore, &exists](const Data& data) {
            exists |= (data == valore);
        }
    );
    return exists;
}

/* ************************************************************************** */

/* ************************************************************************** */

template <typename Data>
template <typename Accumulator>
inline Accumulator PreOrderTraversableContainer <Data>::PreOrderFold(FoldFun<Accumulator> fun, Accumulator accum) const {
    PreOrderTraverse(
        [fun, &accum](const Data& data) {
            accum = fun(data, accum);
        }
    );
    return accum;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator PostOrderTraversableContainer <Data>::PostOrderFold(FoldFun<Accumulator> fun, Accumulator accum) const {
    PostOrderTraverse(
        [fun, &accum](const Data& data) {
            accum = fun(data, accum);
        }
    );
    return accum;
}

/* ************************************************************************** */

}

