#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void parallel_quick_sort(std::vector<int>& arr, int low, int high, int depth = 0) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Limit recursive thread creation to depth < 2 to manage overhead
        if (depth < 2) {
            std::thread left_thread(parallel_quick_sort, std::ref(arr), low, pi - 1, depth + 1);
            std::thread right_thread(parallel_quick_sort, std::ref(arr), pi + 1, high, depth + 1);
            left_thread.join();
            right_thread.join();
        } else {
            parallel_quick_sort(arr, low, pi - 1, depth + 1);
            parallel_quick_sort(arr, pi + 1, high, depth + 1);
        }
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};

    std::cout << "Unsorted Array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    parallel_quick_sort(arr, 0, arr.size() - 1);

    std::cout << "Sorted Array:   ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}