#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

void RamdomArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";

        if ((i + 1) % 10 == 0)
        {
            std::cout << "\n";
        }
    }
}

int main()
{
    const int SIZE = 100;

    int originalArray[SIZE];
    int shellArray[SIZE];
    int mergeArray[SIZE];
    int quickArray[SIZE];

    std::srand(std::time(0));

    for (int i = 0; i < SIZE; i++)
    {
        originalArray[i] = std::rand() % 1000 + 1;
    }

    for (int i = 0; i < SIZE; i++)
    {
        shellArray[i] = originalArray[i];
        mergeArray[i] = originalArray[i];
        quickArray[i] = originalArray[i];
    }

    std::cout << "Original Array:\n\n";
    RamdomArray(originalArray, SIZE);

    shellSort(shellArray, SIZE);

    std::cout << "\nShell Sort:\n\n";
    RamdomArray(shellArray, SIZE);

    mergeSort(mergeArray, 0, SIZE - 1);

    std::cout << "\nMerge Sort:\n\n";
    RamdomArray(mergeArray, SIZE);

    quickSort(quickArray, 0, SIZE - 1);

    std::cout << "\nQuick Sort:\n\n";
    RamdomArray(quickArray, SIZE);

    return 0;
}