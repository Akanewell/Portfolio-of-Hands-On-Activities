#include <iostream>
#include "queueLL.h"
#include "queueArr.h"

int main() {

    qNode<int>* front = nullptr;
    qNode<int>* back = nullptr;

    enqueue(1, &front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << "\n";
    enqueue(2, &front, &back);
    enqueue(3, &front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << "\n";

    display(front);
    dequeue(&front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << "\n";
    dequeue(&front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << "\n";
    dequeue(&front, &back);
    dequeue(&front, &back);
    display(front);

    display(front);
    

    //object cration
    queueArr<int> q(6);

    q.Enqueue(1);
    std::cout<<"Front: " <<q.Front() << " Back: "<< q.Back() << " Size: " << q.Size()<<std::endl;
    q.Enqueue(2);
    std::cout<<"Front: " <<q.Front() << " Back: "<< q.Back() << " Size: " << q.Size() << std::endl;
    q.Enqueue(3);
    std::cout<<"Front: " <<q.Front() << " Back: "<< q.Back() << " Size: " << q.Size() <<std::endl;
    q.Enqueue(4);
    std::cout<<"Front: " <<q.Front() << " Back: "<< q.Back() << " Size: " << q.Size() <<std::endl;
    q.Enqueue(5);
    std::cout<<"Front: " <<q.Front() << " Back: "<< q.Back() << " Size: " << q.Size() <<std::endl;
    q.Enqueue(6);
    std::cout<<"Front: " <<q.Front() << " Back: "<< q.Back() << " Size: " << q.Size() <<std::endl;
    q.Enqueue(7);
    std::cout<<"Front: " <<q.Front() << " Back: "<< q.Back() << " Size: " << q.Size() <<std::endl;
    q.Dequeue();
    std::cout<<"Front: " <<q.Front() << " Back: "<< q.Back() << " Size: " << q.Size() <<std::endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    return 0;
}