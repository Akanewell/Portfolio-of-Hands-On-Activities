#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SortAlgorithms.h"

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << "\n\n";
}

int main() {
    const int SIZE = 100;
    int originalArray[SIZE];
    int testArray[SIZE];

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Array of Values for Sort Algorithm Testing
    std::cout << "=== Preparation Task (Original Unsorted Array) ===\n";
    for (int i = 0; i < SIZE; i++) {
        originalArray[i] = std::rand() % 1000;
    }
    printArray(originalArray, SIZE);

    // Bubble Sort Technique
    for (int i = 0; i < SIZE; i++) testArray[i] = originalArray[i];
    bubbleSort(testArray, SIZE);
    std::cout << "=== Bubble Sort Result ===\n";
    printArray(testArray, SIZE);

    // Selection Sort Algorithm
    for (int i = 0; i < SIZE; i++) testArray[i] = originalArray[i];
    selectionSort(testArray, SIZE);
    std::cout << "=== Selection Sort Result ===\n";
    printArray(testArray, SIZE);

    // Insertion Sort Algorithm
    for (int i = 0; i < SIZE; i++) testArray[i] = originalArray[i];
    insertionSort(testArray, SIZE);
    std::cout << "=== Insertion Sort Result ===\n";
    printArray(testArray, SIZE);

    // Merge Sort
    for (int i = 0; i < SIZE; i++) testArray[i] = originalArray[i];
    mergeSort(testArray, 0, SIZE - 1);
    std::cout << "=== Merge Sort Result ===\n";
    printArray(testArray, SIZE);

 

    return 0;
}