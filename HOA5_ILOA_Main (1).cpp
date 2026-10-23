#include <iostream>
#include <queue>

void display(std::queue<int> q)
{
    std::queue<int> c = q;

    while (!c.empty())
    {
        std::cout << " " << c.front();
        c.pop();
    }

    std::cout << "\n";
}

int main()
{
    std::queue<int> a;

    // Insert elements into the queue
    a.push(10);
    a.push(20);
    a.push(30);

    std::cout << "The queue a is :";
    display(a);

    std::cout << "a.empty() : " << a.empty() << "\n";
    std::cout << "a.size()  : " << a.size() << "\n";
    std::cout << "a.front() : " << a.front() << "\n";
    std::cout << "a.back()  : " << a.back() << "\n";

    std::cout << "After a.pop() : ";
    a.pop();
    display(a);

    a.push(40);

    std::cout << "The queue a is : ";
    display(a);

    return 0;
}