#include "Queue.h"
#include <iostream>
using namespace std;

template<class T>
class LoopQueue: public Queue<T>
{
public:
    LoopQueue(int capacity)
    {
        data = new T[capacity + 1];
        front = 0;
        tail = 0;
        size = 0;
        this->capacity = capacity;
    }

    LoopQueue()
    {
        data = new T[10];
        front = 0;
        tail = 0;
        size = 0;
        capacity = 10;
    }

    int getCapacity()
    {
        return capacity - 1;
    }

    bool isEmpty()
    {
        return front == tail;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(T e)
    {
        if((tail + 1) % capacity == front)
            resize(getCapacity() * 2);
        
        data[tail] = e;
        tail = (tail + 1) % capacity;
    }

    T dequeue()
    {
        if(isEmpty())
            cout << "empty";
        
        T ret = data[front];
        front = (front + 1) % capacity;
        if ( size == getCapacity() / 4 && getCapacity() / 2 != 0)
            resize(getCapacity() / 2);
        size--;
        return ret;
    }

    T getFront()
    {
        if(isEmpty())
            cout << "empty";
        return data[front];
    }

    void print()
    {
        cout << "Queue: size = " << getSize() << ", capacity = " << getCapacity() << endl;
        cout << "front ";
        cout << "[";
        for (int i = front; i != tail ; (i + 1) % capacity) {
            cout << data[i];
            if ((i + 1) % capacity != tail) {
                cout << ", ";
            }
        }
        cout << "] tail" << endl;
    }


private:
    T *data;
    int front, tail;
    int size;
    int capacity;
    void resize(int newCapacity)
    {
        T *newData = new T[newCapacity + 1];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[(i + front) % capacity];
        }
        data = newData;
        front = 0;
        tail = size;
    }
};