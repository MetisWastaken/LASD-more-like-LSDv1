namespace lasd {

template<typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer<Data>& data) const noexcept {
  if (size != data.size) return false;
  for (ulong i = 0; i < size; i++) {
    if (operator[](i) != data.operator[](i)) return false;
  }
  return true;
}

template <typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const {
  for (ulong i = 0; i < size; i++) {
    fun(operator[](i));
  }
}

template<typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const {
  for (ulong i = size; i-- > 0;) {
    fun(operator[](i));
  }
}

template<typename Data>
inline void MutableLinearContainer<Data>::PreOrderMap(MapFun fun) {
  for (ulong i = 0; i < size; i++) {
    fun(operator[](i));
  }
}

template<typename Data>
inline void MutableLinearContainer<Data>::PostOrderMap(MapFun fun) {
  for (ulong i = size; i-- > 0;) {
    fun(operator[](i));
  }
}

template<typename Data>
inline void SortableLinearContainer<Data>::Sort() noexcept {
  if (size > 1) {
    InsertionSort(0, size - 1);
  }
}

template<typename Data>
inline void SortableLinearContainer<Data>::InsertionSort(ulong start, ulong end) noexcept {
  for (ulong i = start + 1; i <= end; i++) {
    Data key = (*this)[i];
    long j = i - 1;
    while (j >= static_cast<long>(start) && (*this)[j] > key) {
      const_cast<Data&>((*this)[j + 1]) = (*this)[j];
      j--;
    }
    const_cast<Data&>((*this)[j + 1]) = key;
  }
}

}