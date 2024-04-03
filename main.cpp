
#include "tests/tests.h"

#include <iostream>
#include <cstddef>
#include <cstdint>



void test()
{
    using Bp_t = fav::Bitparams<std::uint32_t>;
    //Bp_t bp;
    constexpr auto x = Bp_t::IS_8BIT;

}



int main(/*int argc, char** argv*/)
{
    std::cout << "Hello!" << '\n' << '\n';



    DOCTEST_RUN;
    std::cout << '\n' << '\n';

    test();

    std::cout << '\n' << '\n' << "Press any key to exit." << '\n' << '\n';
    std::cin.get();
    return 0;
}