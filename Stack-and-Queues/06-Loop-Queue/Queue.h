template<class T>
class Queue
{
public:
    int getSize();
    bool isEmpty();
    void enqueue(T e);
    T dequeue();
    T getFront();
};