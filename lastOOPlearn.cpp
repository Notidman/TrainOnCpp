//=============================================|
// 
//Learning C ++
// 
//=============================================|
#include <iostream>
#include <sstream>
using namespace std;

class Point
{
private:
    int x, y;
public:

    Point(int valueX = 0, int valueY = 0) : x(valueX), y(valueY)
    {}

    void Print()
    {
        cout << "\nx = " << x
             << "\ny = " << y
             << endl;
    }

    bool operator == (const Point& other)
    {
        return this->x == other.x && this->y == other.y;
    }

    bool operator != (const Point& other)
    {
        return this->x != other.x && this->y != other.y;
    }

    friend void Chx(Point& value);

};

void Chx(Point& value)
{
    value.x = -1;
}

class Test
{
public:
    Test(int size)
    {
        this->arr = new int[size];
        for (size_t i = 0; i != size; ++i)
            this->arr[i] = 1 + rand() % size;
        this->size = size;
    }

    ~Test()
    {
        delete arr;
    }

    void Print()
    {
        for (size_t i = 0; i != size; ++i)
            cout << arr[i];
        cout << endl;
    }

    int& operator[](int index)
    {
        return arr[index];
    }

private:
    int* arr;
    size_t size;
};

struct String {

    String(const char* str) : size(strlen(str))
    {
        this->str = new char[size + 1];
        strcpy_s(this->str, this->size+1, str);
    }

    String(const String& a) : size(a.size), str(new char[size+1])
    {
        for (size_t i = 0; i != size+1; ++i)
            str[i] = a.str[i];
    }

    String& operator = (const String& a)
    {
        if (this != &a)
            String(a).swap_String_(*this);
        return *this;
    }
    
    
    ~String()
    {
        delete[] str;
    }

    void Print() const
    {
        cout << str << endl
            << size << endl;
    }

private:

    void swap_String_(String& a)
    {
        std::swap(size, a.size);
        std::swap(str, a.str);
    }

    size_t size;
    char* str;
};

struct Expression
{
    virtual double evaluate() const = 0;

    virtual ~Expression(){}

};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}

    double evaluate() const {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right)
    { }

    double evaluate() const {
        switch (op)
        {
        case '/':
            return left->evaluate() / right->evaluate();
            break;
        case '+':
            return left->evaluate() + right->evaluate();
            break;
        case '-':
            return left->evaluate() - right->evaluate();
            break;
        case '*':
            return left->evaluate() * right->evaluate();
            break;
        default:
            break;
        }
    }

    ~BinaryOperation()
    {
        delete left;
        delete right;
    }

private:
    Expression const* left;
    Expression const* right;
    char op;
};

class Apple
{
public:

    Apple(int weight, string color, string sort)
        : weight(weight), color(color), sort(sort)
    {
        count += 1;
    }

    virtual string About() const
    {
        return "This apple has\nName: " + sort +
            "\nWeight: " + to_string(weight) + "\nColor: " + color
            + "\n";
    }

    void CountApple() { cout << count << endl; }



private:
    static int count;
    int weight;
    string color;
    string sort;
};

class Company : public Apple
{
public:
    Company(int weight, string color, string sort, string company)
        : Apple(weight, color, sort), company(company) {}

    string About() const
    {
        return Apple::About() + "Sort:" + company + "\n";
    }

private:
    string company;
};

int Apple::count = 0;

int main()
{
    Apple a(60, "Red", "RedSunrise");

    cout << a.About() << endl;

    Company b(34, "Green", "GreenDay", "Beliver");

    cout << b.About() << endl;

    b.CountApple();

    return 0;
}