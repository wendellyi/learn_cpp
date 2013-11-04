#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

class AbstractDisk
{
public:
    virtual void play(void) = 0;
};

class AbstractFactory
{
public:
    virtual AbstractDisk* create(void) = 0;
};

class DiskDVD: public AbstractDisk
{
public:
    void play(void)
    {
        std::cout << "now play DVD" << std::endl;
    }
};

class DiskCD: public AbstractDisk
{
public:
    void play(void)
    {
        std::cout << "now play CD" << std::endl;
    }
};

class DVDFactory: public AbstractFactory
{
public:
    AbstractDisk* create(void)
    {
        return new DiskDVD;
    }
};

class CDFactory: public AbstractFactory
{
public:
    AbstractDisk* create(void)
    {
        return new DiskCD;
    }
};

#endif // ABSTRACTFACTORY_H