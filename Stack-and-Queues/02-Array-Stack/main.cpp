#include "ArrayStack.h"

int main(void)
{
    ArrayStack<int> *stack = new ArrayStack<int>();
    for (int i = 0; i < 5; i++)
    {
        stack->push(i);
        stack->print();
    }
    cout << stack->pop() << endl;
    stack->print();

    system("pause");
    return 0;
}