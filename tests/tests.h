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
    //context.setOption("out", "out.txt"); //Output to file.

    context.run(); //int res = context.run(); //Get test status.
}
#endif



/** User includes */
#include "include/bits.h"



//***********************************************************************/
//TEST SECTION
//***********************************************************************/



//Change to 0 for tests.
#if 0
TEST_CASE("Testing Bitparams uint8.")
{
    using Value_t = std::uint8_t;
    using Bp_t = fav::Bitparams<Value_t>;

    CHECK(Bp_t::NUM_BYTES == 1u);
    CHECK(Bp_t::NUM_BITS == 8u);
    CHECK(Bp_t::NUM_BITS_HALF == 4u);
    CHECK(Bp_t::NUM_BITS_QUART == 2u);
    CHECK(Bp_t::BIT_NUM_LS == 0u);
    CHECK(Bp_t::BIT_NUM_MS == 7u);
    CHECK(Bp_t::BIT_NUM_MS_HALF == 3u);
    CHECK(Bp_t::BIT_NUM_MS_QUART == 1u);
    CHECK(Bp_t::BIT_VALUE_LS == 1u);
    CHECK(Bp_t::BIT_VALUE_MS == 0x80u);
    CHECK(Bp_t::MASK_ALL == 0xFFu);
    CHECK(Bp_t::MASK_NUM_BITS == 0x07u);
    CHECK(Bp_t::MASK_BIT_LS == 0xFEu);
    CHECK(Bp_t::MASK_BIT_MS == 0x7Fu);
    CHECK(Bp_t::MASK_BYTE_LS_0x0F == 0x0Fu);
    CHECK(Bp_t::MASK_BYTE_LS_0xFF == 0xFFu);
    CHECK(Bp_t::MASK_BYTE_MS_0xF0 == 0xF0u);
    CHECK(Bp_t::MASK_BYTE_MS_0xFF == 0xFFu);

    CHECK(Bp_t::IS_NUM_BYTES_1 == true);
    CHECK(Bp_t::IS_NUM_BYTES_2 == false);
    CHECK(Bp_t::IS_NUM_BYTES_4 == false);
    CHECK(Bp_t::IS_NUM_BYTES_8 == false);

    CHECK(Bp_t::IS_NUM_BITS_8 == true);
    CHECK(Bp_t::IS_NUM_BITS_16 == false);
    CHECK(Bp_t::IS_NUM_BITS_32 == false);
    CHECK(Bp_t::IS_NUM_BITS_64 == false);

    CHECK(Bp_t::IS_TYPE_ARITHMETIC == true);
    CHECK(Bp_t::IS_TYPE_UNSIGNED == true);
    CHECK(Bp_t::IS_TYPE_SIGNED == false);
    CHECK(Bp_t::IS_TYPE_FLOATING == false);

}

//***********************************************************************/

TEST_CASE("Testing Bitparams uint16.")
{
    using Value_t = std::uint16_t;
    using Bp_t = fav::Bitparams<Value_t>;

    CHECK(Bp_t::NUM_BYTES == 2u);
    CHECK(Bp_t::NUM_BITS == 16u);
    CHECK(Bp_t::NUM_BITS_HALF == 8u);
    CHECK(Bp_t::NUM_BITS_QUART == 4u);
    CHECK(Bp_t::BIT_NUM_LS == 0u);
    CHECK(Bp_t::BIT_NUM_MS == 15u);
    CHECK(Bp_t::BIT_NUM_MS_HALF == 7u);
    CHECK(Bp_t::BIT_NUM_MS_QUART == 3u);
    CHECK(Bp_t::BIT_VALUE_LS == 1u);
    CHECK(Bp_t::BIT_VALUE_MS == 0x8000u);
    CHECK(Bp_t::MASK_ALL == 0xFFFFu);
    CHECK(Bp_t::MASK_NUM_BITS == 0x0Fu);
    CHECK(Bp_t::MASK_BIT_LS == 0xFFFEu);
    CHECK(Bp_t::MASK_BIT_MS == 0x7FFFu);
    CHECK(Bp_t::MASK_BYTE_LS_0x0F == 0x000Fu);
    CHECK(Bp_t::MASK_BYTE_LS_0xFF == 0x00FFu);
    CHECK(Bp_t::MASK_BYTE_MS_0xF0 == 0xF000u);
    CHECK(Bp_t::MASK_BYTE_MS_0xFF == 0xFF00u);

    CHECK(Bp_t::IS_NUM_BYTES_1 == false);
    CHECK(Bp_t::IS_NUM_BYTES_2 == true);
    CHECK(Bp_t::IS_NUM_BYTES_4 == false);
    CHECK(Bp_t::IS_NUM_BYTES_8 == false);

    CHECK(Bp_t::IS_NUM_BITS_8 == false);
    CHECK(Bp_t::IS_NUM_BITS_16 == true);
    CHECK(Bp_t::IS_NUM_BITS_32 == false);
    CHECK(Bp_t::IS_NUM_BITS_64 == false);

    CHECK(Bp_t::IS_TYPE_ARITHMETIC == true);
    CHECK(Bp_t::IS_TYPE_UNSIGNED == true);
    CHECK(Bp_t::IS_TYPE_SIGNED == false);
    CHECK(Bp_t::IS_TYPE_FLOATING == false);
    
}

