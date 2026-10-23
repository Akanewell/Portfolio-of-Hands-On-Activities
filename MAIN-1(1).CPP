#include<iostream>

//global variables:
#define maxSize 10
int stackArr[maxSize];
int top = -1, newData;

//fuction prototypes:
// top, push, pop, isEmpty, isFull

//observes
bool isEmpty();
bool isFull();
void Top(); //the T is capital
void displayALl(); // goal is to display the stack following the LIFO principle


//transformer operators
void push();
void pop();

int main(){
        int choice;
    while(true){
        std::cout<<"========================\n";
        std::cout<<" Stack operations: " <<std::endl;
        std::cout<<" [1] push [2] pop [3] isEmpty [4] isFull [5] Top "<<std::endl;
        std::cin >> choice;
        std::cout<<"========================\n";
        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: std::cout<<"is the stack empty? "<< isEmpty()<<std::endl;
            break;
            case 4: std::cout<<"is the stack full? "<< isFull()<<std::endl;
            break;
            case 5: Top();
            break;
            default: std::cout<<"Invalid Choice! " <<std::endl;
            break;



    }
}


    return 0;
}


//function definition
bool isEmpty(){
    return (top == -1);
}

bool isFull(){
    return (top == maxSize-1);
}

void Top(){
    //error catching:
    if(isEmpty()) return;

    //prints the top element
    std::cout<<"The top element is: "<< stackArr[top]<<std::endl;
}

void push(){
    //error catching:
    if (isFull()) return;

    //ask the user what they want to insert:
    std::cout<<"What character do you want to push? ";
    std::cin >> newData;

    //storing to the stack:
    stackArr[++top] = newData;

}

void pop(){
    //error catching:
    if(isEmpty()) return;

    //display the item to be poppred:
    std::cout<<"Popping: "<< stackArr[top] <<std::endl;

    //we remove the element form the stack
    top--;
}

