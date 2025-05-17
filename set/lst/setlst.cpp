namespace lasd {

template <typename Data>
SetLst<Data>::SetLst(const SetLst<Data>& set) : List<Data>() {
    set.Traverse([this](const Data& data) {
        this->Insert(data);
    });
}


template <typename Data>
SetLst<Data>::SetLst(SetLst<Data>&& set) noexcept : List<Data>() {
    std::swap(this->head, set.head);
    std::swap(this->tail, set.tail);
    std::swap(this->size, set.size);
    set.head = nullptr;
    set.tail = nullptr;
    set.size = 0;
}


template <typename Data>
SetLst<Data>::SetLst(const TraversableContainer<Data>& cont) {
    cont.Traverse([this](const Data& data) {
        Insert(data);
    });
}

template <typename Data>
SetLst<Data>::SetLst(MappableContainer<Data>&& cont) {
    cont.Map([this](Data& data) {
        Insert(std::move(data));
    });
}

template <typename Data>
SetLst<Data>& SetLst<Data>::operator=(const SetLst<Data>& set) {
    if (this != &set) {
        Clear();
        set.Traverse([this](const Data& data) {
            Insert(data);
        });

    }
    return *this;
}

template <typename Data>
SetLst<Data>& SetLst<Data>::operator=(SetLst<Data>&& set) noexcept {
    if (this != &set) {
        std::swap(this->head, set.head);
        std::swap(this->tail, set.tail);
        std::swap(this->size, set.size);
    }
    return *this;
}

template <typename Data>
bool SetLst<Data>::operator==(const SetLst<Data>& set) const noexcept 
{
    return List<Data>::operator==(set);
}

template <typename Data>
bool SetLst<Data>::operator!=(const SetLst<Data>& set) const noexcept {
    return !(*this == set);
}


template <typename Data>
bool SetLst<Data>::Insert(Data&& data) {

    if (BinarySearch(data) != nullptr) {
        return false;
    }
    if (size == 0 || data > tail->element) {
        List<Data>::InsertAtBack(std::move(data));
        return true;
    }
    if (data < head->element) {
        List<Data>::InsertAtFront(std::move(data));
        return true;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->element < data) {
        temp = temp->next;
    }
    Node* newNode = new Node(std::move(data));
    newNode->next = temp->next;
    temp->next = newNode;
    ++size;
    return true;
}

template <typename Data>
bool SetLst<Data>::Insert(const Data& data) {
    if (BinarySearch(data) != nullptr) {
        return false;
    }
    if (size == 0 || data > tail->element) {
        List<Data>::InsertAtBack(data);
        return true;
    }
    if (data < head->element) {
        List<Data>::InsertAtFront(data);
        return true;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->element < data) {
        temp = temp->next;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    ++size;
    return true;
}

template <typename Data>
bool SetLst<Data>::Remove(const Data& data) {
    const Data* found = BinarySearch(data);
    if (!found) {
        return false;
    }
    if (data == tail->element) {
        List<Data>::RemoveFromBack();
        return true;
    }
    if (data == head->element) {
        List<Data>::RemoveFromFront();
        return true;
    }
    Node* temp = head;
    while (temp->next != nullptr && !(temp->next->element == data)) {
        temp = temp->next;
    }
    if (temp->next != nullptr) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        --size;
        if (temp->next == nullptr) {
            tail = temp;
        }
        return true;
    }
    return false;
}

template <typename Data>
const Data& SetLst<Data>::operator[](ulong index) const {
    return List<Data>::operator[](index);
}

template <typename Data>
bool SetLst<Data>::Exists(const Data& data) const noexcept {
    return (BinarySearch(data) != nullptr);
}

template <typename Data>
void SetLst<Data>::Clear() {
    List<Data>::Clear();
}

template <typename Data>
const Data& SetLst<Data>::Min() const {
    if (this->size == 0) throw std::length_error("Set is empty");
    return this->head->element;
}

template <typename Data>
Data SetLst<Data>::MinNRemove() {
    if (this->size == 0) throw std::length_error("Set is empty");
    Data min = this->head->element;
    this->RemoveMin();
    return min;
}

template <typename Data>
void SetLst<Data>::RemoveMin() {
    if (this->size == 0) throw std::length_error("Set is empty");
    this->RemoveFromFront();
}

template <typename Data>
const Data& SetLst<Data>::Max() const {
    if (this->size == 0) throw std::length_error("Set is empty");
    return this->tail->element;
}

template <typename Data>
Data SetLst<Data>::MaxNRemove() {
    if (this->size == 0) throw std::length_error("Set is empty");
    Data max = this->tail->element;
    this->RemoveMax();
    return max;
}

template <typename Data>
void SetLst<Data>::RemoveMax() {
    if (this->size == 0) throw std::length_error("Set is empty");
    this->RemoveFromBack();
}

template <typename Data>
const Data& SetLst<Data>::Predecessor(const Data& data) const {
    if (this->size == 0) throw std::length_error("Set is empty");
    Node* temp = this->head;
    Node* pred = nullptr;
    while (temp != nullptr && temp->element < data) {
        pred = temp;
        temp = temp->next;
    }
    if (pred == nullptr) throw std::length_error("No predecessor found");
    return pred->element;
}

template <typename Data>
Data SetLst<Data>::PredecessorNRemove(const Data& data) {
    const Data& pred = Predecessor(data);
    this->Remove(pred);
    return pred;
}

template <typename Data>
void SetLst<Data>::RemovePredecessor(const Data& data) {
    const Data& pred = Predecessor(data);
    this->Remove(pred);
}

template <typename Data>
const Data& SetLst<Data>::Successor(const Data& data) const {
    if (this->size == 0) throw std::length_error("Set is empty");
    Node* temp = this->head;
    while (temp != nullptr && temp->element <= data) {
        temp = temp->next;
    }
    if (temp == nullptr) throw std::length_error("No successor found");
    return temp->element;
}

template <typename Data>
Data SetLst<Data>::SuccessorNRemove(const Data& data) {
    const Data& succ = Successor(data);
    this->Remove(succ);
    return succ;
}

template <typename Data>
void SetLst<Data>::RemoveSuccessor(const Data& data) {
    const Data& succ = Successor(data);
    this->Remove(succ);
}

template <typename Data>
const Data* SetLst<Data>::BinarySearch(const Data& value) const {
    if (this->size == 0) return nullptr;
    long left = 0;
    long right = this->size - 1;
    while (left <= right) {
        long mid = left + (right - left) / 2;
        Node* curr = this->head;
        for (long i = 0; i < mid; ++i) {
            curr = curr->next;
        }
        if (curr->element == value) {
            return &(curr->element);
        } else if (curr->element < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return nullptr;
}
}


