template <typename T>
LinkedListStack<T>::LinkedListStack()
{ 
    this->top = nullptr;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    Node<T>* current = this->top;
    while(current != nullptr)
    {
        Node<T>* tempNext = current->next;
        delete current;
        current = tempNext;
    }

    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    this->clear();
    this->length = copyObj.length;

    if (copyObj.top == nullptr) {
        this->top = nullptr;
        return;
    }

    //Copy first element
    this->top = new Node<T>(copyObj.top->data);

    Node<T>* currentOfCopy = copyObj.top->next;
    Node<T>* currentOfThis = this->top;

    while(currentOfCopy != nullptr)
    {
        currentOfThis->next = new Node<T>(currentOfCopy->data);
        
        currentOfCopy = currentOfCopy->next;
        currentOfThis = currentOfThis->next;
    }

    currentOfThis->next = nullptr;
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if(this->top != nullptr)
    {
        return this->top->data;
    }
    return T{};
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if(this->top == nullptr)
    {
        return;
    }
    Node<T>* topNext = top->next;
    delete this->top;

    this->top = topNext;

    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* newNode = new Node<T>(elem);

    newNode->next = this->top;
    this->top = newNode;

    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
