#include <iostream>
using namespace std;

class MinStack
{
private:
    int top;
    int capacity;
    int* minStack;
    void doubleCapacity();
public:
    MinStack(){}
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

int main()
{
    MinStack minStack;
    minStack.Pop();
    minStack.Push(1); //1
    minStack.Push(3); //3, 1
    cout << "top: " << minStack.Top() << ", size: " << minStack.getSize() << endl; //3, 2
    minStack.Push(5); //5, 3, 1
    cout << "top: " << minStack.Top() << ", size: " << minStack.getSize() << endl; //5, 3
    minStack.Pop(); //3, 1
    minStack.Pop(); //1
    cout << "top: " << minStack.Top() << ", size: " << minStack.getSize() << endl; //1, 1
    minStack.Pop(); //empty
    cout << "top: " << minStack.Top() << ", size: " << minStack.getSize() << endl; //5, 3

    return 0;
}
