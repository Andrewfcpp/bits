
#include "tests/tests.h"

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <utility>



int main(/*int argc, char** argv*/)
{
    std::cout << "Hello!" << '\n' << '\n';

    //0xFFFFFFFFFFFFFFFFull



    //using T1 = std::uint64_t;
    //T1 x1;
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x00ull, 15u);
    //std::cout << '\n' << x1 << '\n';

    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x00ull, 15u);
    //std::cout << '\n' << x1 << '\n';

    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x0000000000000000ull, 0u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x0000000000000000ull, 3u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x0000000000000000ull, 15u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x0000000000000000ull, 63u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x0000000000000000ull, 128u);




    //using T1 = std::uint32_t;
    //T1 x1;

    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 0u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 3u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 15u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 31u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 128u);



    using T1 = std::uint32_t;
    T1 x1;

    x1 = fav::Bitmanip<T1>::toggle_bit_ms(0x80000000u);
    //std::cout << '\n' << x1 << '\n';

    //constexpr auto a = fav::Bitparams<double>::NUM_BITS;

    //constexpr bool endian = fav::Endian::IS_ENDIAN_LITTLE;
    //constexpr auto endian_type = fav::Endian::ENDIAN_TYPE;



    //Run all tests.
    DOCTEST_RUN;
    std::cout << '\n' << '\n';



    std::cout << '\n' << '\n' << "Bye, bye!" << '\n' << '\n';
    system("pause 0"); //std::cin.get();
    return 0;
}