#endif

//***********************************************************************/

TEST_CASE("Testing Bitparams uint32.")
{
    using Value_t = std::uint32_t;
    using Bp_t = fav::Bitparams<Value_t>;

    CHECK(Bp_t::NUM_BYTES == 4u);
    CHECK(Bp_t::NUM_BITS == 32u);
    CHECK(Bp_t::NUM_BITS_HALF == 16u);
    CHECK(Bp_t::NUM_BITS_QUART == 8u);
    CHECK(Bp_t::BIT_NUM_LS == 0u);
    CHECK(Bp_t::BIT_NUM_MS == 31u);
    CHECK(Bp_t::BIT_NUM_MS_HALF == 15u);
    CHECK(Bp_t::BIT_NUM_MS_QUART == 7u);
    CHECK(Bp_t::BIT_VALUE_LS == 1u);
    CHECK(Bp_t::BIT_VALUE_MS == 0x80000000u);
    CHECK(Bp_t::MASK_ALL == 0xFFFFFFFFu);
    CHECK(Bp_t::MASK_NUM_BITS == 0x0000001Fu);
    CHECK(Bp_t::MASK_BIT_LS == 0xFFFFFFFEu);
    CHECK(Bp_t::MASK_BIT_MS == 0x7FFFFFFFu);
    CHECK(Bp_t::MASK_BYTE_LS_0x0F == 0x0000000Fu);
    CHECK(Bp_t::MASK_BYTE_LS_0xFF == 0x000000FFu);
    CHECK(Bp_t::MASK_BYTE_MS_0xF0 == 0xF0000000u);
    CHECK(Bp_t::MASK_BYTE_MS_0xFF == 0xFF000000u);

    CHECK(Bp_t::IS_NUM_BYTES_1 == false);
    CHECK(Bp_t::IS_NUM_BYTES_2 == false);
    CHECK(Bp_t::IS_NUM_BYTES_4 == true);
    CHECK(Bp_t::IS_NUM_BYTES_8 == false);

    CHECK(Bp_t::IS_NUM_BITS_8 == false);
    CHECK(Bp_t::IS_NUM_BITS_16 == false);
    CHECK(Bp_t::IS_NUM_BITS_32 == true);
    CHECK(Bp_t::IS_NUM_BITS_64 == false);

    CHECK(Bp_t::IS_TYPE_ARITHMETIC == true);
    CHECK(Bp_t::IS_TYPE_UNSIGNED == true);
    CHECK(Bp_t::IS_TYPE_SIGNED == false);
    CHECK(Bp_t::IS_TYPE_FLOATING == false);

}

//***********************************************************************/

//Check for 64 bit platform
#if INTPTR_MAX == INT64_MAX 

