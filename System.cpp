#include <iostream>
#include <cstdlib>
#include "System.hpp"

// ? Required to work on Unix and Windows
void System::clean_console() {
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
};
