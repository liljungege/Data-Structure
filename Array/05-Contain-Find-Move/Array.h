#include <cassert>
#include <iostream>
using namespace std;

class Array
{
    private:
        int *data;
        int size;
        int capacity;

    public:
        Array(int capacity);
        Array();
        int getCapacity();
        int getSize();
        int isEmpyy();
        void addLast(int e);
        void addFirst(int e);
        void add(int index, int e); 
        void print();      
        int get(int index);
        void set(int index, int e);
        bool contains(int e);
        int find(int e);
        int remove(int index);
        int removeFirst();
        int removeLast();
        void removeElement(int e);
};

// 构造函数，传入数组的容量capacity构造Array
Array::Array(int capacity)
{
    data = new int[capacity];
    size = 0;
    this->capacity = capacity;
}

// 无参数构造函数，默认数组的容量capacity=10
Array::Array()
{
    data = new int[10];
    size = 0;
    capacity = 10;
}

int Array::getCapacity()
{
    return capacity;
}

int Array::getSize()
{
    return size;
}

int Array::isEmpyy()
{
    return size == 0;
}

void Array::addLast(int e)
{
    add(size, e);
}

void Array::addFirst(int e)
{
    add(0, e);
}

// 在index位置插入一个新元素e
void Array::add(int index, int e)
{
    assert(size < capacity && index >= 0 && index <= size);
    for (int i = size - 1; i >= index; i--)
    {
        data[i + 1] = data[i];
    }
    data[index] = e;
    size++;
}

void Array::print()
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

int Array::get(int index)
{
    assert(index >= 0 && index < size);
    return data[index];
}

// 修改index索引位置的元素为e
void Array::set(int index, int e)
{
    assert(index >= 0 && index < size);
    data[index] = e;
}

// 查找数组中是否有元素e
bool Array::contains(int e)
{
    for (int i = 0; i < size; i++)
    {
        if(data[i] == e)
            return true;
    }
    return false;
}

// 查找数组中元素所在的索引，如果不存在元素e，则返回-1
int Array::find(int e)
{
    for (int i = 0; i < size; i++)
    {
        if(data[i] == e)
            return i;
    }
    return -1;
}

// 从数组中删除index位置的元素，返回删除的元素
int Array::remove(int index)
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

int Array::removeFirst()
{
    return remove(0);
}

int Array::removeLast()
{
    return remove(size - 1);
}

void Array::removeElement(int e)
{
    int index = find(e);
    if(index != -1)
        remove(index);
}