TEST_CASE("Testing Bitparams uint64.")
{
    using Value_t = std::uint64_t;
    using Bp_t = fav::Bitparams<Value_t>;

    CHECK(Bp_t::NUM_BYTES == 8u);
    CHECK(Bp_t::NUM_BITS == 64u);
    CHECK(Bp_t::NUM_BITS_HALF == 32u);
    CHECK(Bp_t::NUM_BITS_QUART == 16u);
    CHECK(Bp_t::BIT_NUM_LS == 0u);
    CHECK(Bp_t::BIT_NUM_MS == 63u);
    CHECK(Bp_t::BIT_NUM_MS_HALF == 31u);
    CHECK(Bp_t::BIT_NUM_MS_QUART == 15u);
    CHECK(Bp_t::BIT_VALUE_LS == 1u);
    CHECK(Bp_t::BIT_VALUE_MS == 0x8000000000000000ull);
    CHECK(Bp_t::MASK_ALL == 0xFFFFFFFFFFFFFFFFull);
    CHECK(Bp_t::MASK_NUM_BITS == 0x0000003Full);
    CHECK(Bp_t::MASK_BIT_LS == 0xFFFFFFFFFFFFFFFEull);
    CHECK(Bp_t::MASK_BIT_MS == 0x7FFFFFFFFFFFFFFFull);
    CHECK(Bp_t::MASK_BYTE_LS_0x0F == 0x000000000000000Fu);
    CHECK(Bp_t::MASK_BYTE_LS_0xFF == 0x00000000000000FFu);
    CHECK(Bp_t::MASK_BYTE_MS_0xF0 == 0xF000000000000000u);
    CHECK(Bp_t::MASK_BYTE_MS_0xFF == 0xFF00000000000000u);

    CHECK(Bp_t::IS_NUM_BYTES_1 == false);
    CHECK(Bp_t::IS_NUM_BYTES_2 == false);
    CHECK(Bp_t::IS_NUM_BYTES_4 == false);
    CHECK(Bp_t::IS_NUM_BYTES_8 == true);

    CHECK(Bp_t::IS_NUM_BITS_8 == false);
    CHECK(Bp_t::IS_NUM_BITS_16 == false);
    CHECK(Bp_t::IS_NUM_BITS_32 == false);
    CHECK(Bp_t::IS_NUM_BITS_64 == true);

    CHECK(Bp_t::IS_TYPE_ARITHMETIC == true);
    CHECK(Bp_t::IS_TYPE_UNSIGNED == true);
    CHECK(Bp_t::IS_TYPE_SIGNED == false);
    CHECK(Bp_t::IS_TYPE_FLOATING == false);

}

#endif //Check 64 bit platform

//***********************************************************************/

