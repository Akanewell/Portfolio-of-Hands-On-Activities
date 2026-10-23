#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

const unordered_map<char, char> BRACKETS = {
    {')', '('},
    {'}', '{'},
    {']', '['}
};

bool isBracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[' ||
           ch == ')' || ch == '}' || ch == ']';
}

bool isOpen(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

template <typename T, int SIZE = 100>
class ArrayStack {
private:
    T arr[SIZE];
    int top = -1;

public:
    bool push(T value) {
        if (top == SIZE - 1) return false;
        arr[++top] = value;
        return true;
    }

    bool pop() {
        if (empty()) return false;
        top--;
        return true;
    }

    T peek() const {
        return arr[top];
    }

    bool empty() const {
        return top < 0;
    }
};

template <typename T>
class LinkedListStack {
private:
    struct Node {
        T value;
        unique_ptr<Node> next;
        Node(T v, unique_ptr<Node> n)
            : value(v), next(move(n)) {}
    };

    unique_ptr<Node> head;

public:
    void push(T value) {
        head = make_unique<Node>(value, move(head));
    }

    bool pop() {
        if (empty()) return false;
        head = move(head->next);
        return true;
    }

    T peek() const {
        return head->value;
    }

    bool empty() const {
        return head == nullptr;
    }
};

template <typename Stack>
bool checkBalanced(const string& expr) {
    Stack stack;

    for (char ch : expr) {
        if (!isBracket(ch)) continue;

        if (isOpen(ch)) {
            stack.push(ch);
        } else {
            if (stack.empty()) return false;
            if (stack.peek() != BRACKETS.at(ch)) return false;
            stack.pop();
        }
    }

    return stack.empty();
}

template <typename Stack>
void runTests(const string tests[], int count, const string& title) {
    cout << title << endl;
    for (int i = 0; i < count; i++) {
        cout << tests[i] << " -> "
             << (checkBalanced<Stack>(tests[i]) ? "VALID (Y)" : "INVALID (N)")
             << endl;
    }
}

int main() {
    string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B]+[C-D]}"
    };

    int total = sizeof(expressions) / sizeof(expressions[0]);

    runTests<ArrayStack<char>>(expressions, total, "--- Testing Array Stack ---");
    cout << endl;
    runTests<LinkedListStack<char>>(expressions, total, "--- Testing Linked List Stack ---");

    return 0;
}