#ifdef _MSC_VER
#pragma once
#endif

#ifndef TESTS_H
#define TESTS_H

#ifndef NDEBUG //Debug mode
//Enable tests
#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_RUN doctest_run();
#else
//Disable tests and remove from binary
#define DOCTEST_CONFIG_DISABLE
#pragma message("Warning: All tests will be disabled in Release mode! To use tests set Debug mode.")
#define DOCTEST_RUN /*NOTHING*/
#endif

#include "doctest.h"

//Doctest init and config function.
//Use DOCTEST_RUN; in main() to run all tests.
#ifndef NDEBUG //Debug mode
void doctest_run()
{
    doctest::Context context;

    context.setOption("abort-after", 5); // stop test execution after 5 failed assertions
    context.setOption("order-by", "file"); //Sort the tests by

    context.setOption("no-intro", true); //Doctest version etc.
    context.setOption("duration", true); //Print name and test time
    //context.setOption("success", true); //Print test details
    context.setOption("no-path-filenames", true);
    context.setOption("no-breaks", true); // don't break in the debugger when assertions fail
    context.setOption("no-debug-output", true); //Disables output in the debug console when a debugger is attached

    context.run(); //int res = context.run(); //Get test status.
}
#endif



/** User includes */
//#include <cstddef>
//#include <cstdint>

//#include "include/Bitparams.h"
//#include "include/Bithelpers.h"
#include "bits.h"


//***********************************************************************/

//TEST SECTION

//***********************************************************************/



TEST_CASE("Testing Bitparams uint8_t")
{
    using Bp_t = fav::Bitparams<std::uint8_t>;

    CHECK(Bp_t::NUM_BYTES == 1u);
    CHECK(Bp_t::NUM_BITS == 8u);
    CHECK(Bp_t::MASK_ALL == 0xFFu);
    CHECK(Bp_t::NUM_MSBIT == 7u);
    CHECK(Bp_t::VALUE_MSBIT == 0x80u);
    CHECK(Bp_t::MASK_LSBIT == 0xFEu);
    CHECK(Bp_t::MASK_MSBIT == 0x7Fu);

    CHECK(Bp_t::IS_8BIT == true);
    CHECK(Bp_t::IS_16BIT == false);
    CHECK(Bp_t::IS_32BIT == false);
    CHECK(Bp_t::IS_64BIT == false);

    CHECK(Bp_t::MASK_MSBYTE_0xF0 == 0xF0u);
    CHECK(Bp_t::MASK_MSBYTE_0xFF == 0xFFu);

    CHECK(Bp_t::is_set_any(0x00u) == false);
    CHECK(Bp_t::is_set_any(0x08u) == true);

    CHECK(Bp_t::is_set_all(0x10u) == false);
    CHECK(Bp_t::is_set_all(0xFFu) == true);

    CHECK(Bp_t::is_set_lsbit(0xFEu) == false);
    CHECK(Bp_t::is_set_lsbit(0x01u) == true);

    CHECK(Bp_t::is_set_msbit(0x7Fu) == false);
    CHECK(Bp_t::is_set_msbit(0x80u) == true);

    CHECK(Bp_t::is_clear_any(0xFFu) == false);
    CHECK(Bp_t::is_clear_any(0x07u) == true);

    CHECK(Bp_t::is_clear_all(0x80u) == false);
    CHECK(Bp_t::is_clear_all(0x00u) == true);

    CHECK(Bp_t::is_clear_lsbit(0xFFu) == false);
    CHECK(Bp_t::is_clear_lsbit(0xFEu) == true);

    CHECK(Bp_t::is_clear_msbit(0xFFu) == false);
    CHECK(Bp_t::is_clear_msbit(0x7Fu) == true);

    CHECK(Bp_t::is_valid_bitnum(0u) == true);
    CHECK(Bp_t::is_valid_bitnum(7u) == true);
    CHECK(Bp_t::is_valid_bitnum(8u) == false);

    CHECK(Bp_t::is_invalid_bitnum(0u) == false);
    CHECK(Bp_t::is_invalid_bitnum(7u) == false);
    CHECK(Bp_t::is_invalid_bitnum(8u) == true);

    CHECK(Bp_t::is_even(0xFEu) == true);
    CHECK(Bp_t::is_even(0xFFu) == false);

    CHECK(Bp_t::is_odd(0xFEu) == false);
    CHECK(Bp_t::is_odd(0xFFu) == true);

    CHECK(Bp_t::bit_value(0u) == 0x01u);
    CHECK(Bp_t::bit_value(3u) == 0x08u);
    CHECK(Bp_t::bit_value(7u) == 0x80u);
    CHECK(Bp_t::bit_value(8u) == 0x00u);

    CHECK(Bp_t::bit_mask(0u) == 0xFEu);
    CHECK(Bp_t::bit_mask(3u) == 0xF7u);
    CHECK(Bp_t::bit_mask(7u) == 0x7Fu);
    CHECK(Bp_t::bit_mask(8u) == 0xFFu);

}



