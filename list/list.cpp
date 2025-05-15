
namespace lasd {

    template <typename Data>
    List<Data>::Node::Node(Data&& data)noexcept{
        std::swap(element,data);
    }

    template <typename Data>
    List<Data>::Node::Node(Node&& node)noexcept{
        std::swap(element,node.element);
        std::swap(next,node.next);
    }

    template <typename Data>
    List<Data>::Node::~Node(){
        delete next;
    }

    template <typename Data>
    bool List<Data>::Node::operator==(const Node& node) const noexcept{
        return (element == node.element) && 
               ((next == nullptr && node.next == nullptr) || 
                (next != nullptr && node.next != nullptr));
    }

    template <typename Data>
    inline bool List<Data>::Node::operator != (const Node& node)const noexcept{
        return !(*this == node); 
    }

    template <typename Data>
    List <Data>::List(const TraversableContainer<Data>& con){
        con.Traverse(
            [this](const Data& data){
                InsertAtBack(data);
            }
        );
    }

    template <typename Data>
    List <Data>::List(MappableContainer<Data>&& con){
        con.Map(
            [this](Data& data){
                InsertAtBack(std::move(data));
            }
        );
    }

    template <typename Data>
    List<Data>::List(const List<Data>& list){
        if (list.head != nullptr){
            Node* curr = list.head;
            Node* prev = nullptr;

            while (curr != nullptr){
                Node* newNode = new Node(curr->element);

                if (prev == nullptr)
                    head = newNode;
                else
                    prev->next = newNode;

                prev = newNode;
                curr = curr->next;
            }

            tail = prev;
            size = list.size;
        }
    }

    template <typename Data>
    List<Data>::List(List<Data>&& lst)noexcept {
        if(lst.tail!=nullptr) {
            std::swap(head,lst.head);
            std::swap(tail,lst.tail);
            std::swap(size,lst.size);
        }
    }


    template <typename Data>
    List<Data>::~List(){
        delete head;
        head = tail = nullptr;
        size = 0;
    }

    template <typename Data>
    List<Data>& List<Data>::operator=(const List<Data>& new_list) {
        if (this != &new_list) // no self-assignment
        {
            Clear(); // Clear list

            Node* new_temp = new_list.head;
            while (new_temp != nullptr) {
                InsertAtBack(new_temp->element); // rebuild the list and copy elements
                new_temp = new_temp->next;
            }
        }
        return *this;
    }

    
    template <typename Data>
    List<Data>& List<Data>::operator = (List<Data> && list) noexcept {
        std::swap(size, list.size);
        std::swap(head, list.head);
        std::swap(tail, list.tail);

        return *this;
    }

    template <typename Data>
    bool List<Data>::operator==(const List<Data>& list) const noexcept {
        if (size != list.size)
            return false;

        Node* curr = head;
        Node* temp = list.head;

        while (curr != nullptr && temp != nullptr){
            if (curr->element != temp->element)
                return false;

            curr = curr->next;
            temp = temp->next;
        }

        return true;
    }

    template <typename Data>
    bool List<Data>::operator != (const List<Data>& list)const noexcept {
        return !(*this==list);
    }


    template <typename Data>
    void List<Data>::InsertAtFront(const Data& data){
        Node* temp = new Node(data);
        
        if(tail == nullptr)
            tail = temp;

        temp->next = head;
        head = temp;
        size++;
    }
    
    template <typename Data>
    void List<Data>::InsertAtFront(Data&& data) noexcept{
        Node* temp = new Node(std::move(data));

        if(tail == nullptr)
        tail=temp;

        temp->next = head;
        head = temp;
        size++;
    }

    template <typename Data>
    void List<Data>::RemoveFromFront(){
        if(head == nullptr)
            throw std::length_error("Access to empty list");

        Node* temp = head;

        if(tail == head)
            head=tail=nullptr;
        else    
            head=head->next;
            
        size--;
        temp->next=nullptr;

        delete temp;
    }

    template <typename Data>
    Data List<Data>::FrontNRemove(){
        if(head == nullptr)
            throw std::length_error("Access to empty list");

        Node* temp = head;
        Data val(std::move(temp->element));
        
        if(tail == head)
            head=tail=nullptr;
        else    
            head=head->next;

        size--;
        temp->next=nullptr;

        delete temp;
        return val;
    }


