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
#include <cstddef>
#include <cstdint>

#include "include/Bitparams.h"



//***********************************************************************/

//TEST SECTION

//***********************************************************************/



#if 0
TEST_CASE("Testing Bitparams 8 bit")
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

    CHECK(Bp_t::is_valid_pos(0u) == true);
    CHECK(Bp_t::is_valid_pos(7u) == true);
    CHECK(Bp_t::is_valid_pos(8u) == false);

    CHECK(Bp_t::is_invalid_pos(0u) == false);
    CHECK(Bp_t::is_invalid_pos(7u) == false);
    CHECK(Bp_t::is_invalid_pos(8u) == true);

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
#endif



#if 0
TEST_CASE("Testing Bitparams 16 bit")
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

    CHECK(Bp_t::is_valid_pos(0u) == true);
    CHECK(Bp_t::is_valid_pos(15u) == true);
    CHECK(Bp_t::is_valid_pos(16u) == false);

    CHECK(Bp_t::is_invalid_pos(0u) == false);
    CHECK(Bp_t::is_invalid_pos(15u) == false);
    CHECK(Bp_t::is_invalid_pos(16u) == true);

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
#endif



TEST_CASE("Testing Bitparams 32 bit")
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

    CHECK(Bp_t::is_valid_pos(0u) == true);
    CHECK(Bp_t::is_valid_pos(31u) == true);
    CHECK(Bp_t::is_valid_pos(32u) == false);

    CHECK(Bp_t::is_invalid_pos(0u) == false);
    CHECK(Bp_t::is_invalid_pos(31u) == false);
    CHECK(Bp_t::is_invalid_pos(32u) == true);

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

TEST_CASE("Testing Bitparams 64 bit")
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

    CHECK(Bp_t::is_valid_pos(0u) == true);
    CHECK(Bp_t::is_valid_pos(63u) == true);
    CHECK(Bp_t::is_valid_pos(64u) == false);

    CHECK(Bp_t::is_invalid_pos(0u) == false);
    CHECK(Bp_t::is_invalid_pos(63u) == false);
    CHECK(Bp_t::is_invalid_pos(64u) == true);

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



#endif
