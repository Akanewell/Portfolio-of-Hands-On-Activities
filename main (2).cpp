#include <iostream>
#include <cstdlib>
#include <ctime>
#include "nodes.h"
#include "searching.h"


int main() {
    // ---------------------------------------------------------------------
    // Table 6-1: Random Dataset Generation
    // ---------------------------------------------------------------------
    std::cout << "=== Table 6-1: Dataset Generation ===\n";
    const int max_size = 50;
    int dataset[max_size];
    srand(time(0));


    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
    }
    
    std::cout << "Generated Dataset:\n";
    for (int i = 0; i < max_size; i++) {
        std::cout << dataset[i] << " ";
    }
    std::cout << "\n\n";


    // ---------------------------------------------------------------------
    // Table 6-2a: Linear Search for Array
    // ---------------------------------------------------------------------
    std::cout << "=== Table 6-2a: Linear Search for Array ===\n";
    int sampleArray[5] = {10, 20, 30, 40, 50};
    linearSearch(sampleArray, 5, 30);
    linearSearch(sampleArray, 5, 99);
    std::cout << "\n";


    // ---------------------------------------------------------------------
    // Table 6-2b: Linear Search for Linked List
    // ---------------------------------------------------------------------
    std::cout << "=== Table 6-2b: Linear Search for Linked List ===\n";
    Node<char> *name1 = new_node('R');
    Node<char> *name2 = new_node('o');
    Node<char> *name3 = new_node('m');
    Node<char> *name4 = new_node('a');
    Node<char> *name5 = new_node('n');


    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = NULL;


    linearLS(name1, 'n');
    linearLS(name1, 'z');
    std::cout << "\n";


    // ---------------------------------------------------------------------
    // Table 6-3a: Binary Search for Array
    // ---------------------------------------------------------------------
    std::cout << "=== Table 6-3a: Binary Search for Array ===\n";
    int sortedArr[10] = {1, 5, 8, 10, 13, 16, 27, 32, 45, 60};
    binarySearch(sortedArr, 10, 27);
    binarySearch(sortedArr, 10, 100);
    std::cout << "\n";


    // ---------------------------------------------------------------------
    // Table 6-3b: Binary Search for Linked List
    // ---------------------------------------------------------------------
    std::cout << "=== Table 6-3b: Binary Search for Linked List ===\n";
    // Constructing an ordered linked list: 10 -> 20 -> 30 -> 40 -> 50
    Node<int> *llHead = new_node(10);
    llHead->next = new_node(20);
    llHead->next->next = new_node(30);
    llHead->next->next->next = new_node(40);
    llHead->next->next->next->next = new_node(50);


    Node<int>* res = binarySearchLL(llHead, 30);
    if (res != NULL) {
        std::cout << "Element " << res->data << " found in Linked List!\n";
    } else {
        std::cout << "Element not found in Linked List!\n";
    }
    std::cout << "\n";


    // ---------------------------------------------------------------------
    // Supplementary Activities
    // ---------------------------------------------------------------------
    std::cout << "==========================================\n";
    std::cout << "=== SUPPLEMENTARY ACTIVITIES ===\n";
    std::cout << "==========================================\n";


    // Problem 1
    int prob1List[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int key1 = 18;


    // Array approach comparison count
    int arrayComp = linearSearchArrayCountComparisons(prob1List, 10, key1);


    // Linked list approach comparison count
    Node<int>* prob1LLHead = new_node(prob1List[0]);
    Node<int>* tempNode = prob1LLHead;
    for (int i = 1; i < 10; i++) {
        tempNode->next = new_node(prob1List[i]);
        tempNode = tempNode->next;
    }
    int llComp = linearSearchLLCountComparisons(prob1LLHead, key1);


    std::cout << "[Problem 1] Searching for key " << key1 << ":\n";
    std::cout << "  - Array Approach Comparisons: " << arrayComp << "\n";
    std::cout << "  - Linked List Approach Comparisons: " << llComp << "\n\n";


    // Problem 2
    int occurrences = countOccurrences(prob1List, 10, key1);
    std::cout << "[Problem 2] Count of key '" << key1 << "' in list: " << occurrences << "\n\n";


    // Problem 3 & 4
    int prob3List[10] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int searchKey = 8;
    int foundIdx = recursiveBinarySearch(prob3List, 0, 9, searchKey);


    std::cout << "[Problem 3 & 4] Searching for key " << searchKey << " using Recursive Binary Search:\n";
    if (foundIdx != -1) {
        std::cout << "  - Found key " << searchKey << " at index: " << foundIdx << "\n";
    } else {
        std::cout << "  - Key " << searchKey << " not found.\n";
    }


    return 0;
}