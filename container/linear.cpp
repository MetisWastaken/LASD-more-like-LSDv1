
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
void SortableLinearContainer<Data>::InSort()noexcept{
    InSort(0,size-1);  
}

template <typename Data>
void SortableLinearContainer<Data>::InSort(ulong start, ulong end) noexcept {
    for (ulong i = start + 1; i <= end; ++i) {
        Data key = operator[](i);
        ulong j = i;
        while (j > start && operator[](j - 1) > key) {
            // Sposta l'elemento a destra
            const_cast<Data&>(operator[](j)) = operator[](j - 1);
            --j;
        }
        // Inserisce l'elemento nella posizione corretta
        const_cast<Data&>(operator[](j)) = key;
    }
}



/* ************************************************************************** */
}