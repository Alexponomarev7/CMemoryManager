#ifndef CMEMORYMANAGERSWITCHER_STANDARDMEMORYMANAGER_H
#define CMEMORYMANAGERSWITCHER_STANDARDMEMORYMANAGER_H

#include "IMemoryManager.h"

class StandardMemoryManager : public IMemoryManager {
public:
    StandardMemoryManager() = default;
    void* Alloc(std::size_t size);
    void Free(void* ptr);
    ~StandardMemoryManager() {};
};

#endif //CMEMORYMANAGERSWITCHER_STANDARDMEMORYMANAGER_H
