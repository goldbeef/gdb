/*************************************************************************
    > File Name: class.cpp
    > Author: goldbeef
    > Mail: goldbeef@163.com 
    > Created Time: 2017年04月22日 星期六 10时45分33秒
 ************************************************************************/

#include <stdio.h>

int add(int a, int b)
{
    int c = a + b;
    return c;
}

class CBase
{
public:
    virtual void show()
    {
        printf("from CBase::show()\n");
    }
};

class CChild1: public CBase 
{ 
public: 
    virtual void show() 
    {
        printf("from CChild1::show()\n");
    }
};


class CChild2: public CBase 
{ 
public: 
    virtual void show() 
    {
        printf("from CChild2::show()\n");
    }
};


int main()
{
    CBase *ptr0 = new CBase;
    CBase *ptr1 = new CChild1;
    CBase *ptr2 = new CChild2;

    ptr0->show();
    ptr1->show();
    ptr2->show();
}
