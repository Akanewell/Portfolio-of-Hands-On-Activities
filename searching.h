#ifndef SEARCHING_H
#define SEARCHING_H


#include <iostream>
#include "nodes.h"


// ==========================================
// PART B: LINEAR / SEQUENTIAL SEARCH
// ==========================================


// Linear Search for Arrays
template <typename T>
void linearSearch(T arr[], int n, T item) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            std::cout << "Searching is successful at index " << i << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Searching is Unsuccessful\n";
    }
}


// Linear Search for Array with Comparison Count (Supplementary Problem 1)
template <typename T>
int linearSearchArrayCountComparisons(T arr[], int n, T item) {
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == item) {
            break;
        }
    }
    return comparisons;
}


// Linear Search for Linked List (ILO A.1)
template <typename T>
void linearLS(Node<T>* head, T dataFind) {
    Node<T>* current = head;
    bool found = false;
    int index = 0;
    while (current != NULL) {
        if (current->data == dataFind) {
            std::cout << "Searching is successful. Found '" << dataFind << "' at node position " << index << "\n";
            found = true;
            break;
        }
        current = current->next;
        index++;
    }
    if (!found) {
        std::cout << "Searching is Unsuccessful\n";
    }
}


// Linear Search for Linked List with Comparison Count (Supplementary Problem 1)
template <typename T>
int linearSearchLLCountComparisons(Node<T>* head, T item) {
    int comparisons = 0;
    Node<T>* current = head;
    while (current != NULL) {
        comparisons++;
        if (current->data == item) {
            break;
        }
        current = current->next;
    }
    return comparisons;
}


// Linear Search returning count of repeating instances (Supplementary Problem 2)
template <typename T>
int countOccurrences(T arr[], int n, T k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            count++;
        }
    }
    return count;
}




// ==========================================
// PART C: BINARY SEARCH
// ==========================================


// Binary Search for Arrays
template <typename T>
void binarySearch(T arr[], int n, T no) {
    int low = 0;
    int up = n - 1;
    bool found = false;


    while (low <= up) {
        int mid = (low + up) / 2;
        if (no == arr[mid]) {
            std::cout << "Search element is found at index " << mid << "!\n";
            found = true;
            break;
        } else if (no < arr[mid]) {
            up = mid - 1;
        } else {
            low = mid + 1;
        }
    }


    if (!found) {
        std::cout << "Search element is not found\n";
    }
}


// Helper function to find middle node of a Linked List (Two-pointer approach)
template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last) {
    if (start == NULL) return NULL;


    Node<T>* slow = start;
    Node<T>* fast = start->next;


    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}


// Binary Search for Linked List
template <typename T>
Node<T>* binarySearchLL(Node<T>* head, T key) {
    Node<T>* start = head;
    Node<T>* last = NULL;


    while (start != last) {
        Node<T>* mid = getMiddle(start, last);


        if (mid == NULL) return NULL;


        if (mid->data == key) {
            return mid;
        } else if (mid->data < key) { // Key is in the right half
            start = mid->next;
        } else { // Key is in the left half
            last = mid;
        }
    }
    return NULL;
}


// Recursive Binary Search for Arrays (Supplementary Problem 4)
template <typename T>
int recursiveBinarySearch(T arr[], int low, int high, T key) {
    if (low > high) {
        return -1; // Not found
    }


    int mid = low + (high - low) / 2;


    if (arr[mid] == key) {
        return mid;
    } else if (arr[mid] > key) {
        return recursiveBinarySearch(arr, low, mid - 1, key);
    } else {
        return recursiveBinarySearch(arr, mid + 1, high, key);
    }
}


#endif