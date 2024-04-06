
#include "tests/tests.h"

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <utility>



int main(/*int argc, char** argv*/)
{
    std::cout << "Hello!" << '\n' << '\n';



    //Run all tests.
    DOCTEST_RUN;
    std::cout << '\n' << '\n';



    std::cout << '\n' << '\n' << "Bye, bye!" << '\n' << '\n';
    system("pause 0"); //std::cin.get();
    return 0;
}