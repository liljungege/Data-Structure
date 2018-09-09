#include "Array.h"
#include "Queue.h"
// #include <iostream>
using namespace std;

template<class T>
class ArrayQueue: public Queue<T>
{
public:
    ArrayQueue(int capacity)
    {
        array = new Array<T>(capacity);
    }

    ArrayQueue()
    {
        array = new Array<T>();
    }

    int getSize()
    {
        return array->getSize();
    }

    bool isEmpty()
    {
        return array->isEmpyy();
    }

    int getCapacity()
    {
        return array->getCapacity();
    }

    void enqueue(T e)
    {
        array->addLast(e);
    }

    T dequeue()
    {
        return array->removeFirst();
    }

    T getFront()
    {
        return array->getFirst();
    }

    void print()
    {
        cout << "Queue: size = " << array->getSize() << ", capacity = " << array->getCapacity() << endl;
        cout << "front ";
        cout << "[";
        for (int i = 0; i < array->getSize(); ++i) {
            cout << array->get(i);
            if (i != array->getSize() - 1) {
                cout << ", ";
            }
        }
        cout << "] tail" << endl;
    }

private:
    Array<T> *array;
};