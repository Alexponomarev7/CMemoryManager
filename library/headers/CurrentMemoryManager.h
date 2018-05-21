#ifndef CMEMORYMANAGERSWITCHER_CURRENTMEMORYMANAGER_H
#define CMEMORYMANAGERSWITCHER_CURRENTMEMORYMANAGER_H

#include <iostream>

class CurrentMemoryManager {
public:
    static void* Alloc(std::size_t size);
    static void Free(void* ptr);
};

#endif //CMEMORYMANAGERSWITCHER_CURRENTMEMORYMANAGER_H
