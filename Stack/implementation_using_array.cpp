
#include <bits/stdc++.h>
using namespace std;

// define default capacity of stack
#define SIZE 1000

// Class for stack
template <class X>
class Stack
{
    X *arr;
    int top;
    int capacity;

public:
    Stack()
    {
        arr = new X[SIZE];
        capacity = SIZE;
        top = -1;
    } // constructor

    bool isEmpty()
    {
        return top == -1;   // or return size() == 0;
    }
    void push(X x)
    {
        if (isFull())
        {
            cout << "OverFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Inserting " << x << endl;
        arr[++top] = x;
    }

    X pop()
    {
        if (isEmpty())
        {
            cout << "UnderFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Removing " << peek() << endl;

        // decrease stack size by 1 and (ostionally) return the popped element
        return arr[top--];
    }
    X peek()
    {
        if (!isEmpty())
            return arr[top];
        else
            exit(EXIT_FAILURE);
    }

    int size()
    {
        return top + 1;
    }
    bool isFull()
    {
        return top == capacity - 1; // or return size() == capacity;    
    }

    // destructor
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack<string> st;

    st.push("A");
    st.push("B");

    st.pop();
    st.pop();

    st.push("C");

    // Prints the top of the stack
    cout << "Top element is: " << st.peek() << endl;

    // Returns the number of elements present in the stack
    cout << "Stack size is " << st.size() << endl;

    st.pop();

    // check if stack is emsty or not
    if (st.isEmpty())
        cout << "Stack is Empty\n";
    else
        cout << "Stack isn't empty\n";

    return 0;
}