TEST_CASE("Testing Bithelpers.")
{
    using Bh_t = fav::Bithelpers;
    using U8_t = std::uint8_t;
    using U16_t = std::uint16_t;
    using U32_t = std::uint32_t;

    CHECK(Bh_t::reverse<U8_t>(0xF1u) == 0x8Fu);
    CHECK(Bh_t::reverse<U16_t>(0xF0F1u) == 0x8F0Fu);
    CHECK(Bh_t::reverse<U32_t>(0xF0F0FF01u) == 0x80FF0F0Fu);
    
    CHECK(Bh_t::mask_for<U8_t>(0x10u) == 0x1Fu);
    CHECK(Bh_t::mask_for<U16_t>(0x0102u) == 0x01FFu);
    CHECK(Bh_t::mask_for<U32_t>(0x01020304u) == 0x01FFFFFFu);
    
    CHECK(Bh_t::count_pop<U32_t>(0x00000001u) == 1u);
    CHECK(Bh_t::count_pop<U32_t>(0xFFFFFFFFu) == 32u);
    CHECK(Bh_t::count_pop<U32_t>(0x55555555u) == 16u);

    CHECK(Bh_t::count_trail_zeros<U8_t>(0xF0u) == 4u);
    CHECK(Bh_t::count_trail_zeros<U16_t>(0xFF00u) == 8u);
    CHECK(Bh_t::count_trail_zeros<U32_t>(0xFFFF0000u) == 16u);
    CHECK(Bh_t::count_zeros<U32_t>(0x10203040u) == 27u);
    CHECK(Bh_t::count_lead_zeros<U32_t>(0x0000FFFFu) == 16u);
    CHECK(Bh_t::count_lead_ones<U32_t>(0xFFFF0000u) == 16u);
    CHECK(Bh_t::count_trail_ones<U32_t>(0x0000FFFFu) == 16u);

    CHECK(Bh_t::pow2_highest<U32_t>(0x00030000u) == 262144u);
    CHECK(Bh_t::pow2_lowest<U32_t>(0x00030000u) == 131072u);

    CHECK(Bh_t::isolate_trail<U32_t>(0x11223344u, 15) == 0x00003344u);
    CHECK(Bh_t::isolate_lead<U32_t>(0x11223344u, 15) == 0x11220000u);
    CHECK(Bh_t::remove_bit<U32_t>(0x11223344u, 15) == 0x08913344u);

    CHECK(Bh_t::find_lead_one<U32_t>(0x00F00000u) == 23u);
    CHECK(Bh_t::find_trail_one<U32_t>(0x00F00000u) == 20u);
    CHECK(Bh_t::find_lead_zero<U32_t>(0xFF0000FFu) == 23u);
    CHECK(Bh_t::find_trail_zero<U32_t>(0xFF0000FFu) == 8u);
    
    //***********************************************************************/

    CHECK(Bh_t::fill_trail_ones<U32_t>(0x00000000u, 0u) == 0x00000001u);
    CHECK(Bh_t::fill_trail_ones<U32_t>(0x00000000u, 3u) == 0x0000000Fu);
    CHECK(Bh_t::fill_trail_ones<U32_t>(0x00000000u, 15u) == 0x0000FFFFu);
    CHECK(Bh_t::fill_trail_ones<U32_t>(0x00000000u, 31u) == 0xFFFFFFFFu);
    CHECK(Bh_t::fill_trail_ones<U32_t>(0x00000000u, 128u) == 0xFFFFFFFFu);

    CHECK(Bh_t::fill_trail_ones<U32_t>(0x12345678u, 0u) == 0x12345679u);
    CHECK(Bh_t::fill_trail_ones<U32_t>(0x12345678u, 3u) == 0x1234567Fu);
    CHECK(Bh_t::fill_trail_ones<U32_t>(0x12345678u, 15u) == 0x1234FFFFu);
    CHECK(Bh_t::fill_trail_ones<U32_t>(0x12345678u, 31u) == 0xFFFFFFFFu);

    CHECK(Bh_t::fill_lead_ones<U32_t>(0x00000000u, 0u) == 0xFFFFFFFFu);
    CHECK(Bh_t::fill_lead_ones<U32_t>(0x00000000u, 4u) == 0xFFFFFFF0u);
    CHECK(Bh_t::fill_lead_ones<U32_t>(0x00000000u, 16u) == 0xFFFF0000u);
    CHECK(Bh_t::fill_lead_ones<U32_t>(0x00000000u, 31u) == 0x80000000u);
    CHECK(Bh_t::fill_lead_ones<U32_t>(0x00000000u, 128u) == 0x00000000u);

    CHECK(Bh_t::fill_lead_ones<U32_t>(0x12345678u, 0u) == 0xFFFFFFFFu);
    CHECK(Bh_t::fill_lead_ones<U32_t>(0x12345678u, 4u) == 0xFFFFFFF8u);
    CHECK(Bh_t::fill_lead_ones<U32_t>(0x12345678u, 16u) == 0xFFFF5678u);
    CHECK(Bh_t::fill_lead_ones<U32_t>(0x12345678u, 31u) == 0x92345678u);
    CHECK(Bh_t::fill_lead_ones<U32_t>(0x12345678u, 128u) == 0x12345678u);

    CHECK(Bh_t::fill_trail_zeros<U32_t>(0xFFFFFFFFu, 0u) == 0xFFFFFFFEu);
    CHECK(Bh_t::fill_trail_zeros<U32_t>(0xFFFFFFFFu, 3u) == 0xFFFFFFF0u);
    CHECK(Bh_t::fill_trail_zeros<U32_t>(0xFFFFFFFFu, 15u) == 0xFFFF0000u);
    CHECK(Bh_t::fill_trail_zeros<U32_t>(0xFFFFFFFFu, 31u) == 0x00000000u);
    CHECK(Bh_t::fill_trail_zeros<U32_t>(0xFFFFFFFFu, 128u) == 0x00000000u);

    CHECK(Bh_t::fill_trail_zeros<U32_t>(0x1234567Fu, 0u) == 0x1234567Eu);
    CHECK(Bh_t::fill_trail_zeros<U32_t>(0x12345678u, 3u) == 0x12345670u);
    CHECK(Bh_t::fill_trail_zeros<U32_t>(0x12345678u, 15u) == 0x12340000u);
    CHECK(Bh_t::fill_trail_zeros<U32_t>(0x12345678u, 31u) == 0x00000000u);

    CHECK(Bh_t::fill_lead_zeros<U32_t>(0xFFFFFFFFu, 0u) == 0x00000000u);
    CHECK(Bh_t::fill_lead_zeros<U32_t>(0xFFFFFFFFu, 4u) == 0x0000000Fu);
    CHECK(Bh_t::fill_lead_zeros<U32_t>(0xFFFFFFFFu, 16u) == 0x0000FFFFu);
    CHECK(Bh_t::fill_lead_zeros<U32_t>(0xFFFFFFFFu, 31u) == 0x7FFFFFFFu);
    CHECK(Bh_t::fill_lead_zeros<U32_t>(0xFFFFFFFFu, 128u) == 0xFFFFFFFFu);

    CHECK(Bh_t::fill_lead_zeros<U32_t>(0x12345678u, 0u) == 0x00000000u);
    CHECK(Bh_t::fill_lead_zeros<U32_t>(0x12345678u, 4u) == 0x00000008u);
    CHECK(Bh_t::fill_lead_zeros<U32_t>(0x12345678u, 16u) == 0x00005678u);
    CHECK(Bh_t::fill_lead_zeros<U32_t>(0xF2345678u, 31u) == 0x72345678u);
    CHECK(Bh_t::fill_lead_zeros<U32_t>(0x12345678u, 128u) == 0x12345678u);

    //***********************************************************************/

    CHECK(Bh_t::swap<U8_t>(0x12u) == 0x21u);
    CHECK(Bh_t::swap<U16_t>(0x1234u) == 0x3412u);
    CHECK(Bh_t::swap<U32_t>(0x12345678u) == 0x78563412u);

}

