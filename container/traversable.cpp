
namespace lasd {

    template<typename Data>
    template<typename Accumulator>

    inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> fun, Accumulator accum)const{
        Traverse( //Prende una serie di parametri e tra tonde l'oggetto da studiare
            [fun,&accum](const Data data){
                accum=fun(data,accum); //fun definisce il comportamento, e per ogni singolo valore applica la funzione passata in input
            }
        );
        return accum;
    }

    template<typename Data>

    bool TraversableContainer<Data>::Exists(const Data& valore)const noexcept{
        Traverse( 
            [valore,&exist](const Data& data){
                exists|=(data==valore) 
            }
        );
        return exists;
    }


    template<typename Data>
   inline void PreOrderTraversableContainer<Data>::Traverse(TraverseFun fun) const
    {
            PreOrderTraverse(fun);
    }

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> fun, Accumulator accum)const
    {
        bool exists = false;
        PostOrderTraverse
        (
        [fun,&accum](const Data &data);
            {
            accum=fun(data,accum);
            }
        );

    return accum;
    }   

    template <typename Data>
    template <typename Accumulator>
    inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator>, Accumulator)const
    {
        PreOrderTraverse
        (
        [fun,&accum](const Data &data);
            {
            accum=fun(data,accum);
            }
        );

    return accum;
    }   


}
