//=============================================|
// 
//Learning C ++
// 
//=============================================|
#include <iostream>
#include <stddef.h>
#include <algorithm>

using namespace std;

class Human
{
public:
    int age;
    float weight;
    string name;

    void AboutYou()
    {
        cout << "Name: " << name
             << "\nWeght: " << weight
             << "\nAge: " << age
             << endl;
    }

    void Get()
    {
        cout << "Enter your info\n";
        cout << "Your name: ";
        cin >> name;
        cout << "Your weight: ";
        cin >> weight;
        cout << "Your age: ";
        cin >> age;
        cout << endl;
    }
};

class CoffeeGrinder
{
private:
    bool Energy;

    bool GetVoltage(bool Vol)
    {
        return Vol;
    }

public:
    void SetEnergy(bool SetEnergy)
    {
        if (SetEnergy)
            Energy = true;
        else
            Energy = false;
    }
    void Start()
    {
        if (GetVoltage(Energy))
            cout << "VjuHHH!!" << endl;
        else
            cout << "\a" << endl;
    }
};

class Point
{
private:
    int x, y;
public:

    Point(int valueX  = 0, int valueY = 0) : x(valueX), y(valueY)
    {}

    void Print()
    {
        cout << "\nx = " << x
             << "\ny = " << y
             << endl;
    }
};

class Segment
{
private:
    Point p1;
    Point p2;
public:
    explicit Segment(int xcord1 = 0, int xcord2 = 0,
        int ycord1 = 0, int ycord2 = 0)
        : p1(xcord1,xcord2), p2(ycord1, ycord2) {}

    ~Segment()
    {}

    void InfoPoint()
    {
        p1.Print();
        p2.Print();
    }
};

class MyClass
{
private:
    int * data;
    size_t size;

    void swap_MyClass_(MyClass& a)
    {
        std::swap(size, a.size);
        std::swap(data, a.data);
    }

public:

    MyClass(const MyClass & other) 
        : size(other.size), data(new int [other.size])
    {
        for (size_t i = 0; i != size; ++i)
            this->data[i] = other.data[i];
    }

    MyClass(int size = 0) 
        : size(size), data(new int [size])
    {
        for (size_t i = 0; i != size; ++i)
            data[i] = i;

        cout << "Call Const " << this << endl;
    }

    MyClass& operator = (const MyClass& other)
    {
        if (this != &other)
            MyClass(other).swap_MyClass_(*this);

        return *this;
    }

    ~MyClass()
    {
        cout << "Call Destr" << this << endl;
        delete[] data;
    }
};

class IntArray
{
public:

    explicit IntArray(size_t size) 
        : size_(size), data_(new int[size])
    {
        for (size_t i = 0; i != size_; ++i)
            data_[i] = 0;
    }

    IntArray(const IntArray& a) 
        : size_(a.size_), data_(new int[size_])
    {
        for (size_t i = 0; i != size_; ++i)
            data_[i] = a.data_[i];
    }

    ~IntArray()
    {
        delete[] data_;
    }

    IntArray& operator = (const IntArray& a)
    {
        if (this != &a)
            IntArray(a).swap_IntArray_(*this);
        return *this;
    }

    size_t size() const { return size_; }

    int get(size_t i) const { return data_[i]; }

    int& get(size_t i) { return data_[i]; }

    void resize(size_t newSize)
    {
        IntArray t(newSize);

        size_t n = newSize > size_ ? size_ : newSize;
        for (size_t i = 0; i != n; ++i)
            t.data_[i] = data_[i];
        swap_IntArray_(t);
    }

private:

    void swap_IntArray_(IntArray& a)
    {
        std::swap(size_, a.size_);
        std::swap(data_, a.data_);
    }

    size_t size_;
    int* data_;
};

int main()
{
    setlocale(0, "ru");

    return 0;
}