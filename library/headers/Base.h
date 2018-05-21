#ifndef CMEMORYMANAGERSWITCHER_BASE_H
#define CMEMORYMANAGERSWITCHER_BASE_H

#include "standardMemoryManager.h"

class Base {
private:
    IMemoryManager* currentManager;
public:
    Base(IMemoryManager* newManager = new(::malloc(sizeof(StandardMemoryManager))) StandardMemoryManager());
    Base(const Base&) = delete;
    Base& operator=(const Base&) = delete;
    ~Base() {};

    void* Alloc(std::size_t size) noexcept(false);
    void Free(void* ptr) noexcept;

};

#endif //CMEMORYMANAGERSWITCHER_SINGLETONBASE_H
