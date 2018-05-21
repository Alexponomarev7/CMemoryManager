#include "StackAllocator.h"

const size_t AllocatorNode::_M_SIZE = 1e7;

AllocatorNode::AllocatorNode() : _current_memory(new char[_M_SIZE]), _size(0), next(nullptr) {}

AllocatorNode::~AllocatorNode() {
    delete[] (_current_memory - _size);
}

char* AllocatorNode::alloc(size_t required_memory) {
    std::cout << "StackAllocator: " << required_memory << " " << _size << std::endl;
    char* res = _current_memory;
    _current_memory += required_memory;
    _size += required_memory;
    return res;
}

size_t AllocatorNode::empty() const {
    return _M_SIZE - _size;
}
