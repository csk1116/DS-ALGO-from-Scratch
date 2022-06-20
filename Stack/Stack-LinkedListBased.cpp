#include <iostream>
using namespace std;

class LinkedListBasedStack;

class StackNode
{
private:
    int data;
    StackNode* next;
public:
    StackNode():data(0), next(nullptr){}
    StackNode(int value):data(value), next(nullptr){}
    StackNode(int value, StackNode* nextNode):data(value), next(nextNode){}
    friend LinkedListBasedStack;
};

class LinkedListBasedStack
{
private:
    StackNode* top;
    int size;
public:
    LinkedListBasedStack():size(0),top(nullptr){}
    void Push(int);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void LinkedListBasedStack::Push(int input)
{    
    if(IsEmpty())
    {
        top = new StackNode(input);
        size ++;
        return;
    }

    StackNode* newTopnode = new StackNode(input);
    newTopnode->next = top;
    top = newTopnode;
    size ++;
}

void LinkedListBasedStack::Pop()
{
    if(IsEmpty())
    {
        cout << "stack is empty" << endl;
        return;
    }

    StackNode* temp = top->next;
    delete top;
    top = temp;
    temp = nullptr;
    size --;
}

bool LinkedListBasedStack::IsEmpty()
{    
    return size == 0 ? true : false;
}

int LinkedListBasedStack::Top()
{
    if(IsEmpty())
    {
        cout << "stack is empty" << endl;
        return -1;
    }

    return top->data;
}

int LinkedListBasedStack::getSize()
{
    return size;
}

int main()
{
    LinkedListBasedStack stack;
    stack.Pop();
    stack.Push(1); //1
    stack.Push(3); //3, 1
    cout << "top: " << stack.Top() << ", size: " << stack.getSize() << endl; //3, 2
    stack.Push(5); //5, 3, 1
    cout << "top: " << stack.Top() << ", size: " << stack.getSize() << endl; //5, 3
    stack.Pop(); //3, 1
    stack.Pop(); //1
    cout << "top: " << stack.Top() << ", size: " << stack.getSize() << endl; //1, 1
    stack.Pop(); //empty
    cout << "top: " << stack.Top() << ", size: " << stack.getSize() << endl; //5, 3

    return 0;
}
