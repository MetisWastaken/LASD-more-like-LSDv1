namespace lasd {

template <typename Data>
SetVec<Data>::SetVec(){
    elements.Resize(5); 
    size = 0;
    head = 0;
    tail = 0;
}

template <typename Data>
SetVec<Data>::SetVec(const TraversableContainer<Data>& cont) {
    elements.Resize(cont.Size()*3); 
    size=0;
  cont.Traverse(
    [this](const Data& val) {
      this->Insert(val);
    }
  );
}


template <typename Data>
SetVec<Data>::SetVec(MappableContainer<Data>&& cont) {
    elements.Resize(cont.Size()*3); 
    size=0;
  cont.Map(
    [this](Data& val) {
      this->Insert(std::move(val));
    }
  );
}


template <typename Data>
SetVec<Data>::SetVec(const SetVec<Data>& set) {
    *this=set;
}


template <typename Data>
SetVec<Data>::SetVec(SetVec<Data>&& set) noexcept {
    *this=std::move(set);
}


template <typename Data>
SetVec<Data>& SetVec<Data>::operator=(const SetVec<Data>& set) {
    head=set.head;
    tail=set.tail;
    size=set.size;
    elements = set.elements; 
    return *this;
}

// Move assignment
template <typename Data>
SetVec<Data>& SetVec<Data>::operator=(SetVec<Data>&& set) noexcept {
        std::swap(head, set.head);
        std::swap(tail, set.tail);
        std::swap(size, set.size);
        elements = std::move(set.elements);
    return *this;
}

// Comparison operators
template <typename Data>
bool SetVec<Data>::operator==(const SetVec<Data>& set) const noexcept {
     if(size!= set.size) return false;
     for(ulong i=0; i<size; i++){
        if((*this)[i] != set[i]) {
            return false;
        }
     }
     return true;
}


template <typename Data>
bool SetVec<Data>::operator!=(const SetVec<Data>& set) const noexcept {
    return !(*this == set);
}


template <typename Data>
bool SetVec<Data>::Insert(const Data& value) {
   if(Exists(value)) return false;

   ulong pos=BinarySearch(value);
   ChangeCapacity();
   Expand(pos);
   elements[(head+pos)%elements.Size()] = value;
   size++;
   return true;
}

template <typename Data>
bool SetVec<Data>::Insert(Data&& value) {
 if(Exists(value)) return false;

   ulong pos=BinarySearch(value);
   ChangeCapacity();
   Expand(pos);
   elements[(head+pos)%elements.Size()] = std::move(value);
   size++;
   return true;
}


template <typename Data>
bool SetVec<Data>::Remove(const Data& value) 
{
 if(!Exists(value)) return false;

    ulong pos = BinarySearch(value);

    Reduce(pos);
    size--;
    ChangeCapacity();
    return true;
}


template <typename Data>
bool SetVec<Data>::Exists(const Data& value) const noexcept {

    if(size==0)
        return false;
    
    ulong pos = BinarySearch(value);

    if(pos < size && elements[pos] == value) {
        return true;
    }
    return false;
}


template <typename Data>
const Data& SetVec<Data>::operator[](ulong index) const {
    if (elements.Size() == 0)
        throw std::out_of_range("Empty set");
    return elements[(head+index)%elements.Size()];
}


template <typename Data>
void SetVec<Data>::Clear() {
    size=0;
    head = 0;
    tail = 0;
    elements.Clear();
    elements.Resize(5);
}

template <typename Data>
const Data& SetVec<Data>::Min() const {
    if (elements.Size() == 0)
        throw std::length_error("Set is empty");
    return (*this)[0];
}


template <typename Data>
Data SetVec<Data>::MinNRemove() {
    if (elements.Size() == 0)
        throw std::length_error("Set is empty");
    Data min = (*this)[0];
    RemoveMin();
    return min;
}


template <typename Data>
void SetVec<Data>::RemoveMin() {
    if (elements.Size() == 0)
        throw std::length_error("Set is empty");
    Remove((*this)[0]);
}

template <typename Data>
const Data& SetVec<Data>::Max() const {
    if (elements.Size() == 0)
        throw std::length_error("Set is empty");
    return (*this)[size-1];
}


template <typename Data>
Data SetVec<Data>::MaxNRemove() {
    if (size == 0)
        throw std::length_error("Set is empty");
    Data max = (*this)[size- 1];
    RemoveMax();
    return max;
}


template <typename Data>
void SetVec<Data>::RemoveMax() {
    if (size == 0)
        throw std::length_error("Set is empty");
    Remove((*this)[size- 1]);
}


template <typename Data>
const Data& SetVec<Data>::Predecessor(const Data& value) const {
    if (size == 0)
        throw std::length_error("Set is empty");

    long pos = BinarySearch( value);
    if (pos == 0)
        throw std::length_error("No predecessor found");
    return (*this)[pos-1];
}


template <typename Data>
Data SetVec<Data>::PredecessorNRemove(const Data& value) {
    const Data& pred = Predecessor(value);
    Remove(pred);
    return pred;
}


template <typename Data>
void SetVec<Data>::RemovePredecessor(const Data& value) {
    const Data& pred = Predecessor(value);
    Remove(pred);
}


template <typename Data>
const Data& SetVec<Data>::Successor(const Data& value) const {
    if (elements.Size() == 0)
        throw std::length_error("Set is empty");
    ulong pos = BinarySearch(value);
    if (pos >= size)
        throw std::length_error("No successor");
    if ((*this)[pos] == value)
        return (*this)[pos + 1];
    else
        return (*this)[pos];
}


template <typename Data>
Data SetVec<Data>::SuccessorNRemove(const Data& value) {
    const Data& succ = Successor(value);
    Remove(succ);
    return succ;
}


template <typename Data>
void SetVec<Data>::RemoveSuccessor(const Data& value) {
    const Data& succ = Successor(value);
    Remove(succ);
}

template<typename Data>
void SetVec<Data>::Reduce(ulong pos){

    ulong cap=elements.Size();

    if(pos < size/2){
        ulong i = (head + pos) % cap;

        while(i != (head + cap - 1)%cap){
            ulong prev = (i+cap-1)%cap;

            elements[i] = std::move(elements[prev]);

            i=prev;
        }

        head = (head + 1)%cap;
    }else{
        ulong i = (head + pos) % cap;

        while(i != tail){
            ulong next = (i+1)%cap;

            elements[i] = std::move(elements[next]);

            i=next;
        }

        tail = (tail + cap - 1)%cap;
    }
}

template<typename Data>
void SetVec<Data>::Expand(ulong pos){
    ulong cap = elements.Size();

    if(pos < size/2){
        ulong insertIndex = (head + pos) % cap;
        ulong i = tail;

        while (i != insertIndex)
        {
            ulong prev = (i + cap - 1) % cap;
            elements[i] = std::move(elements[prev]);
            i = prev;
        }

        tail = (tail + 1) % cap;

    } else {
        ulong insertIndex = (head + pos) % cap;
        ulong i = head;

        while (i != insertIndex)
        {
            ulong prev = (i + cap - 1) % cap;
            elements[prev] = std::move(elements[i]);
            i = (i + 1) % cap;
        }

        head = (head + cap - 1) % cap;
    }
}


template <typename Data>
void SetVec<Data>::ChangeCapacity(){
    if(size*2>elements.Size()){
        ulong newsize = elements.Size() * 2;
        Vector<Data> newVec(newsize);
        for(ulong i=0; i<size; i++){
            newVec[i] = std::move(elements[(head+i)%elements.Size()]);
        }
        elements = std::move(newVec);
        head = 0;
        tail = size;
    }else if(size < elements.Size()/4){
        ulong newsize = elements.Size()/2;
        Vector<Data> newVec(newsize);
        for(ulong i=0; i<size; i++){
            newVec[i] = std::move(elements[(head+i)%elements.Size()]);
        }
        elements = std::move(newVec);
        head = 0;
        tail = size;
        }
}



template <typename Data>
ulong SetVec<Data>::BinarySearch(const Data& value) const{
 if (size == 0)
            return 0;

        ulong low = 0;
        ulong high = size;

        while (low < high)
        {
            ulong mid = low + (high - low) / 2;
            Data midValue = (*this)[mid];

            if(midValue == value)
                return mid;

            if (midValue < value)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
}

}
