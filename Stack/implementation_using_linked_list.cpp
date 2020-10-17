#include <bits/stdc++.h>
using namespace std;

// The structure describing the node
template <class T>
class NodeStack
{
public:
  T item;
  NodeStack<T>* link;
};

// Template class Stack based on a singly linked list
template <class T>
class StackList
{

  NodeStack<T>* start; // pointer to the top of the stack
  int size;
  public:
    // default constructor
    StackList() 
    { 
      start = NULL; 
      size = 0;
    }

    // copy constructor
    
    // push an item onto the stack
    // the item is placed at the top of the list
    void push(T item)
    {
      NodeStack<T>* p;

      // 1. Form an item.
      try 
      {
        p = new NodeStack<T>; // attempt to allocate memory
      }
      catch(bad_alloc e)
      {
        // if memory is not allocated, then exit
        cout << e.what() << endl;
        return;
      }
      p->item = item;
      p->link = start; // p points to the 1st item

      // 2. Redirect pTop to p
      start = p;
      size++;
    }

    // Number items in the stack
    int length()
    {
      return size;
    }

    T top()
    {
      if(size == 0)
      {
        cout << "Stack is empty\n";
        exit(EXIT_FAILURE);
      }
      else
      {
        return start->item;
      }
    }

    // clears the stack - removes all elements from the stack
    bool isEmpty()
    {
      return size==0;
    }
    // method puller from the stack
    T pop()
    {
      // check if the stack is empty?
      if (start == NULL)
        return 0;

      NodeStack<T>* p2; // additional pointer
      T item;
      item = start->item;

      // redirect pointers pTop, p2
      p2 = start;
      start = start->link;

      // Free the memory allocated for the 1st item
      delete p2;

      return item;
    }
};

int main()
{
  StackList<int> st;
  st.push(1);
  st.push(2);
  st.pop();
  cout << st.top() << endl << st.length();
  return 0;

}