TEST_CASE("Testing Bitparams uint16_t")
{
    using Bp_t = fav::Bitparams<std::uint16_t>;

    CHECK(Bp_t::NUM_BYTES == 2u);
    CHECK(Bp_t::NUM_BITS == 16u);
    CHECK(Bp_t::MASK_ALL == 0xFFFFu);
    CHECK(Bp_t::NUM_MSBIT == 15u);
    CHECK(Bp_t::VALUE_MSBIT == 0x8000u);
    CHECK(Bp_t::MASK_LSBIT == 0xFFFEu);
    CHECK(Bp_t::MASK_MSBIT == 0x7FFFu);

    CHECK(Bp_t::IS_8BIT == false);
    CHECK(Bp_t::IS_16BIT == true);
    CHECK(Bp_t::IS_32BIT == false);
    CHECK(Bp_t::IS_64BIT == false);

    CHECK(Bp_t::MASK_MSBYTE_0xF0 == 0xF000u);
    CHECK(Bp_t::MASK_MSBYTE_0xFF == 0xFF00u);

    CHECK(Bp_t::is_set_any(0x0000u) == false);
    CHECK(Bp_t::is_set_any(0x0080u) == true);

    CHECK(Bp_t::is_set_all(0x0010u) == false);
    CHECK(Bp_t::is_set_all(0xFFFFu) == true);

    CHECK(Bp_t::is_set_lsbit(0x0000u) == false);
    CHECK(Bp_t::is_set_lsbit(0x0001u) == true);

    CHECK(Bp_t::is_set_msbit(0x0000u) == false);
    CHECK(Bp_t::is_set_msbit(0x8000u) == true);

    CHECK(Bp_t::is_clear_any(0xFFFFu) == false);
    CHECK(Bp_t::is_clear_any(0x0070u) == true);

    CHECK(Bp_t::is_clear_all(0x0080u) == false);
    CHECK(Bp_t::is_clear_all(0x0000u) == true);

    CHECK(Bp_t::is_clear_lsbit(0xFFFFu) == false);
    CHECK(Bp_t::is_clear_lsbit(0xFFFEu) == true);

    CHECK(Bp_t::is_clear_msbit(0xFFFEu) == false);
    CHECK(Bp_t::is_clear_msbit(0x7FFFu) == true);

    CHECK(Bp_t::is_valid_bitnum(0u) == true);
    CHECK(Bp_t::is_valid_bitnum(15u) == true);
    CHECK(Bp_t::is_valid_bitnum(16u) == false);

    CHECK(Bp_t::is_invalid_bitnum(0u) == false);
    CHECK(Bp_t::is_invalid_bitnum(15u) == false);
    CHECK(Bp_t::is_invalid_bitnum(16u) == true);

    CHECK(Bp_t::is_even(0xFFFEu) == true);
    CHECK(Bp_t::is_even(0xFFFFu) == false);

    CHECK(Bp_t::is_odd(0xFFFEu) == false);
    CHECK(Bp_t::is_odd(0xFFFFu) == true);

    CHECK(Bp_t::bit_value(0u)  == 0x0001u);
    CHECK(Bp_t::bit_value(7u)  == 0x0080u);
    CHECK(Bp_t::bit_value(15u) == 0x8000u);
    CHECK(Bp_t::bit_value(16u) == 0x0000u);

    CHECK(Bp_t::bit_mask(0u)  == 0xFFFEu);
    CHECK(Bp_t::bit_mask(7u)  == 0xFF7Fu);
    CHECK(Bp_t::bit_mask(15u) == 0x7FFFu);
    CHECK(Bp_t::bit_mask(16u) == 0xFFFFu);

}



