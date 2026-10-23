#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <utility>
#include <ctime>


template <typename T>
void bubbleSort(T arr[], std::size_t arrSize) {
    for (std::size_t i = 0; i < arrSize; i++) {
        for (std::size_t j = i + 1; j < arrSize; j++) {
            if (arr[j] > arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}


template <typename T>
int Routine_Smallest(T A[], int K, const int arrSize) {
    T smallestElem = A[K];
    int position = K;
    for (int J = K + 1; J < arrSize; J++) {
        if (A[J] < smallestElem) {
            smallestElem = A[J];
            position = J;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], const int N) {
    int POS, temp, pass = 0;
    for (int i = 0; i < N; i++) {
        POS = Routine_Smallest(arr, i, N);
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
        pass++;
    }
}


template <typename T>
void insertionSort(T arr[], const int N) {
    int K = 1, J, temp;
    while (K < N) {
        temp = arr[K];
        J = K - 1;
        while (J >= 0 && temp <= arr[J]) {
            arr[J + 1] = arr[J];
            J--;
        }
        arr[J + 1] = temp;
        K++;
    }
}

template <typename T>
void merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }

    delete[] L;
    delete[] R;
}

template <typename T>
void mergeSort(T arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

#endif 