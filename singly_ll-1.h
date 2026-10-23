#ifndef SINGLY_LL_H
#define SINGLY_LL_H

template <typename T>
class SinglyList{
    public:
    T data;
    SinglyList<T>* next;
};

template <typename T>
void ListTraversal(SinglyList<T>* node){

    if(node == nullptr){
        std::cout << "the list is empty" << std::endl;
        return;
    }

    //WHILE n IS NOT EQUAL TO null:
    while(node != nullptr){
        //PRINT data to n
        std::cout << node->data;

        if(node->next != nullptr){
            std::cout << "->";
        }

        //GO TO THE NEXT NODE:
        node = node->next;

    }
    //PRINT THE NEXT LINE
    std::cout << std::endl;
}

template <typename T>
void sllInsertHead(T newData, SinglyList<T>** currentHead){

    // 1. Allocate memeory for then new node
    SinglyList<T>* newNode = new SinglyList<T>;

    // 2. Put out data into the new node
    newNode->data = newData;

    // 3. Set Next of the new node to point ot the previous head
    newNode->next = *currentHead;

    // 4. Reset Head to point to the new nod
    *currentHead = newNode;

}

template <typename T>
void sllGeneralInsert(T newData, SinglyList<T>* prevNode){

    // 1. Check if it is the head node
    if(prevNode == nullptr){
        // 2. If null, print "Previous node cannot be null."
        std::cout << "Previous node cannot be null." << std::endl;
    }
    // 3. Allocate a new node
    SinglyList<T>* newNode = new SinglyList<T>;
    // 4. Store data in the new node
    newNode->data = newData;
    // 5. Point new node to the node previous node was pointing to
    newNode->next = prevNode->next;
    // 6. Point previous node to the new node
    prevNode->next = newNode;
}

template <typename T>
void sllInsertEnd(T newData, SinglyList<T>** head){
    // 1. Allocate new node
    SinglyList<T>* newNode = new SinglyList<T>;
    //dereference to the new node
    SinglyList<T>* currentNode = *head;
    //store data in new node:
    newNode->data = newData;
    //point the new node to null
    newNode->next = nullptr;

    //Traverse the list of the current node to the new node
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    //Point the next of the current node to the new node
    currentNode->next = newNode;

}

template <typename T>
void sllDeleteNode(T findData, SinglyList<T>** head){
    //check first if the list is already empty??
    if(*head == nullptr) return;

    SinglyList<T>* currNode= *head;
    SinglyList<T>* prevNode= nullptr;

    //search for the node 1. what if the data we are looking for is not... (idk)
    // 2. the data is found
    while(currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    //data was not found
    if(currNode == nullptr) return;

    if(prevNode == nullptr){
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

template <typename T>
void sllDeleteList(SinglyList<T>** head){

    SinglyList<T>* current = *head;

    while(current != nullptr){
        SinglyList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}

#endif