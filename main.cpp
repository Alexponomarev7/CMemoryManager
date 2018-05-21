#include <iostream>

#include "CMemoryManagerSwitcher.h"
#include "standardMemoryManager.h"
#include "stackMemoryManager.h"

using namespace std;


template <typename T>
T* create(Base *v) {
    CMemoryManagerSwitcher SMem = CMemoryManagerSwitcher(v);

    return new T();
}

int main() {
    StackMemoryManager *st_mem_man = new StackMemoryManager();
    Base *v = new Base(st_mem_man);

    long double *x = create<long double>(v);

    char *y = new char();

    long double *z = create<long double>(v);

    return 0;
}