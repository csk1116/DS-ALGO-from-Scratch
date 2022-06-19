#include <iostream>
using namespace std;

class ArrayBasedStack
{
private:
    int top;
    int capacity;
    int* stack;
    void doubleCapacity();
public:
    ArrayBasedStack(){}
    void Push(int x);
    void Pop();
    bool IsEmpty();
    int Top();
    int getSize();
};

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
