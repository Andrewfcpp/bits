
#include "tests/tests.h"

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <utility>



int main(/*int argc, char** argv*/)
{
    std::cout << "Hello!" << '\n' << '\n';

    auto x1 = fav::Bithelpers::find_lead_zero<std::uint64_t>(0xFFFF00000000FFFFull);
    std::cout << '\n' << x1 << '\n';






    //Run all tests.
    DOCTEST_RUN;
    std::cout << '\n' << '\n';



    std::cout << '\n' << '\n' << "Bye, bye!" << '\n' << '\n';
    system("pause 0"); //std::cin.get();
    return 0;
}