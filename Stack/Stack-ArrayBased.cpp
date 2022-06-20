#include <iostream>
using namespace std;

class ArrayBasedStack
{
private:
    int top; //index
    int capacity;
    int* stack;
    void doubleCapacity();
public:
    ArrayBasedStack():top(-1), capacity(1) //capacity initial with one for testing
    {
        stack = new int[capacity];
    }
    void Push(int);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

void ArrayBasedStack::doubleCapacity()
{
    capacity *= 2;
    int* newStack = new int[capacity];
    for(int i = 0; i < capacity / 2; i ++)
    {
        newStack[i] = this->stack[i];
    }    
    delete[] stack;
    stack = newStack;    
}

void ArrayBasedStack::Push(int input)
{    
    top ++;
    if(top > capacity - 1)
    {
        doubleCapacity();
    }
    stack[top] = input;
}

void ArrayBasedStack::Pop()
{
    if(IsEmpty())
    {
        cout << "stack is empty" << endl;
        return;
    }

    //revise the index of the top
    stack[top] = 0; 
    top --;
}

bool ArrayBasedStack::IsEmpty()
{    
    return top < 0 ? true : false;
}

int ArrayBasedStack::Top()
{
    if(IsEmpty())
    {
        cout << "stack is empty" << endl;
        return -1;
    }

    return stack[top];
}

int ArrayBasedStack::getSize()
{
    return top + 1;
}

int main()
{
    ArrayBasedStack stack;
    
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
