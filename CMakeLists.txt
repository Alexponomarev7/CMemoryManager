cmake_minimum_required(VERSION 3.10)
project(CMemoryManagerSwitcher)

enable_testing()

set(CMAKE_CXX_STANDARD 11)

include_directories(library/headers)

set(SOURCE_LIB main.cpp library/source/CMemoryManagerSwitcher.cpp library/source/Base.cpp library/source/standardMemoryManager.cpp
        library/source/IMemoryManager.cpp library/source/CurrentMemoryManager.cpp library/source/RuntimeHeap.cpp
        library/source/StackAllocator.cpp library/source/stackMemoryManager.cpp)
add_executable(main ${SOURCE_LIB})
