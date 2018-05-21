#ifndef CMEMORYMANAGERSWITCHER_STACKMEMORYMANAGER_H
#define CMEMORYMANAGERSWITCHER_STACKMEMORYMANAGER_H

#include "IMemoryManager.h"
#include "StackAllocator.h"

class StackMemoryManager: public IMemoryManager {
public:
    StackMemoryManager() = default;
    void* Alloc(std::size_t size);
    void Free(void* ptr);
    ~StackMemoryManager() {};
private:
    StackAllocator<char> _allocator;
};

#endif //CMEMORYMANAGERSWITCHER_STACKMEMORYMANAGER_H