TEST_CASE("Testing Bitparams uint32_t")
{
    using Bp_t = fav::Bitparams<std::uint32_t>;

    CHECK(Bp_t::NUM_BYTES == 4u);
    CHECK(Bp_t::NUM_BITS == 32u);
    CHECK(Bp_t::MASK_ALL == 0xFFFFFFFFu);
    CHECK(Bp_t::NUM_MSBIT == 31u);
    CHECK(Bp_t::VALUE_MSBIT == 0x80000000u);
    CHECK(Bp_t::MASK_LSBIT == 0xFFFFFFFEu);
    CHECK(Bp_t::MASK_MSBIT == 0x7FFFFFFFu);

    CHECK(Bp_t::IS_8BIT  == false);
    CHECK(Bp_t::IS_16BIT == false);
    CHECK(Bp_t::IS_32BIT == true);
    CHECK(Bp_t::IS_64BIT == false);

    CHECK(Bp_t::MASK_MSBYTE_0xF0 == 0xF0000000u);
    CHECK(Bp_t::MASK_MSBYTE_0xFF == 0xFF000000u);

    CHECK(Bp_t::is_set_any(0x00000000u)  == false);
    CHECK(Bp_t::is_set_any(0x00008000u)  == true);

    CHECK(Bp_t::is_set_all(0x00001000u) == false);
    CHECK(Bp_t::is_set_all(0xFFFFFFFFu) == true);

    CHECK(Bp_t::is_set_lsbit(0x00000000u) == false);
    CHECK(Bp_t::is_set_lsbit(0x00000001u) == true);

    CHECK(Bp_t::is_set_msbit(0x00000000u) == false);
    CHECK(Bp_t::is_set_msbit(0x80000000u) == true);

    CHECK(Bp_t::is_clear_any(0xFFFFFFFFu) == false);
    CHECK(Bp_t::is_clear_any(0x00007000u) == true);

    CHECK(Bp_t::is_clear_all(0x00008000u) == false);
    CHECK(Bp_t::is_clear_all(0x00000000u) == true);

    CHECK(Bp_t::is_clear_lsbit(0xFFFFFFFFu) == false);
    CHECK(Bp_t::is_clear_lsbit(0xFFFFFFFEu) == true);

    CHECK(Bp_t::is_clear_msbit(0xFFFFFFFEu) == false);
    CHECK(Bp_t::is_clear_msbit(0x7FFFFFFFu) == true);

    CHECK(Bp_t::is_valid_bitnum(0u) == true);
    CHECK(Bp_t::is_valid_bitnum(31u) == true);
    CHECK(Bp_t::is_valid_bitnum(32u) == false);

    CHECK(Bp_t::is_invalid_bitnum(0u) == false);
    CHECK(Bp_t::is_invalid_bitnum(31u) == false);
    CHECK(Bp_t::is_invalid_bitnum(32u) == true);

    CHECK(Bp_t::is_even(0xFFFFFFFEu) == true);
    CHECK(Bp_t::is_even(0xFFFFFFFFu) == false);

    CHECK(Bp_t::is_odd(0xFFFFFFFEu) == false);
    CHECK(Bp_t::is_odd(0xFFFFFFFFu) == true);

    CHECK(Bp_t::bit_value(0u)  == 0x00000001u);
    CHECK(Bp_t::bit_value(15u) == 0x00008000u);
    CHECK(Bp_t::bit_value(31u) == 0x80000000u);
    CHECK(Bp_t::bit_value(32u) == 0x00000000u);

    CHECK(Bp_t::bit_mask(0u)  == 0xFFFFFFFEu);
    CHECK(Bp_t::bit_mask(15u) == 0xFFFF7FFFu);
    CHECK(Bp_t::bit_mask(31u) == 0x7FFFFFFFu);
    CHECK(Bp_t::bit_mask(32u) == 0xFFFFFFFFu);

}



//Check 64 bit platform
#if INTPTR_MAX == INT64_MAX 

