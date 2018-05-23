#include "Base.h"

const size_t InfoBlock::info = std::max(sizeof(IMemoryManager**),
                                  alignof(std::max_align_t));

Base::Base(IMemoryManager* newManager) {
    currentManager = newManager;
}

void* Base::Alloc(std::size_t size) noexcept(false) {
    char* memory = static_cast<char*>(currentManager->Alloc(size + InfoBlock::info));
    new(memory) IMemoryManager*(currentManager);
    return memory + InfoBlock::info;
}

void Base::Free(void *memory) noexcept {
    IMemoryManager** usedManager = reinterpret_cast<IMemoryManager**>(static_cast<char*>(memory) - InfoBlock::info);
    (*usedManager)->Free(static_cast<void*>(usedManager));
}