//***********************************************************************/

#if INTPTR_MAX == INT64_MAX //Check for 64 bit platform

TEST_CASE("Testing Bithelpers uint64.")
{
    using Bh_t = fav::Bithelpers;
    using U64_t = std::uint64_t;

    CHECK(Bh_t::reverse<U64_t>(0xF0F0FF00FF00FFF1ull) == 0x8FFF00FF00FF0F0Full);
    CHECK(Bh_t::mask_for<U64_t>(0x0102030405060708ull) == 0x01FFFFFFFFFFFFFFull);
    CHECK(Bh_t::count_pop<U64_t>(0x0000000000000001ull) == 1u);
    CHECK(Bh_t::count_pop<U64_t>(0x5555555555555555ull) == 32u);
    CHECK(Bh_t::count_zeros<U64_t>(0xF0F0F0F0F0F0F0F0ull) == 32u);
    CHECK(Bh_t::count_lead_zeros<U64_t>(0x0FFFFFFFFFFFFFFFull) == 4u);
    CHECK(Bh_t::count_trail_zeros<U64_t>(0xF000000000000000ull) == 60u);
    CHECK(Bh_t::count_lead_ones<U64_t>(0xF00000000000F000ull) == 4u);
    CHECK(Bh_t::count_trail_ones<U64_t>(0xF00000000000000Full) == 4u);
    CHECK(Bh_t::pow2_highest<U64_t>(0x0000000000030000ull) == 262144u); //0x40000
    CHECK(Bh_t::pow2_lowest<U64_t>(0x0000000000030000ull) == 131072u); //0x20000
    CHECK(Bh_t::isolate_trail<U64_t>(0x1122334455667788ull, 31) == 0x0000000055667788ull);
    CHECK(Bh_t::isolate_lead<U64_t>(0x1122334455667788ull, 31) == 0x1122334400000000ull);
    CHECK(Bh_t::remove_bit<U64_t>(0x1122334455667788ull, 31) == 0x089119A255667788ull);
    CHECK(Bh_t::find_lead_one<U64_t>(0x0000F00000000000ull) == 47u);
    CHECK(Bh_t::find_trail_one<U64_t>(0x0000F00000000000ull) == 44u);
    CHECK(Bh_t::find_lead_zero<U64_t>(0xFFFF00000000FFFFull) == 47u);
    CHECK(Bh_t::find_trail_zero<U64_t>(0xFFFF00000000FFFFull) == 16u);

    CHECK(Bh_t::swap<U64_t>(0x1234567890ABCDEFu) == 0xEFCDAB9078563412u);
}

