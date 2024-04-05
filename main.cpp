
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

    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x0000000000000000ull, 0u);
    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x0000000000000000ull, 4u);
    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x0000000000000000ull, 16u);
    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x0000000000000000ull, 63u);
    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x0000000000000000ull, 128u);

    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 0u);
    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 3u);
    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 15u);
    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 63u);
    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 128u);

    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 0u);
    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 4u);
    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 16u);
    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 63u);
    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0xFFFFFFFFFFFFFFFFull, 128u);



    //using T1 = std::uint32_t;
    //T1 x1;

    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 0u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 3u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 15u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 31u);
    //x1 = fav::Bithelpers::fill_trail_ones<T1>(0x12345678u, 128u);

    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x12345678u, 0u);
    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x12345678u, 4u);
    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x12345678u, 16u);
    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x12345678u, 31u);
    //x1 = fav::Bithelpers::fill_lead_ones<T1>(0x12345678u, 128u);

    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0x1234567Fu, 0u);
    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0x12345678u, 3u);
    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0x12345678u, 15u);
    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0x12345678u, 31u);
    //x1 = fav::Bithelpers::fill_trail_zeros<T1>(0x12345678u, 128u);

    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0x12345678u, 0u);
    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0x12345678u, 4u);
    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0x12345678u, 16u);
    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0xF2345678u, 31u);
    //x1 = fav::Bithelpers::fill_lead_zeros<T1>(0x12345678u, 128u);



    //constexpr bool endian = fav::Endian::IS_ENDIAN_LITTLE;
    //constexpr auto endian_type = fav::Endian::ENDIAN_TYPE;



    //Run all tests.
    DOCTEST_RUN;
    std::cout << '\n' << '\n';



    std::cout << '\n' << '\n' << "Bye, bye!" << '\n' << '\n';
    system("pause 0"); //std::cin.get();
    return 0;
}