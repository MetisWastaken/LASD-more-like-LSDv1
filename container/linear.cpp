
namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer<Data>& dato) const noexcept
{
    if(size!=dato.size){
        return false;
    }
    for (ulong i = 0; i < size; i++)
    {
        if (operator[](i) != dato.operator[](i))
            return false;
    }
    return true;
}

template <typename Data>
void MutableLinearContainer<Data>::PostOrderMap(MapFun fun){
    if(size>0){
        for(ulong i=size-1; i>=0;i--){ //double check pls
            fun(operator[](i));
        }
    }
}

template <typename Data>
void SortableLinearContainer<Data>::Sort()noexcept{
    InSort(0,size-1);  
}

template<typename Data>

void SortableLinearContainer<Data>::InSort()noexcept{
    //need help

}


/* ************************************************************************** */
}