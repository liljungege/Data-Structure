#include "Array.h"
#include "Stack.h"

template <class T>
class ArrayStack;

template <class T>
class ArrayStack: public Stack<T>
{
    public:
        ArrayStack(int capacity)
        {
            array = new Array<T>(capacity);
        }
        
        ArrayStack()
        {
            array = new Array<T>();
        }

        int getSize()
        {
            return array->getSize();
        }

        bool isEmpty()
        {
            return array->isEmpty();
        }

        int getCapacity()
        {
            return array->getCapacity();
        }

        void push(T e)
        {
            array->addLast(e);
        }

        T pop()
        {
            return array->removeLast();
        }

        T peek()
        {
            return array->getLast();
        }

        void print()
        {
            cout << "Stack: size = " << array->getSize() << ", capacity = " << array->getCapacity() << endl;
            cout << "bottom: ";
            cout << "[";
            for (int i = 0; i < array->getSize(); ++i) {
                cout << array->get(i);
                if (i != array->getSize() - 1) {
                    cout << ", ";
                }
            }
            cout << "] ";
            cout << " top" << endl;
        }

    private:
        Array<T> *array;
        
};