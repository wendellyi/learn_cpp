#include <iostream>

template<class T>
class auto_ptr 
{
private:
    T* ap; 
public:

    // constructor & destructor ----------------------------------- (1)
    explicit auto_ptr (T* ptr = 0) throw() : ap(ptr){}

    ~auto_ptr() throw() 
    {
        delete ap;
    }


    // Copy & assignment --------------------------------------------(2)
    auto_ptr (auto_ptr& rhs) throw() :ap(rhs.release()) {}
    template<class Y>  
    auto_ptr (auto_ptr<Y>& rhs) throw() : ap(rhs.release()) { }

    auto_ptr& operator= (auto_ptr& rhs) throw() 
    {
        reset(rhs.release());
        return *this;
    }
    template<class Y>
    auto_ptr& operator= (auto_ptr<Y>& rhs) throw() 
    {
        reset(rhs.release());
        return *this;
    }

    // Dereference----------------------------------------------------(3)
    T& operator*() const throw() 
    {
        return *ap;
    }
    T* operator->() const throw() 
    {
        return ap;
    }

    // Helper functions------------------------------------------------(4)
    // value access
    T* get() const throw() 
    {
        return ap;
    }

    // release ownership
    T* release() throw()
    {
        T* tmp(ap);
        ap = 0;
        return tmp;
    }

    // reset value
    void reset (T* ptr=0) throw() 
    {
        if (ap != ptr) 
        {
            delete ap;
            ap = ptr;
        }
    }

    // Special conversions-----------------------------------------------(5)
    template<class Y>
    struct auto_ptr_ref
    {
        Y* yp;
        auto_ptr_ref (Y* rhs) : yp(rhs) {}
    };

    auto_ptr(auto_ptr_ref<T> rhs) throw() : ap(rhs.yp) { }
    auto_ptr& operator= (auto_ptr_ref<T> rhs) throw() 
    {  
        reset(rhs.yp);
        return *this;
    }
    template<class Y>
    operator auto_ptr_ref<Y>() throw() 
    {
        return auto_ptr_ref<Y>(release());
    }
    template<class Y>
    operator auto_ptr<Y>() throw()
    {
        return auto_ptr<Y>(release());
    }
};

class Explicit
{
public:

    explicit Explicit(int i)
    {
        value = i;
    }

private:
    int value;

};

class Wendell
{
public:
    Wendell()
    {
        std::cout << "Wendell come out" << std::endl;
    }

    ~Wendell()
    {
        std::cout << "Wendell come in" << std::endl;
    }
};

int main(void)
{
    auto_ptr<Wendell> wendell = new Wendell;
    //wendell.release();

    Explicit ex = 5;

    return 0;
}