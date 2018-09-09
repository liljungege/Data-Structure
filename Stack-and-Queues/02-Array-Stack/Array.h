#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class Array
{
    private:
        T *data;
        int size;
        int capacity;

    public:
        Array(int capacity);
        Array();
        int getCapacity();
        int getSize();
        int isEmpyy();
        void addLast(T e);
        void addFirst(T e);
        void add(int index, T e); 
        void print();      
        T get(int index);
        void set(int index, T e);
        bool contains(T e);
        int find(T e);
        T remove(int index);
        T removeFirst();
        T removeLast();
        void removeElement(T e);

        T getLast()
        {
            return get(size - 1);
        }

        T getFirst()
        {
            return get(0);
        }
};

// 构造函数，传入数组的容量capacity构造Array
template <class T>
Array<T>::Array(int capacity)
{
    data = new T[capacity];
    size = 0;
    this->capacity = capacity;
}

// 无参数构造函数，默认数组的容量capacity=10
template <class T>
Array<T>::Array()
{
    data = new T[10];
    size = 0;
    capacity = 10;
}

template <class T>
int Array<T>::getCapacity()
{
    return capacity;
}

template <class T>
int Array<T>::getSize()
{
    return size;
}

template <class T>
int Array<T>::isEmpyy()
{
    return size == 0;
}

template <class T>
void Array<T>::addLast(T e)
{
    add(size, e);
}

template <class T>
void Array<T>::addFirst(T e)
{
    add(0, e);
}

// 在index位置插入一个新元素e
template <class T>
void Array<T>::add(int index, T e)
{
    assert(size < capacity && index >= 0 && index <= size);
    for (int i = size - 1; i >= index; i--)
    {
        data[i + 1] = data[i];
    }
    data[index] = e;
    size++;
}

template <class T>
void Array<T>::print()
{
    cout << "Array: size = " << size << ", capacity = " << capacity << endl;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << data[i];
        if(i != size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

template <class T>
T Array<T>::get(int index)
{
    assert(index >= 0 && index < size);
    return data[index];
}

template <class T>
// 修改index索引位置的元素为e
void Array<T>::set(int index, T e)
{
    assert(index >= 0 && index < size);
    data[index] = e;
}

// 查找数组中是否有元素e
template <class T>
bool Array<T>::contains(T e)
{
    for (int i = 0; i < size; i++)
    {
        if(data[i] == e)
            return true;
    }
    return false;
}

// 查找数组中元素所在的索引，如果不存在元素e，则返回-1
template <class T>
int Array<T>::find(T e)
{
    for (int i = 0; i < size; i++)
    {
        if(data[i] == e)
            return i;
    }
    return -1;
}

// 从数组中删除index位置的元素，返回删除的元素
template <class T>
T Array<T>::remove(int index)
{
    assert(index >= 0 && index < size);

    int ret = data[index];
    for (int i = index + 1; i < size; i++)
    {
        data[i-1] = data[i];
    }
    size--;
    return ret;
}

template <class T>
T Array<T>::removeFirst()
{
    return remove(0);
}

template <class T>
T Array<T>::removeLast()
{
    return remove(size - 1);
}

template <class T>
void Array<T>::removeElement(T e)
{
    int index = find(e);
    if(index != -1)
        remove(index);
}