    template <typename Data>
    void List<Data>::InsertAtBack(const Data& data){
        Node* temp = new Node(data);

        if(tail == nullptr)
            head=temp;
        else
            tail->next = temp;
        
        tail = temp;
        size++;
    }

    template <typename Data>
    void List<Data>::InsertAtBack(Data&& data) noexcept{
        Node* temp = new Node(std::move(data));

        if(tail==nullptr)
            head=temp;
        else
            tail->next=temp;
        
        tail=temp;
        size++;
    }

    template <typename Data>
    void List<Data>::RemoveFromBack(){
        if(head == nullptr)
            throw std::length_error("Access to empty list");

        if (head == tail)
            head = tail = nullptr;
        else{
            Node* temp = head;

            while(temp->next != tail){
                temp = temp->next;
            }    

            temp->next = nullptr;
            tail = temp;
        }    
        size--;
    }

    template <typename Data>
    Data List<Data>::BackNRemove(){
        if (head == nullptr){
            throw std::length_error("Access to empty list");
        }

        Data val(std::move(tail->element));

        if (head == tail){
            delete head;
            head = tail = nullptr;
        }
        else{
            Node* prev = nullptr;
            Node* curr = head;

            while (curr->next != nullptr){
                prev = curr;
                curr = curr->next;
            }

            delete curr;
            tail = prev;
            tail->next = nullptr;
        }

        --size;
        return val;
    }

    template <typename Data>
    Data& List<Data>::operator[](const ulong index){
        if (index >= size){
            throw std::out_of_range("Access at index " + std::to_string(index));
        }

        Node* curr = head;
        for (ulong i = 0; i < index; ++i){
            curr = curr->next;
        }

        return curr->element;
    }

    template <typename Data>
    Data& List<Data>::Front() {
        if(head != nullptr)
            return head->element;
        else
            throw std::length_error("Access to empty list");
    }

    template <typename Data>
    Data& List<Data>::Back() {
        if(tail != nullptr)
            return tail->element;
        else
            throw std::length_error("Access to empty list");
    }

    template <typename Data>
    const Data& List<Data>::operator[](const ulong index) const{
        return static_cast<const Data&>(const_cast<List<Data>*>(this)->operator[](index));
    }

    template <typename Data>
    const Data& List<Data>::Front() const{
        return static_cast<const Data&>(const_cast<List<Data>*>(this)->Front());
    }

    template <typename Data>
    const Data& List<Data>::Back() const{
        return static_cast<const Data&>(const_cast<List<Data>*>(this)->Back());
    }


    template <typename Data>
    void List<Data>::Traverse(TraverseFun fun) const{
        PreOrderTraverse(fun, head);
    }
    

    template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun) const {
        PreOrderTraverse(fun, head);
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun) const {
        PostOrderTraverse(fun, head);
    }


    template <typename Data>
    void List<Data>::Map(MapFun fun) {
        PreOrderMap(fun, head);
    }


    template <typename Data>
    void List<Data>::PreOrderMap(MapFun fun) {
        PreOrderMap(fun, head);
    }


    template <typename Data>
    void List<Data>::PostOrderMap(MapFun fun) {
        PostOrderMap(fun, head);
    }

    template <typename Data>
    void List<Data>::Clear(){
        delete head;
        head = tail = nullptr;
        size = 0;
    }

 template <typename Data>
    void List<Data>::PreOrderTraverse(TraverseFun fun, const Node* curr) const
    {
        for (; curr != nullptr; curr=curr->next)
        {
            fun(curr->element);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderTraverse(TraverseFun fun, const Node* curr) const
    {
        if (curr!=nullptr)
        {
            PostOrderTraverse(fun, curr->next);
            fun(curr->element);
        }
    }

    template <typename Data>
    void List<Data>::PreOrderMap(MapFun fun, Node* curr)
    {
        for (; curr != nullptr; curr=curr->next)
        {
            fun(curr->element);
        }
    }

    template <typename Data>
    void List<Data>::PostOrderMap(MapFun fun, Node* curr)
    {
        if (curr!=nullptr)
        {
            PostOrderMap(fun, curr->next);
            fun(curr->element);
        }
    }

}

