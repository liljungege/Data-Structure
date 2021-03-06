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
    return sizeof(data) / sizeof(int);
}

int Array::getSize()
{
    return size;
}

int Array::isEmpyy()
{
    return size == 0;
}