#ifndef CMEMORYMANAGERSWITCHER_CMEMORYMANAGERSWITCHER_H
#define CMEMORYMANAGERSWITCHER_CMEMORYMANAGERSWITCHER_H

#include <iostream>
#include "Base.h"

class List {
private:
    Base *_current, *_prev;
public:
    List(Base* new_base);

    void push_back(Base* new_base);
    void pop_back();

    Base* back();
};


class CMemoryManagerSwitcher {
public:
    Base* _instance;
    static List* _vector_instance;

    CMemoryManagerSwitcher(Base* manager);
    ~CMemoryManagerSwitcher();

    static Base* instance();
};

#endif //CMEMORYMANAGERSWITCHER_CMEMORYMANAGERSWITCHER_H