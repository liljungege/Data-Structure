#include "ArrayQueue.h"
#include <iostream>

int main(void)
{
    ArrayQueue<int> *queue = new ArrayQueue<int>();
    for (int i = 0; i < 10; i++)
    {
        queue->enqueue(i);
        queue->print();

        if(i % 3 == 2)
        {
            queue->dequeue();
            queue->print();
        }
    }

    system("pause");
    return 0;

}