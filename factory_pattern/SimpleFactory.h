#ifndef SIMPLE_FACTORY_H
#define SIMPLE_FACTORY_H

#include <iostream>

class Product
{
public:
    virtual void play(void) = 0;    // 没有定义的函数记得声明为纯虚函数
};

class DVD: public Product
{
public:
    void play(void)
    {
        std::cout << "now play DVD" << std::endl;
    }
};

class CD: public Product
{
public:
    void play(void)
    {
        std::cout << "now play CD" << std::endl;
    }
};

class Creator
{
public:
    enum PRODUCT_TYPE
    {
        TYPE_DVD,
        TYPE_CD
    };

    Product* factory(PRODUCT_TYPE type) {
        switch (type) {
        case TYPE_DVD:
            return new DVD;
        case TYPE_CD:
            return new CD;
        default:
            return NULL;
        }
    }
};

#endif // SIMPLE_FACTORY_H