#endif

//***********************************************************************/

TEST_CASE("Testing Bitmanip")
{
    using Value_t = std::uint32_t;
    using Bm32_t = fav::Bitmanip<Value_t>;

    CHECK(Bm32_t::get(0x00008000u, 15u) == 1u);
    CHECK(Bm32_t::get(0xFFFF7FFFu, 15u) == 0u);
    CHECK(Bm32_t::get_ls(0x00000001u) == 1u);
    CHECK(Bm32_t::get_ls(0x00000000u) == 0u);
    CHECK(Bm32_t::get_ms(0x80000000u) == 1u);
    CHECK(Bm32_t::get_ms(0x00000000u) == 0u);
    CHECK(Bm32_t::get_masked(0x12345678u, 0x000FF000u) == 0x00045000u);
    CHECK(Bm32_t::get_value(15u) == 0x00008000u);
    CHECK(Bm32_t::get_mask(15u) == 0xFFFF7FFFu);

    CHECK(Bm32_t::set_all(0x12345678u) == 0xFFFFFFFFu);
    CHECK(Bm32_t::set(0x00000000u, 15u) == 0x00008000u);
    CHECK(Bm32_t::set_state(0x00000000u, 15u, 1u) == 0x00008000u);
    CHECK(Bm32_t::set_state(0xFFFFFFFFu, 15u, 0u) == 0xFFFF7FFFu);
    CHECK(Bm32_t::set_ls(0x00000000u) == 0x00000001u);
    CHECK(Bm32_t::set_ms(0x00000000u) == 0x80000000u);
    CHECK(Bm32_t::set_masked(0x12345678u, 0x000FF000u) == 0x123FF678u);

    CHECK(Bm32_t::toggle(0x00008000u, 15u) == 0x00000000u);
    CHECK(Bm32_t::toggle(0x00000000u, 15u) == 0x00008000u);
    CHECK(Bm32_t::toggle_ls(0x00000000u) == 0x00000001u);
    CHECK(Bm32_t::toggle_ls(0x00000001u) == 0x00000000u);
    CHECK(Bm32_t::toggle_ms(0x00000000u) == 0x80000000u);
    CHECK(Bm32_t::toggle_ms(0x80000000u) == 0x00000000u);
    CHECK(Bm32_t::toggle_masked(0x55555555u, 0x000FF000u) == 0x555AA555u);
    CHECK(Bm32_t::toggle_masked(0x555AA555u, 0x000FF000u) == 0x55555555u);

    CHECK(Bm32_t::isolate(0xFFFFFFFFu, 15u) == 0x00008000u);
    CHECK(Bm32_t::isolate_ls(0xFFFFFFFFu) == 0x00000001u);
    CHECK(Bm32_t::isolate_ms(0xFFFFFFFFu) == 0x80000000u);
    CHECK(Bm32_t::isolate_masked(0x12345678u, 0x000FF000u) == 0x00045000u);

    CHECK(Bm32_t::clear_all(0x12345678u) == 0x00000000u);
    CHECK(Bm32_t::clear(0xFFFFFFFFu, 15u) == 0xFFFF7FFFu);
    CHECK(Bm32_t::clear_ls(0xFFFFFFFFu) == 0xFFFFFFFEu);
    CHECK(Bm32_t::clear_ms(0xFFFFFFFFu) == 0x7FFFFFFFu);
    CHECK(Bm32_t::clear_masked(0x12345678u, 0x000FF000u) == 0x12300678u);

    CHECK(Bm32_t::is_set_all(0xFFFF7FFFu) == false);
    CHECK(Bm32_t::is_set_all(0xFFFFFFFFu) == true);
    CHECK(Bm32_t::is_set_all(0xFFFFFFFFu, 0x000FF000u) == true);
    CHECK(Bm32_t::is_set_all(0xFFF7FFFFu, 0x000FF000u) == false);
    CHECK(Bm32_t::is_set_any(0x00000000u) == false);
    CHECK(Bm32_t::is_set_any(0x00008000u) == true);
    CHECK(Bm32_t::is_set_any(0xFFF01FFFu, 0x000FF000u) == true);
    CHECK(Bm32_t::is_set_any(0xFFF00FFFu, 0x000FF000u) == false);
    CHECK(Bm32_t::is_set_ls(0x00000000u) == false);
    CHECK(Bm32_t::is_set_ls(0x00000001u) == true);
    CHECK(Bm32_t::is_set_ms(0x00000000u) == false);
    CHECK(Bm32_t::is_set_ms(0x80000000u) == true);

    CHECK(Bm32_t::is_clear_all(0xFFFF7FFFu) == false);
    CHECK(Bm32_t::is_clear_all(0x00000000u) == true);
    CHECK(Bm32_t::is_clear_all(0xFFF00FFFu, 0x000FF000u) == true);
    CHECK(Bm32_t::is_clear_all(0xFFF01FFFu, 0x000FF000u) == false);
    CHECK(Bm32_t::is_clear_any(0xFFFFFFFFu) == false);
    CHECK(Bm32_t::is_clear_any(0xFFFF7FFFu) == true);
    CHECK(Bm32_t::is_clear_any(0xFFF8FFFFu, 0x000FF000u) == true);
    CHECK(Bm32_t::is_clear_any(0xFFFFFFFFu, 0x000FF000u) == false);
    CHECK(Bm32_t::is_clear_ls(0xFFFFFFFFu) == false);
    CHECK(Bm32_t::is_clear_ls(0xFFFFFFFEu) == true);
    CHECK(Bm32_t::is_clear_ms(0xFFFFFFFFu) == false);
    CHECK(Bm32_t::is_clear_ms(0x7FFFFFFFu) == true);

    CHECK(Bm32_t::is_valid(0u) == true);
    CHECK(Bm32_t::is_valid(31u) == true);
    CHECK(Bm32_t::is_valid(32u) == false);
    CHECK(Bm32_t::is_invalid(0u) == false);
    CHECK(Bm32_t::is_invalid(31u) == false);
    CHECK(Bm32_t::is_invalid(32u) == true);

    CHECK(Bm32_t::is_ls(0u) == true);
    CHECK(Bm32_t::is_ls(1u) == false);
    CHECK(Bm32_t::is_ms(31u) == true);
    CHECK(Bm32_t::is_ms(30u) == false);

    CHECK(Bm32_t::is_odd(0xFFFFFFFFu) == true);
    CHECK(Bm32_t::is_odd(0xFFFFFFFEu) == false);
    CHECK(Bm32_t::is_even(0xFFFFFFFFu) == false);
    CHECK(Bm32_t::is_even(0xFFFFFFFEu) == true);

    CHECK(Bm32_t::to_bool(0x00000000u) == false);
    CHECK(Bm32_t::to_bool(0x12345678u) == true);

    CHECK(Bm32_t::advance(0u) == 0u);
    CHECK(Bm32_t::advance(31u) == 31u);
    CHECK(Bm32_t::advance(32u) == 0u);
    CHECK(Bm32_t::advance(33u) == 1u);

    Value_t a = 0x12345678u;
    Value_t b = 0x87654321u;
    Bm32_t::swap(a, b);
    CHECK(a == 0x87654321u);
    CHECK(b == 0x12345678u);

}

