#ifndef CMEMORYMANAGERSWITCHER_IMEMORYMANAGER_H
#define CMEMORYMANAGERSWITCHER_IMEMORYMANAGER_H

#include <iostream>

class IMemoryManager {
public:
    virtual void* Alloc(std::size_t size) = 0;
    virtual void Free(void* ptr) = 0;
    virtual ~IMemoryManager() = 0;
};

#endif //CMEMORYMANAGERSWITCHER_IMEMORYMANAGER_H
