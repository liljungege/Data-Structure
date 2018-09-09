#include "LoopQueue.h"
#include <iostream>

int main(void)
{
    LoopQueue<int> *queue = new LoopQueue<int>();
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