//***********************************************************************/

TEST_CASE("Testing Codec_4bit.")
{
    using U8_t = std::uint8_t;
    using U16_t = std::uint16_t;
    using U32_t = std::uint32_t;
    using U64_t = std::uint64_t;

    CHECK(fav::Codec_4bit<U8_t>::decode(0x0Fu) == 0x0Fu);
    CHECK(fav::Codec_4bit<U16_t>::decode(0x0F0Fu) == 0x00FFu);
    CHECK(fav::Codec_4bit<U32_t>::decode(0x0F0F0F0Fu) == 0x0000FFFFu);

    CHECK(fav::Codec_4bit<U8_t>::encode(0x0Fu) == 0x0Fu);
    CHECK(fav::Codec_4bit<U16_t>::encode(0x00FFu) == 0x0F0Fu);
    CHECK(fav::Codec_4bit<U32_t>::encode(0x0000FFFFu) == 0x0F0F0F0Fu);

#if INTPTR_MAX == INT64_MAX //Check for 64 bit platform

    CHECK(fav::Codec_4bit<U64_t>::decode(0x0F0F0F0F0F0F0F0Full) == 0x00000000FFFFFFFFull);
    CHECK(fav::Codec_4bit<U64_t>::encode(0x00000000FFFFFFFFull) == 0x0F0F0F0F0F0F0F0Full);

#endif
}

