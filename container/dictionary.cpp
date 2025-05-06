
namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& Tcon ){
    bool all=true;
    Tcon.Traverse(
        [this,&all](const Data&data){
            all&=Insert(data);
        }
    );
return all;
}

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& Tcon){
    bool all=true;

    Tcon.map(
        [this,&all](const Data&data){
            all&=Insert(std::move(data));
        }
    );
    return all;
}

template<typename Data>

bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& Tcon ){
    bool some=false;
    Tcon.Traverse(
        [this,&some](const Data&data){
            some|=Insert(data);
        }
    );
    return some;
}
template <typename Data>
bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& Tcon)
{
    bool some = false;
    Tcon.Map(
        [this, &some] (Data&data) 
        {
            some|=Insert(std::move(data));
        }
    );
    return some;
}

template <typename Data>
bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& Tcon){
    bool all=true;
    Tcon.Traverse(
        [this,&all](const Data&data){
            all&=Remove(data);
        }
    );
    return all;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& Tcon){
    bool some=false;
    Tcon.Traverse(
        [this,&some](const data&data){
            some|=Remove(data);
        }
    );
    return some;
}



/* ************************************************************************** */

}
