
#include "tests/tests.h"

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>



#define COMPILER_USE_INLINE



int main(/*int argc, char** argv*/)
{
    std::cout << "Start." << '\n' << '\n';



    //Run all tests.
    DOCTEST_RUN;



    std::cout << '\n' << '\n' << "Exit." << '\n' << '\n';
    system("pause 0"); //std::cin.get();
    return 0;
}