TEST_CASE("Testing Bitparams uint64_t")
{
    using Bp_t = fav::Bitparams<std::uint64_t>;

    CHECK(Bp_t::NUM_BYTES == 8u);
    CHECK(Bp_t::NUM_BITS == 64u);
    CHECK(Bp_t::MASK_ALL == 0xFFFFFFFFFFFFFFFFull);
    CHECK(Bp_t::NUM_MSBIT == 63u);
    CHECK(Bp_t::VALUE_MSBIT == 0x8000000000000000ull);
    CHECK(Bp_t::MASK_LSBIT == 0xFFFFFFFFFFFFFFFEull);
    CHECK(Bp_t::MASK_MSBIT == 0x7FFFFFFFFFFFFFFFull);

    CHECK(Bp_t::IS_8BIT == false);
    CHECK(Bp_t::IS_16BIT == false);
    CHECK(Bp_t::IS_32BIT == false);
    CHECK(Bp_t::IS_64BIT == true);

    CHECK(Bp_t::MASK_MSBYTE_0xF0 == 0xF000000000000000ull);
    CHECK(Bp_t::MASK_MSBYTE_0xFF == 0xFF00000000000000ull);

    CHECK(Bp_t::is_set_any(0x0000000000000000ull) == false);
    CHECK(Bp_t::is_set_any(0x0000800000000000ull) == true);

    CHECK(Bp_t::is_set_all(0x0000000000001000ull) == false);
    CHECK(Bp_t::is_set_all(0xFFFFFFFFFFFFFFFFull) == true);

    CHECK(Bp_t::is_set_lsbit(0x0000000000000000ull) == false);
    CHECK(Bp_t::is_set_lsbit(0x0000000000000001ull) == true);

    CHECK(Bp_t::is_set_msbit(0x0000000000000000ull) == false);
    CHECK(Bp_t::is_set_msbit(0x8000000000000000ull) == true);

    CHECK(Bp_t::is_clear_any(0xFFFFFFFFFFFFFFFFull) == false);
    CHECK(Bp_t::is_clear_any(0x0000000000007000ull) == true);

    CHECK(Bp_t::is_clear_all(0x0000000000008000ull) == false);
    CHECK(Bp_t::is_clear_all(0x0000000000000000ull) == true);

    CHECK(Bp_t::is_clear_lsbit(0xFFFFFFFFFFFFFFFFull) == false);
    CHECK(Bp_t::is_clear_lsbit(0xFFFFFFFFFFFFFFFEull) == true);

    CHECK(Bp_t::is_clear_msbit(0xFFFFFFFFFFFFFFFEull) == false);
    CHECK(Bp_t::is_clear_msbit(0x7FFFFFFFFFFFFFFFull) == true);

    CHECK(Bp_t::is_valid_bitnum(0u) == true);
    CHECK(Bp_t::is_valid_bitnum(63u) == true);
    CHECK(Bp_t::is_valid_bitnum(64u) == false);

    CHECK(Bp_t::is_invalid_bitnum(0u) == false);
    CHECK(Bp_t::is_invalid_bitnum(63u) == false);
    CHECK(Bp_t::is_invalid_bitnum(64u) == true);

    CHECK(Bp_t::is_even(0xFFFFFFFFFFFFFFFEull) == true);
    CHECK(Bp_t::is_even(0xFFFFFFFFFFFFFFFFull) == false);

    CHECK(Bp_t::is_odd(0xFFFFFFFFFFFFFFFEull) == false);
    CHECK(Bp_t::is_odd(0xFFFFFFFFFFFFFFFFull) == true);

    CHECK(Bp_t::bit_value(0u)  == 0x0000000000000001ull);
    CHECK(Bp_t::bit_value(15u) == 0x0000000000008000ull);
    CHECK(Bp_t::bit_value(63u) == 0x8000000000000000ull);
    CHECK(Bp_t::bit_value(64u) == 0x0000000000000000ull);

    CHECK(Bp_t::bit_mask(0u)  == 0xFFFFFFFFFFFFFFFEull);
    CHECK(Bp_t::bit_mask(15u) == 0xFFFFFFFFFFFF7FFFull);
    CHECK(Bp_t::bit_mask(63u) == 0x7FFFFFFFFFFFFFFFull);
    CHECK(Bp_t::bit_mask(64u) == 0xFFFFFFFFFFFFFFFFull);

}

#endif //Check 64 bit platform



//***********************************************************************/



