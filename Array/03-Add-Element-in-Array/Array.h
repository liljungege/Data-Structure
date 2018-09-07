#include <cassert>

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