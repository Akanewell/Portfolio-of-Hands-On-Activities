#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>


// 1. Bubble Sort Implementation 
template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    for (size_t i = 0; i < arrSize; i++) {
        for (size_t j = i + 1; j < arrSize; j++) {
            if (arr[j] < arr[i]) { // Adjusted for ascending order
                std::swap(arr[j], arr[i]);
            }
        }
    }
}


// 2. Merge Sort Implementation 
template <typename T>
void merge(T arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;


    std::vector<T> L(n1), R(n2);


    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[middle + 1 + j];


    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }


    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}


template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}


int main() {
    std::vector<int> sizes = {100, 1000, 10000};


    for (int n : sizes) {
        std::vector<int> bestData(n), worstData(n);
        
        // Best Case: Already Sorted
        for (int i = 0; i < n; i++) bestData[i] = i;
        
        // Worst Case: Reverse Sorted
        for (int i = 0; i < n; i++) worstData[i] = n - i;


        // Test Bubble Sort
        std::vector<int> temp = worstData;
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(temp.data(), temp.size());
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> bubbleWorstTime = end - start;


        // Test Merge Sort
        temp = worstData;
        start = std::chrono::high_resolution_clock::now();
        mergeSort(temp.data(), 0, temp.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> mergeWorstTime = end - start;


        std::cout << "N = " << n << " | Bubble Sort Worst: " << bubbleWorstTime.count() 
                  << " ms | Merge Sort Worst: " << mergeWorstTime.count() << " ms\n";
    }


    return 0;
}