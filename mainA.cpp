#include <iostream>
#include <thread>

// Global variable of type integer
int global_var = 0;

// Add function that takes an integer parameter and adds it to global_var
void add(int val) {
    global_var += val;
}

int main() {
    // Create 3 threads passing the add function and values
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    // Display state before joining T1
    std::cout << "Value before T1.join(): " << global_var << std::endl;
    T1.join();

    // Display state after T1.join() and before T2.join()
    std::cout << "Value after T1.join(): " << global_var << std::endl;
    T2.join();

    // Display state after T2.join() and before T3.join()
    std::cout << "Value after T2.join(): " << global_var << std::endl;
    T3.join();

    // Final display state after T3.join()
    std::cout << "Final value after T3.join(): " << global_var << std::endl;

    return 0;
}