#include <iostream>
#include "StackFactory.hpp"

int main()
{
    Stack<int> * myStack = StackFactory<int>::GetStack();
    Stack<int> * myStack2 = StackFactory<int>::GetStack();

    for(int i = 0; i < 10; i++)
    {
        myStack->push(i);
    }
    myStack->print();

    for(int i = 0; i < 2; i++)
    {
        myStack->pop();
    }
    myStack->print();

    myStack2 = myStack;
    cout << "Copying myStack1 to myStack2" << endl;
    myStack->print();
    myStack2->print();

    cout << "clearing both stacks"<< endl;
    myStack->clear();
    myStack->print();
    myStack2->print();
}