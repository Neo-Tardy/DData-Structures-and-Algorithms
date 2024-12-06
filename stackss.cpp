#include <iostream>
#include <stack>
#include <string>

using namespace std;
   
    private:

        int top;

        int maxSize;

        int* stackArray;



public:

    Stack (int size) {

        maxSize = size;

        stackArray = new int[maxSize];

        top = -1;

    }



    ~Stack() {

        delete[] stackArray;

    }



    bool isEmpty() {

        return (top == -1);

    }



    bool isFull() {

        return (top == maxSize-1);

    }



    void push (int value) {

        stackArray[++top] = value;

    }



    void pop() {

        if (isEmpty()) {

            std::cout << "" << endl;

            return;

        }

        --top;

    }



    int peek() {

        return stackArray[top];

    }

};



int main() {

    Stack myStack(5);



    std::cout << "Is empty?: " << myStack.isEmpty() << endl;

    myStack.push(10);

    std::cout << "Pushed " << myStack.peek() << " onto the stack" << endl;;

    myStack.push(20);

    std::cout << "Pushed " << myStack.peek() << " onto the stack" << endl;

    myStack.push(30);

    std::cout << "Pushed " << myStack.peek() << " onto the stack" << endl;



    std::cout << "Is full?: " << myStack.isFull() << endl;

    myStack.push(40);

    std::cout << "Pushed " << myStack.peek() << " onto the stack" << endl;

    myStack.push(50);

    std::cout << "Pushed " << myStack.peek() << " onto the stack" << endl;



    std::cout << "Is full?: " << myStack.isFull() << endl;

    myStack.pop();

    std::cout << "Popped " << myStack.peek() << " onto the stack" << endl;

    myStack.pop();

    std::cout << "Popped " << myStack.peek() << " onto the stack" << endl;



    std::cout << "Top element after popping: " << myStack.peek() << endl;

    myStack.push(60);

    std::cout << "Pushed " << myStack.peek() << " onto the stack" << endl;



    return 0;

}