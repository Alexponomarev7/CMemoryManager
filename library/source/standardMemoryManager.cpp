#include "standardMemoryManager.h"

void* StandardMemoryManager::Alloc(std::size_t size) {
    void* result;

    while ((result = ::malloc(size)) == nullptr) {
        std::new_handler newHandler = std::get_new_handler();
        if (newHandler)
            newHandler();
        else
            throw std::bad_alloc();
    }

    return result;
}

void StandardMemoryManager::Free(void *memory) {
    ::free(memory);
}