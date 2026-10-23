#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template <typename T>
class queueArr {
private:
    // pointer to dynamically allocated array
    T* q_array;
    size_t q_capacity;
    size_t q_size;
    int q_front;
    int q_back;

public:
    // constructor
    queueArr(size_t capacity = 10);

    bool Empty();
    size_t Size();
    void Clear();

    T Front();
    T Back();

    void Enqueue(T value);
    void Dequeue();

    // copy constructor:
    queueArr(const queueArr& other);

    // copy assignment operator
    queueArr& operator=(const queueArr& other);

    // destructor
    ~queueArr();
};

// constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;
    q_array = new T[q_capacity];
}

template <typename T>
bool queueArr<T>::Empty() {
    return q_size == 0;
}

template <typename T>
size_t queueArr<T>::Size() {
    return q_size;
}

template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

template <typename T>
T queueArr<T>::Front() {
    // what will happen if the queue is already empty?
    if (Empty()) {
        std::cout << "The Queue is Empty.\n";
        return T();
    }

    return q_array[q_front];
}

// back
template <typename T>
T queueArr<T>::Back() {
    if (Empty()) {
        std::cout << "The Queue is Empty.\n";
        return T();
    }

    return q_array[q_back];
}

template <typename T>
void queueArr<T>::Enqueue(T value) {
    // check if the queue is full
    if (q_size == q_capacity) {
        std::cout << "Queue is full\n";
        return;
    }

    // compute for the q_back for circular (use the modulo operator)
    q_back = (q_back + 1) % q_capacity;
    // assign the q_array with the updated q_back to the value
    q_array[q_back] = value;
    // increment the q_size
    q_size++;
    return;
}

template <typename T>
void queueArr<T>::Dequeue() {
    // check if it is empty
    if (Empty()) {
        std::cout << "the queue is empty\n ";
        return;
    }

    // move q_front circularly
    q_front = (q_front + 1) % q_capacity;

    // decrement the q_size
    q_size--;

    // reset index when queue becomes empty
    if (Empty()) {
        Clear();
        return;
    }
}

template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array;
}

#endif // QUEUEARR_H