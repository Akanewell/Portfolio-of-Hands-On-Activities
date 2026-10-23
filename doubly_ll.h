#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

//Doublelist Node
template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* next;
        DoubleList<T>* prev;
};

//Creating a node function
template<typename T>
DoubleList<T>  *createNode(T newData){
    //Dynamic memory alloction for a new node
    DoubleList<T>* newNode = new DoubleList<T>;

    newNode->data = newData;
    //Point it to the next node
    newNode->prev = nullptr;
    newNode->next = nullptr;

    return newNode;
}

template<typename T>
void dllTraverse(DoubleList<T>* currentNode){
    //Check if the list is empty
    if(currentNode == nullptr){
        std::cout << "The list is empty";
        return;
    }

    DoubleList<T>* tail;
    std::cout << "FORWARD" << std::endl;
    //Forward traverse
    while(currentNode != nullptr){
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode  = currentNode->next;
    }
    std::cout << std::endl;
    //Reverse traverse
    std::cout << "REVERSE" << std::endl;
    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
    std::cout << std::endl;

}

//inserting a node to the head
template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentNode){

    // create a new node:
    DoubleList<T> *newNode = createNode(newData);
    //point the newNode to the currentNode (head)
    newNode->next = *currentNode;
    //point the currentNode(head) to the newNode
    (*currentNode)->prev = newNode;
    
}

//inserting at the End;
template <typename T>
void dllInsertEnd(T newData, DoubleList<T> *currentHead){
    //create a new node
    DoubleList<T>* newNode = createNode(newData);

    //traverse until we reach the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    //connect the new node back to the last node
    newNode->prev = currentHead;
    //connect the curent node to the new node
    currentHead->next = newNode;
}
template<typename T>
void dllGeneralInsert(T newData, DoubleList<T>* preNode){
    if(preNode == nullptr){
        std::cout << "Previous value cannot be null" << std::endl;
    }
    DoubleList<T>* newNode = createNode(newData);

    newNode->next = preNode->next;
    newNode->prev = preNode;
    preNode->next = newNode;
    (preNode->next->next)->prev = newNode;
}

//deleting a node
template<typename T>
void dllDeleteNode(T findData, DoubleList<T>** head){
    if(*head == nullptr)return;

    DoubleList<T>* currNode = *head;
    DoubleList<T>* preNode = nullptr;

    while(currNode != nullptr && currNode->data !=findData){
        preNode = currNode;
        currNode = currNode->next;
    }
    if(currNode == nullptr){
        std::cout << "Data is not found." << std::endl;
        return;
    }
    if(preNode == nullptr){
        *head = currNode->next;
        (*head)->prev = nullptr;
    }else{
        preNode->next = currNode->next;
        (currNode->next)->prev = preNode;
    }
    delete currNode;
}

#endif


