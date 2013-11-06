#include <iostream>

class A
{
public:
    A(int i, int j)
    {
        _i = i;
        _j = j;
    }

    void display(A& a)
    {
        std::cout << "_i = " << a._i << std::endl;
        std::cout << "_j = " << a._j << std::endl;
    }

private:
    int _i;
    int _j;
};

class B
{
public:
    enum type
    {
        animal,
        plant,
        insect
    };

private:
    typedef int INT32;
    static INT32 value;
};

B::INT32 B::value = 0;          // Ok

int main(void)
{
    A a(386, 686);
    A b(3, 5);

    a.display(b);
    b.display(a);

    /////////////////////////////////////////////////////////////
    //B::INT32 i = 0;           // Bad
    B::type t = B::animal;


    return 0;
}

/*
    Êä³ö£º
    _i = 3
    _j = 5
    _i = 386
    _j = 686
*/