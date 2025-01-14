// include -> library import 
#include "helloworld.h"

// Compilation command: g++ -o helloworld helloworld.cpp
// Format: g++ -o <executable> <source file> 

// Having extra, redundant brackets is fine. But there must be brackets. 
int helloworld() {
    // std -> standard library
    // cout -> character output 
    // endl -> end line, flushes output buffer as well

    // \t is 4 chars in that implementation
    std::cout << "This (\") is a quote,\tand this (\\) is a backslash." << std::endl; 

    // 0 -> success, other values -> something wrong 
    return 0;
}