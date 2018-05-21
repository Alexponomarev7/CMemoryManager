#include "CMemoryManagerSwitcher.h"

List::List(Base* new_base) : _prev(nullptr), _current(new_base) {}

List* CMemoryManagerSwitcher::_vector_instance = new(::malloc(sizeof(List*))) List(new(::malloc(sizeof(Base*))) Base());

void List::push_back(Base* new_base) {
    _prev = _current;
    _current = new_base;
}

void List::pop_back() {
    _current = _prev;
}

Base* List::back() {
    return _current;
}

Base* CMemoryManagerSwitcher::instance() {
    if (_vector_instance == nullptr) {
        return new(::malloc(sizeof(Base*))) Base();
    }
    return _vector_instance->back();
}

CMemoryManagerSwitcher::CMemoryManagerSwitcher(Base* manager) {
    _instance = manager;
    _vector_instance->push_back(manager);
}

CMemoryManagerSwitcher::~CMemoryManagerSwitcher() {
    _vector_instance->pop_back();
}

void* operator new(std::size_t size) noexcept(false) {
    return CMemoryManagerSwitcher::instance()->Alloc(size);
}

void operator delete(void* ptr) noexcept {
    CMemoryManagerSwitcher::instance()->Free(ptr);
}

void* operator new(std::size_t size, const std::nothrow_t&) noexcept {
    void* p = nullptr;
    try {
        p = ::operator new(size);
    } catch (...) {}
    return p;
}

void* operator new[](std::size_t size) noexcept(false) {
    return ::operator new(size);
}

void* operator new[](std::size_t size, const std::nothrow_t&) noexcept {
    void* p = nullptr;
    try {
        p = ::operator new[](size);
    } catch (...) {}
    return p;
}

void operator delete(void* ptr, const std::nothrow_t&) noexcept {
    ::operator delete(ptr);
}

void operator delete(void* ptr, std::size_t) noexcept {
    ::operator delete(ptr);
}

void operator delete[](void* ptr) noexcept {
    ::operator delete(ptr);
}

void operator delete[](void* ptr, const std::nothrow_t&) noexcept {
    ::operator delete[](ptr);
}

void operator delete[](void* ptr, std::size_t) noexcept {
    ::operator delete[](ptr);
}