//***********************************************************************/

TEST_CASE("Testing Codec_7bit.")
{
    using U8_t = std::uint8_t;
    using U16_t = std::uint16_t;
    using U32_t = std::uint32_t;
    using U64_t = std::uint64_t;

    CHECK(fav::Codec_7bit<U8_t>::decode(0x7Fu) == 0x7Fu);
    CHECK(fav::Codec_7bit<U16_t>::decode(0x7F7Fu) == 0x3FFFu);
    CHECK(fav::Codec_7bit<U32_t>::decode(0x7F7F7F7Fu) == 0x0FFFFFFFu);

    CHECK(fav::Codec_7bit<U8_t>::encode(0x7Fu) == 0x7Fu);
    CHECK(fav::Codec_7bit<U16_t>::encode(0x3FFFu) == 0x7F7Fu);
    CHECK(fav::Codec_7bit<U32_t>::encode(0x0FFFFFFFu) == 0x7F7F7F7Fu);

#if INTPTR_MAX == INT64_MAX //Check for 64 bit platform

    CHECK(fav::Codec_7bit<U64_t>::decode(0x7F7F7F7F7F7F7F7Full) == 0x00FFFFFFFFFFFFFFull);
    CHECK(fav::Codec_7bit<U64_t>::encode(0x00FFFFFFFFFFFFFFull) == 0x7F7F7F7F7F7F7F7Full);

#endif
}

//***********************************************************************/

TEST_CASE("Testing Codec_bcd.")
{
    using U8_t = std::uint8_t;
    using U16_t = std::uint16_t;
    using U32_t = std::uint32_t;
    using U64_t = std::uint64_t;

    CHECK(fav::Codec_bcd<U8_t>::decode(0x12u) == 12u);
    CHECK(fav::Codec_bcd<U16_t>::decode(0x1234u) == 1234u);
    CHECK(fav::Codec_bcd<U32_t>::decode(0x12345678u) == 12345678u);

    CHECK(fav::Codec_bcd<U8_t>::encode(12u) == 0x12u);
    CHECK(fav::Codec_bcd<U16_t>::encode(1234u) == 0x1234u);
    CHECK(fav::Codec_bcd<U32_t>::encode(12345678u) == 0x12345678u);

#if INTPTR_MAX == INT64_MAX //Check for 64 bit platform

    CHECK(fav::Codec_bcd<U64_t>::decode(0x1122334455667788ull) == 1122334455667788ull);
    CHECK(fav::Codec_bcd<U64_t>::encode(1122334455667788ull) == 0x1122334455667788ull);

#endif
}



#endif
