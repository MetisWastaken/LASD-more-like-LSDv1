
namespace lasd {

    template<typename Data>
    template<typename Accumulator>

    Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> fun, Accumulator accum)const{
        Traverse( //Prende una serie di parametri e tra tonde l'oggetto da studiare
            [fun,&accum](const Data obj){
                accum=fun(obj,accum) //fun definisce il comportamento, e per ogni singolo valore applica la funzione passata in input
            }
        );
        return accum;
    }

    template<typename Data>
    template<typename Accumulator>

    Accumulator TraversableContainer<Data>::Exist(const Data& valore)const{
        Traverse( 
            [val,&exist](const Data& data){
                Exists=(data==valore) 
            }
        );
        return Exist;
    }
}
