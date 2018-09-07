#include "Array.h"

int main(void)
{
    Array *array = new Array(20);
    for (int i = 0; i < 10; i++)
    {
        array->addLast(i);
    }
    array->print();
    array->add(1, 100);
    array->addFirst(-1);
    array->print();

    array->remove(2);
    array->print();

    array->removeElement(4);
    array->print();

    array->removeFirst();
    array->print();

    system("pause");
    return 0;
}