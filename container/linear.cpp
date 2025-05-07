
namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer<Data>& dato) const noexcept
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

template<typename Data>
inline const Data& LinearContainer<Data>::Front()const{
    return operator[](0);
}

template<typename Data>
inline const Data& LinearContainer<Data>::Back()const{
    return operator[](size-1);
}

template<typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun fun) const
{
    PreOrderTraverse(fun);
}

template <typename Data> 
inline void MutableLinearContainer<Data>::Map(Mapfun fun){
    PreOrderMap(fun);   
}

template <typename Data>
void MutableLinearContainer<Data>::PostOrderMap(MapFun fun){
   ulong i=size;
   while(i>0){
    fun(operator[](i--));
   }
}
template <typename Data> 
void LinearContainer<Data>::PreOrderMap(MapFun fun) const
{
    for (ulong i=0;i<size;i++)
    {
        fun(operator[](i));
    }
}

template <typename Data>
void SortableLinearContainer<Data>::Sort()noexcept{
    Sort(0,size-1);  
}

template <typename Data>
void SortableLinearContainer<Data>::Sort(ulong start, ulong end)noexcept{
    for (ulong i=start+1; i<=end; i++) {
        Data key=operator[](i);
        ulong j=i;
        while (j>start && operator[](j-1)>key) {
            // Sposta l'elemento a destra
            const_cast(operator[](j))=operator[](j-1);
            j--;
        }
        // Inserisce l'elemento nella posizione corretta
        const_cast<Data&>(operator[](j))=key;
    }
}



/* ************************************************************************** */
}