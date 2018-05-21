#ifndef CMEMORYMANAGERSWITCHER_RUNTIMEHEAP_H
#define CMEMORYMANAGERSWITCHER_RUNTIMEHEAP_H

#include <iostream>

class RuntimeHeap {
public:
    static void* Alloc(std::size_t size);
    static void Free(void* ptr);
};

#endif //CMEMORYMANAGERSWITCHER_RUNTIMEHEAP_H
