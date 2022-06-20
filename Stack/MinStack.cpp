/*
Implement MinStack with the help of c++ STL stack. There are two stack in the class: data stack & minstack.
data stack act as a normal stack while minstack is used to track the min value in the stack.
*/
#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    MinStack() {}
    void Push(int);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
    int getMin();
};

void MinStack::Push(int input)
{   
    if(!IsEmpty() && input > minStack.top())
        minStack.push(minStack.top());        
    else
        minStack.push(input);

    dataStack.push(input);
}

void MinStack::Pop()
{
    if(IsEmpty())
    {
        cout << "stack is empty" << endl;
        return;
    }

    dataStack.pop();
    minStack.pop();
}

bool MinStack::IsEmpty()
{
    return (dataStack.empty() && minStack.empty());
}

int MinStack::Top()
{
    if(IsEmpty())
    {
        cout << "stack is empty" << endl;
        return -1;
    }

    return dataStack.top();
}

int MinStack::getSize()
{
    if(IsEmpty())
    {
        cout << "stack is empty" << endl;
        return -1;
    }

    return dataStack.size();
}

int MinStack::getMin()
{
    if(IsEmpty())
    {
        cout << "stack is empty" << endl;
        return -1;
    }

    return minStack.top();
}


int main()
{
    MinStack minStack;
    minStack.Pop();
    minStack.Push(5);
    cout << "top: " << minStack.Top() << ", min: " << minStack.getMin() << endl; //5, 5

    minStack.Push(10);
    cout << "top: " << minStack.Top() << ", min: " << minStack.getMin() << endl; //10, 5

    minStack.Push(9);
    cout << "top: " << minStack.Top() << ", min: " << minStack.getMin() << endl; //9, 5

    minStack.Push(1);
    cout << "top: " << minStack.Top() << ", min: " << minStack.getMin() << endl; //1 ,1

    minStack.Pop();
    cout << "top: " << minStack.Top() << ", min: " << minStack.getMin() << endl; //9, 5

    minStack.Pop();
    cout << "top: " << minStack.Top() << ", min: " << minStack.getMin() << endl; //10, 5

    minStack.Pop();
    cout << "top: " << minStack.Top() << ", min: " << minStack.getMin() << endl; //5, 5

    minStack.Pop();
    cout << "top: " << minStack.Top() << "min: " << minStack.getMin() << endl; //empty

    return 0;
}
