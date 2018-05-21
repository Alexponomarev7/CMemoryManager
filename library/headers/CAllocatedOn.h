#ifndef CMEMORYMANAGERSWITCHER_CALLOCATEDON_H
#define CMEMORYMANAGERSWITCHER_CALLOCATEDON_H

#include <iostream>


template<typename Strategy>
class AllocatedOn {
    using _allocationStrategy = Strategy;
public:
    void* operator new(std::size_t size);
    void operator delete(void* ptr);
};

template<typename Strategy>
void* AllocatedOn<Strategy>::operator new(std::size_t size) {
    return _allocationStrategy::Alloc(size);
}

template<typename Strategy>
void AllocatedOn<Strategy>::operator delete(void* ptr) {
    _allocationStrategy::Free(ptr);
}


#endif //CMEMORYMANAGERSWITCHER_CALLOCATEDON_H