TEST_CASE("Testing Bithelpers")
{
    using Bh_t = fav::Bithelpers;
    using U8_t = std::uint8_t;
    using U16_t = std::uint16_t;
    using U32_t = std::uint32_t;
    using U64_t = std::uint64_t;

    CHECK(Bh_t::reverse<U8_t>(0xF1u) == 0x8Fu);
    CHECK(Bh_t::reverse<U16_t>(0xF0F1u) == 0x8F0Fu);
    CHECK(Bh_t::reverse<U32_t>(0xF0F0FF01u) == 0x80FF0F0Fu);
    CHECK(Bh_t::reverse<U64_t>(0xF0F0FF00FF00FFF1ull) == 0x8FFF00FF00FF0F0Full);

    CHECK(Bh_t::mask_for<U8_t>(0x10u) == 0x1Fu);
    CHECK(Bh_t::mask_for<U16_t>(0x0102u) == 0x01FFu);
    CHECK(Bh_t::mask_for<U32_t>(0x01020304u) == 0x01FFFFFFu);
    CHECK(Bh_t::mask_for<U64_t>(0x0102030405060708ull) == 0x01FFFFFFFFFFFFFFull);

    CHECK(Bh_t::count_pop<U32_t>(0x00000001u) == 1u);
    CHECK(Bh_t::count_pop<U32_t>(0xFFFFFFFFu) == 32u);
    CHECK(Bh_t::count_pop<U32_t>(0x55555555u) == 16u);

    CHECK(Bh_t::count_pop<U64_t>(0x0000000000000001ull) == 1u);
    CHECK(Bh_t::count_pop<U64_t>(0xFFFFFFFFFFFFFFFFull) == 64u);
    CHECK(Bh_t::count_pop<U64_t>(0x5555555555555555ull) == 32u);

    CHECK(Bh_t::count_zeros<U32_t>(0x10203040u) == 27u);
    CHECK(Bh_t::count_zeros<U64_t>(0xF0F0F0F0F0F0F0F0ull) == 32u);

    CHECK(Bh_t::count_lead_zeros<U32_t>(0x0000FFFFu) == 16u);
    CHECK(Bh_t::count_lead_zeros<U64_t>(0x0FFFFFFFFFFFFFFFull) == 4u);

    CHECK(Bh_t::count_trail_zeros<U8_t>(0xF0u) == 4u);
    CHECK(Bh_t::count_trail_zeros<U16_t>(0xFF00u) == 8u);
    CHECK(Bh_t::count_trail_zeros<U32_t>(0xFFFF0000u) == 16u);
    CHECK(Bh_t::count_trail_zeros<U64_t>(0xF000000000000000ull) == 60u);

    CHECK(Bh_t::count_lead_ones<U32_t>(0xFFFF0000u) == 16u);
    CHECK(Bh_t::count_lead_ones<U64_t>(0xF00000000000F000ull) == 4u);

    CHECK(Bh_t::count_trail_ones<U32_t>(0x0000FFFFu) == 16u);
    CHECK(Bh_t::count_trail_ones<U64_t>(0xF00000000000000Full) == 4u);

    CHECK(Bh_t::pow2_highest<U32_t>(0x00030000u) == 262144u);
    CHECK(Bh_t::pow2_highest<U64_t>(0x0000000000030000ull) == 262144u);

    CHECK(Bh_t::pow2_lowest<U32_t>(0x00030000u) == 131072u);
    CHECK(Bh_t::pow2_lowest<U64_t>(0x0000000000030000ull) == 131072u);

    CHECK(Bh_t::isolate_trail<U32_t>(0x11223344u, 15) == 0x00003344u);
    CHECK(Bh_t::isolate_trail<U64_t>(0x1122334455667788ull, 31) == 0x0000000055667788ull);

    CHECK(Bh_t::isolate_lead<U32_t>(0x11223344u, 15) == 0x11220000u);
    CHECK(Bh_t::isolate_lead<U64_t>(0x1122334455667788ull, 31) == 0x1122334400000000ull);

    CHECK(Bh_t::remove_bit<U32_t>(0x11223344u, 15) == 0x08913344u);
    CHECK(Bh_t::remove_bit<U64_t>(0x1122334455667788ull, 31) == 0x089119A255667788ull);

    CHECK(Bh_t::find_lead_one<U32_t>(0x00F00000u) == 23u);
    CHECK(Bh_t::find_lead_one<U64_t>(0x0000F00000000000ull) == 47u);

    CHECK(Bh_t::find_trail_one<U32_t>(0x00F00000u) == 20u);
    CHECK(Bh_t::find_trail_one<U64_t>(0x0000F00000000000ull) == 44u);

    CHECK(Bh_t::find_lead_zero<U32_t>(0xFF0000FFu) == 23u);
    CHECK(Bh_t::find_lead_zero<U64_t>(0xFFFF00000000FFFFull) == 47u);

    CHECK(Bh_t::find_trail_zero<U32_t>(0xFF0000FFu) == 8u);
    CHECK(Bh_t::find_trail_zero<U64_t>(0xFFFF00000000FFFFull) == 16u);



    //Check 64 bit platform
#if INTPTR_MAX == INT64_MAX 



#endif

}



#endif
