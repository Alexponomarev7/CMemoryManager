#include "Base.h"

Base::Base(IMemoryManager* newManager) {
    currentManager = newManager;
}

void* Base::Alloc(std::size_t size) noexcept(false) {
    char* memory = static_cast<char*>(currentManager->Alloc(size + sizeof(IMemoryManager*)));
    new(memory) IMemoryManager*(currentManager);
    return memory + sizeof(IMemoryManager*);
}

void Base::Free(void *memory) noexcept {
    IMemoryManager** usedManager = static_cast<IMemoryManager**>(memory) - 1;
    (*usedManager)->Free(static_cast<void*>(usedManager));
}