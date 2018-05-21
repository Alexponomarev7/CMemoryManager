#include "currentMemoryManager.h"
#include "CMemoryManagerSwitcher.h"


void* CurrentMemoryManager::Alloc(std::size_t size) {
    return CMemoryManagerSwitcher::instance()->Alloc(size);
}

void CurrentMemoryManager::Free(void *ptr) {
    CMemoryManagerSwitcher::instance()->Free(ptr);
}