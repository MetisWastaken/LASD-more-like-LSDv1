
#include <iostream>

namespace lasd 
{
/* ************************************************************************ */

// Specific constructors
template <typename Data>
Vector<Data>::Vector(const ulong newsize)
{
    try {
        size = newsize;
        Elements = new Data[size]{};
    } catch(const std::exception& e) {
        size = 0;
        Elements = nullptr;
        std::cerr << e.what() << '\n';
    }
}

template <typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>& cont)
    : Vector(cont.Size())
{
    ulong i = 0;
    cont.Traverse(
        [this, &i](const Data& data) {
            Elements[i++] = data;
        }
    );
}

template <typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& cont)
    : Vector(cont.Size())
{
    ulong i = 0;
    cont.Map(
        [this, &i](Data& data) {
            Elements[i++] = std::move(data);
        }
    );
}

/* ************************************************************************** */
//copy constructor
template <typename Data>
Vector<Data>::Vector(const Vector& vect)
{
    size = vect.size;
    Elements = new Data[size];
    std::copy(vect.Elements, vect.Elements + size, Elements);
}

//move constructor
template <typename Data>
Vector<Data>::Vector(Vector&& vect) noexcept
{
    std::swap(size, vect.size);
    std::swap(Elements, vect.Elements);
}

/* ************************************************************************** */
//copy assignment (Vector)
template <typename Data>
Vector<Data>& Vector<Data>::operator = (const Vector<Data>& vect)
{
    Vector<Data> temp(vect);
    std::swap(*this, temp);
    return *this;
}

//move assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator = (Vector<Data>&& vect) noexcept
{
    std::swap(size, vect.size);
    std::swap(Elements, vect.Elements);
    return *this;
}

/* ************************************************************************** */
//comparison operators 
template <typename Data>
bool Vector<Data>::operator == (const Vector<Data>& vect) const noexcept
{
    if(size == vect.size)
    {
        for(ulong i = 0; i < size; i++)
        {
            if(Elements[i] != vect.Elements[i])
                return false;
        }
        return true;
    }
    return false;
}


template <typename Data>
inline bool Vector<Data>::operator != (const Vector<Data>& vect) const noexcept
{
    return !(*this == vect);
}

/* ************************************************************************ */

// Specific member functions (inherited from MutableLinearContainer)
template <typename Data>
Data& Vector<Data>::operator [] (const ulong i)
{
    if(i < size)
        return Elements[i];
    else
        throw std::out_of_range("Access at index " + std::to_string(i) + "; vector size" + std::to_string(size));
}

template <typename Data>
Data& Vector<Data>::Front()
{
    if(size != 0)
        return Elements[0];
    else
        throw std::length_error("Access to empty vector.");
}

template <typename Data>
Data& Vector<Data>::Back()
{
    if(size != 0)
        return Elements[size - 1];
    else
        throw std::length_error("Access to empty vector.");
}


/* ************************************************************************ */
// Specific member functions (inherited from LinearContainer)
template <typename Data>
const Data& Vector<Data>::operator[](const ulong i) const 
{
    return const_cast<Vector<Data>&>(*this)[i];
}

template <typename Data>
const Data& Vector<Data>::Front() const
{
    return const_cast<Vector<Data>&>(*this).Front();
}

template <typename Data>
const Data& Vector<Data>::Back() const
{
    return const_cast<Vector<Data>&>(*this).Back();
}

/* ************************************************************************ */
// Specific member function (inherited from ClearableContainer and ResizeableContainer)
template <typename Data>
void Vector<Data>::Clear()
{
    delete[] Elements;
    Elements = nullptr;
    size = 0;
}

template <typename Data>
void Vector<Data>::Resize(const ulong newsize)
{
    if(newsize == 0)
        Clear();
    else if(size != newsize)
    {
        Data* temp = new Data[newsize] {};
        ulong minsize = (size < newsize) ? size : newsize;
        for(ulong i = 0; i < minsize; i++)
        {
            std::swap(Elements[i], temp[i]);
        }
        std::swap(Elements, temp);
        size = newsize;
        delete[] temp;
    }
}

/* ************************************************************************** */
//specific constructor (SortableVector)

template <typename Data>
SortableVector<Data>::SortableVector(const ulong newsize) : Vector<Data>(newsize) {}

template <typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& cont) : Vector<Data>(cont) {}

template <typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& cont) : Vector<Data>(std::move(cont)) {}

/* ************************************************************************** */
// Copy Constructor and Move Constructor (SortableVector)
template <typename Data>
SortableVector<Data>::SortableVector(const SortableVector<Data>& vect) : Vector<Data>(vect) {}

template <typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data>&& vect) noexcept : Vector<Data>(std::move(vect)) {}

/* ************************************************************************** */
//Copy Assignment and Move Assignment (SortableVector)
template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator = (const SortableVector<Data>& vect)
{
    Vector<Data>::operator=(vect);
    return *this;
}

template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator = (SortableVector<Data>&& vect) noexcept
{
    Vector<Data>::operator=(std::move(vect));
    return *this;
}


}
