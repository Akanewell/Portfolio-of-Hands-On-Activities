#include <iostream>
#include <string>

// Task 1: Create a class called Job
class Job {
public:
    int id;
    std::string userName;
    int pages;

    // Default the constructor
    Job() : id(0), userName(""), pages(0) {}

    // Parameterized the constructor
    Job(int jobID, std::string user, int numPages) 
        : id(jobID), userName(user), pages(numPages) {}

    void display() const {
        std::cout << "[Job ID: " << id << " | User: " << userName << " | Pages: " << pages << "]";
    }
};

class Queue {
private:
    Job* arr;
    int capacity;
    int frontIndex;
    int backIndex;
    int count;

public:
    // The constructor
    Queue(int cap = 10) : capacity(cap), frontIndex(0), backIndex(-1), count(0) {
        arr = new Job[capacity];
    }

    // Copy the Constructor
    Queue(const Queue& other) {
        capacity = other.capacity;
        frontIndex = other.frontIndex;
        backIndex = other.backIndex;
        count = other.count;
        arr = new Job[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Copy the Assignment Operator
    Queue& operator=(const Queue& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            frontIndex = other.frontIndex;
            backIndex = other.backIndex;
            count = other.count;
            arr = new Job[capacity];
            for (int i = 0; i < capacity; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }
    int size() const { return count; }

    void Enqueue(const Job& job) {
        if (isFull()) {
            std::cout << "Error: Queue is full! Cannot add Job ID " << job.id <<std::endl;
            return;
        }
        backIndex = (backIndex + 1) % capacity;
        arr[backIndex] = job;
        count++;
    }

    void Dequeue() {
        if (isEmpty()) {
            std::cout << "Error: Queue is empty!\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    Job Front() const {
        if (!isEmpty()) return arr[frontIndex];
        return Job();
    }

    Job Back() const {
        if (!isEmpty()) return arr[backIndex];
        return Job();
    }
};

// Task 2 and 3 The create a class called Printer using the queue
class Printer {
private:
    Queue jobQueue;

public:
    Printer(int capacity = 10) : jobQueue(capacity) {}

    void addJob(const Job& job) {
        std::cout << "Adding to printer: ";
        job.display();
        std::cout << "\n";
        jobQueue.Enqueue(job);
    }

    // Task 4:
    void processJobs() {
        std::cout << "\n--- Starting Printer Processing ---\n";
        while (!jobQueue.isEmpty()) {
            Job currentJob = jobQueue.Front();
            std::cout << "Printing -> ";
            currentJob.display();
            std::cout << " ... [Completed]\n";
            jobQueue.Dequeue();
        }
        std::cout << "All jobs processed. Printer queue is clear.\n";
    }
};

int main() {
    Printer officePrinter(5);

    std::cout << "--- SIMULATING MULTIPLE USERS ADDING PRINT JOBS ---\n";
    officePrinter.addJob(Job(101, "alyanah", 5));
    officePrinter.addJob(Job(102, "katie", 12));
    officePrinter.addJob(Job(103, "Prored", 3));
    officePrinter.addJob(Job(104, "Akane", 20));

    officePrinter.processJobs();

    return 0;
}