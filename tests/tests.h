#ifdef _MSC_VER
#pragma once
#endif

#ifndef TESTS_H
#define TESTS_H

#ifndef NDEBUG //Debug mode
//Enable tests
#define DOCTEST_CONFIG_IMPLEMENT
#pragma message("Info: All tests is enabled. To disable tests use Release mode.")
#define DOCTEST_RUN doctest_run();
#else
//Disable tests and remove from binary
#define DOCTEST_CONFIG_DISABLE
#pragma message("Info: All tests is disabled. To enable tests use Debug mode.")
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
    context.setOption("no-intro", true); //Print doctest version.
    //context.setOption("duration", true); //Print name and test time
    //context.setOption("success", true); //Print test details
    context.setOption("no-path-filenames", true);
    context.setOption("no-breaks", true); // don't break in the debugger when assertions fail
    context.setOption("no-debug-output", true); //Disables output in the debug console when a debugger is attached
    //context.setOption("out", "doctest_out.txt"); //Output to file.

    context.run(); //int res = context.run(); //Get test status.
}
#endif



/** User includes */
#include "include/bits.h"



//***********************************************************************/
//TEST SECTION
//***********************************************************************/



// TEST_SUITE("Some test" * doctest::description("all tests will have this"))
TEST_SUITE("Bitnum<Value_t>")
{
    using Value_t = std::uint8_t;
    using Bp_t = Bitparams<Value_t>;
    using Bn_t = Bitnum<Value_t>;
    using Bo_t = Bitops<Value_t>;

    TEST_CASE("reverse(bitnum)")
    {
        CHECK(Bn_t::reverse(Bp_t::NLSB) == Bp_t::NMSB);
        CHECK(Bn_t::reverse(Bp_t::NMSB) == Bp_t::NLSB);
    }
    TEST_CASE("clamp(bitnum)")
    {
        CHECK(Bn_t::clamp(Bp_t::NLSB) == Bp_t::NLSB);
        CHECK(Bn_t::clamp(Bp_t::NMSB) == Bp_t::NMSB);
        CHECK(Bn_t::clamp(Bp_t::NMSB + 1) == Bp_t::NMSB);
    }

    TEST_CASE("advance(bitnum)")
    {
        CHECK(Bn_t::advance(Bp_t::NLSB) == Bp_t::NLSB);
        CHECK(Bn_t::advance(Bp_t::NMSB) == Bp_t::NMSB);
        CHECK(Bn_t::advance(Bp_t::NMSB + 1) == Bp_t::NLSB);
    }

    TEST_CASE("is_valid(bitnum)")
    {
        CHECK(Bn_t::is_valid(Bp_t::NLSB) == true);
        CHECK(Bn_t::is_valid(Bp_t::NMSB) == true);
        CHECK(Bn_t::is_valid(Bp_t::NMSB + 1) == false);
    }

    TEST_CASE("is_invalid(bitnum)")
    {
        CHECK(Bn_t::is_invalid(Bp_t::NLSB) == false);
        CHECK(Bn_t::is_invalid(Bp_t::NMSB) == false);
        CHECK(Bn_t::is_invalid(Bp_t::NMSB + 1) == true);
    }

    TEST_CASE("is_lsb(bitnum)")
    {
        CHECK(Bn_t::is_lsb(Bp_t::NLSB) == true);
        CHECK(Bn_t::is_lsb(Bp_t::NMSB) == false);
    }

    TEST_CASE("is_msb(bitnum)")
    {
        CHECK(Bn_t::is_msb(Bp_t::NLSB) == false);
        CHECK(Bn_t::is_msb(Bp_t::NMSB) == true);
    }

}



TEST_SUITE("Bitops<Value_t>")
{
    using Value_t = std::uint8_t;
    using Bp_t = Bitparams<Value_t>;
    using Bn_t = Bitnum<Value_t>;
    using Bo_t = Bitops<Value_t>;
    TEST_CASE("msk(bitnum)")
    {
        CHECK(Bo_t::msk(Bp_t::NLSB) == Bp_t::SET_LSB);
        CHECK(Bo_t::msk(Bp_t::NMSB) == Bp_t::SET_MSB);
    }

    TEST_CASE("get(v, bitnum)")
    {
        CHECK(Bo_t::get(Bp_t::SET_LSB, Bp_t::NLSB) == Bp_t::SET_LSB);
        CHECK(Bo_t::get(Bp_t::SET_MSB, Bp_t::NMSB) == Bp_t::SET_MSB);
    }

    TEST_CASE("set(v, bitnum)")
    {
        CHECK(Bo_t::set(Bp_t::CLR_ALL, Bp_t::NLSB) == Bp_t::SET_LSB);
        CHECK(Bo_t::set(Bp_t::CLR_ALL, Bp_t::NMSB) == Bp_t::SET_MSB);
    }

    TEST_CASE("clr(v, bitnum)")
    {
        CHECK(Bo_t::clr(Bp_t::SET_ALL, Bp_t::NLSB) == Bp_t::SET_LSBI);
        CHECK(Bo_t::clr(Bp_t::SET_ALL, Bp_t::NMSB) == Bp_t::SET_MSBI);
    }

    TEST_CASE("tgl(v, bitnum)")
    {
        Value_t v = Bp_t::CLR_ALL;
        v = Bo_t::tgl(v, Bp_t::NLSB); CHECK(v == Bp_t::SET_LSB);
        v = Bo_t::tgl(v, Bp_t::NLSB); CHECK(v == Bp_t::CLR_ALL);
        v = Bo_t::tgl(v, Bp_t::NMSB); CHECK(v == Bp_t::SET_MSB);
        v = Bo_t::tgl(v, Bp_t::NMSB); CHECK(v == Bp_t::CLR_ALL);
    }

    TEST_CASE("is_set(v, bitnum)")
    {
        CHECK(Bo_t::is_set(Bp_t::SET_LSB, Bp_t::NLSB) == true);
        CHECK(Bo_t::is_set(Bp_t::SET_MSB, Bp_t::NMSB) == true);
    }

    // value = 0,
    // set msb to 1,
    // 0b10000000 result,
    // test msb state = 1,
    // 0b00000000 result,
    // set msb to 0,
    // test msb state = 0.
    TEST_CASE("getst(bitnum, state), setst(bitnum, state)")
    {
        Value_t v = Bp_t::CLR_ALL;
        v = Bo_t::stset(v, Bp_t::NMSB, Bp_t::VAL_1);
        CHECK(Bo_t::stget(v, Bp_t::NMSB) == Bp_t::VAL_1);
        v = Bo_t::stset(v, Bp_t::NMSB, Bp_t::VAL_0);
        CHECK(Bo_t::stget(v, Bp_t::NMSB) == Bp_t::VAL_0);
    }

    // 0b00000001 value = set lsb,
    // rotate right by 1,
    // 0b10000000 result,
    // test lsb = clear, msb = set.
    // rotate left by 1,
    // 0b00000001 result,
    // test lsb = set, msb = clear.
    TEST_CASE("rol(v, bitnum), ror(v, bitnum)")
    {
        Value_t v = Bp_t::SET_LSB;
        v = Bo_t::ror(v, 1u);
        CHECK(Bo_t::is_clrlsb(v) == true);
        CHECK(Bo_t::is_setmsb(v) == true);
        v = Bo_t::rol(v, 1u);
        CHECK(Bo_t::is_setlsb(v) == true);
        CHECK(Bo_t::is_clrmsb(v) == true);
    }

    // 0b00000001 value = set lsb,
    // copy lsb = msb,
    // 0b10000001 result,
    // test lbs and msb is set.
    TEST_CASE("copy(v, bitnum_src, bitnum_tgt)")
    {
        Value_t v = Bp_t::SET_LSB;
        CHECK(Bo_t::copy(v, Bp_t::NLSB, Bp_t::NMSB) == (Bp_t::SET_MSB | Bp_t::SET_LSB));
    }
    
    // 0b00000001 value = set lsb,
    // swap lsb <-> msb,
    // 0b10000000 result,
    // test lsb = clear, msb = set.
    TEST_CASE("swap(v, bitnum_a, bitnum_b)")
    {
        Value_t v = Bp_t::SET_LSB;
        v = Bo_t::swap(v, Bp_t::NLSB, Bp_t::NMSB);
        CHECK(Bo_t::is_setmsb(v) == true);
        CHECK(Bo_t::is_clrlsb(v) == true);
    }

}

TEST_SUITE("Bitmask<Value_t>")
{
    using Value_t = std::uint8_t;
    using Bp_t = Bitparams<Value_t>;
    using Bo_t = Bitops<Value_t>;
    using Bm_t = Bitmask<Value_t>;

    TEST_CASE("get(v, mask)")
    {
        CHECK(Bm_t::get(0b10101010, 0b00111100) == 0b00101000);
    }

    TEST_CASE("set(v, mask)")
    {
        CHECK(Bm_t::set(0b10101010, 0b00111100) == 0b10111110);
    }

    TEST_CASE("clr(v, mask)")
    {
        CHECK(Bm_t::clr(0b10101010, 0b00111100) == 0b10000010);
    }

    TEST_CASE("tgl(v, mask)")
    {
        CHECK(Bm_t::tgl(0b10101010, 0b00111100) == 0b10010110);
    }

    TEST_CASE("is_set(v, mask)")
    {
        CHECK(Bm_t::is_setall(0b10111110, 0b00111100) == true);
        CHECK(Bm_t::is_setall(0b10110110, 0b00111100) == false);
        CHECK(Bm_t::is_setany(0b10000010, 0b00111100) == false);
        CHECK(Bm_t::is_setany(0b10000110, 0b00111100) == true);

        CHECK(Bm_t::is_clrall(0b10000010, 0b00111100) == true);
        CHECK(Bm_t::is_clrall(0b10000110, 0b00111100) == false);
        CHECK(Bm_t::is_clrany(0b10111110, 0b00111100) == false);
        CHECK(Bm_t::is_clrany(0b10111010, 0b00111100) == true);

        CHECK(Bo_t::is_setall(Bp_t::SET_ALL) == true);
        CHECK(Bo_t::is_setall(Bp_t::SET_LSBI) == false);
        CHECK(Bo_t::is_setany(Bp_t::CLR_ALL) == false);
        CHECK(Bo_t::is_setany(Bp_t::SET_LSB) == true);
               
        CHECK(Bo_t::is_clrall(Bp_t::CLR_ALL) == true);
        CHECK(Bo_t::is_clrall(Bp_t::SET_LSB) == false);
        CHECK(Bo_t::is_clrany(Bp_t::SET_ALL) == false);
        CHECK(Bo_t::is_clrany(Bp_t::SET_LSBI) == true);

    }

    TEST_SUITE("Bitfill<Value_t>")
    {
        using Value_t = std::uint8_t;
        using Bp_t = Bitparams<Value_t>;
        using Bo_t = Bitops<Value_t>;
        using Bm_t = Bitmask<Value_t>;
        using Bf_t = Bitfill<Value_t>;

        TEST_CASE("tr0(numbits)")
        {
            CHECK(Bf_t::tr0(0) == 0b11111111);
            CHECK(Bf_t::tr0(8) == 0b00000000);
            CHECK(Bf_t::tr0(3) == 0b11111000);
        }

        TEST_CASE("tr1(numbits)")
        {
            CHECK(Bf_t::tr1(0) == 0b00000000);
            CHECK(Bf_t::tr1(8) == 0b11111111);
            CHECK(Bf_t::tr1(3) == 0b00000111);
        }

        TEST_CASE("ld0(numbits)")
        {
            CHECK(Bf_t::ld0(0) == 0b11111111);
            CHECK(Bf_t::ld0(8) == 0b00000000);
            CHECK(Bf_t::ld0(3) == 0b00011111);
        }

        TEST_CASE("ld1(numbits)")
        {
            CHECK(Bf_t::ld1(0) == 0b00000000);
            CHECK(Bf_t::ld1(8) == 0b11111111);
            CHECK(Bf_t::ld1(3) == 0b11100000);
        }

        TEST_CASE("rng0(from_msb, to_lsb)")
        {
            CHECK(Bf_t::rng0(0, 0) == 0b11111110);
            CHECK(Bf_t::rng0(7, 7) == 0b01111111);
            CHECK(Bf_t::rng0(7, 0) == 0b00000000);
            CHECK(Bf_t::rng0(3, 3) == 0b11110111);
            CHECK(Bf_t::rng0(6, 1) == 0b10000001);
            CHECK(Bf_t::rng0(1, 6) == 0b11111111);
            CHECK(Bf_t::rng0(3, 4) == 0b11111111);
        }

        TEST_CASE("rng1(from_msb, to_lsb)")
        {
            CHECK(Bf_t::rng1(0, 0) == 0b00000001);
            CHECK(Bf_t::rng1(7, 7) == 0b10000000);
            CHECK(Bf_t::rng1(7, 0) == 0b11111111);
            CHECK(Bf_t::rng1(3, 3) == 0b00001000);
            CHECK(Bf_t::rng1(6, 1) == 0b01111110);
            CHECK(Bf_t::rng1(1, 6) == 0b00000000);
            CHECK(Bf_t::rng1(3, 4) == 0b00000000);
        }

    }

    TEST_SUITE("Bitspec<Value_t>")
    {
        using Value_t = std::uint8_t;
        using Bp_t = Bitparams<Value_t>;
        using Bs_t = Bitspec<Value_t>;

        TEST_CASE("is_pow2(Value_t v)")
        {
            CHECK(Bs_t::is_pow2(0b00000000) == true);
            CHECK(Bs_t::is_pow2(0b00000001) == true);
            CHECK(Bs_t::is_pow2(0b10000000) == true);
            CHECK(Bs_t::is_pow2(0b11111111) == false);
            CHECK(Bs_t::is_pow2(0b10000001) == false);
        }

        TEST_CASE("mask(Value_t v)")
        {
            CHECK(Bs_t::mask(0b00000000) == 0b00000000);
            CHECK(Bs_t::mask(0b00000001) == 0b00000001);
            CHECK(Bs_t::mask(0b10000000) == 0b11111111);
            CHECK(Bs_t::mask(0b11111111) == 0b11111111);
            CHECK(Bs_t::mask(0b01010101) == 0b01111111);
        }

        TEST_CASE("swap(Value_t v)")
        {
            CHECK(Bitspec<std::uint8_t>::swap(0x12u) == 0x21u);
            CHECK(Bitspec<std::uint16_t>::swap(0x1234u) == 0x3412u);
            CHECK(Bitspec<std::uint32_t>::swap(0x12345678u) == 0x78563412u);
            CHECK(Bitspec<std::uint64_t>::swap(0x1122334455667788ull) == 0x8877665544332211ull);
        }

        TEST_CASE("reverse(Value_t v)")
        {
            CHECK(Bitspec<std::uint8_t>::reverse(0x5Fu) == 0xFAu);
            CHECK(Bitspec<std::uint16_t>::reverse(0x55FFu) == 0xFFAAu);
            CHECK(Bitspec<std::uint32_t>::reverse(0x55330F00u) == 0x00F0CCAAu);
            CHECK(Bitspec<std::uint64_t>::reverse(0x55330F00FF000000ull) == 0x000000FF00F0CCAAull);
        }

        TEST_CASE("pow2hi(Value_t v)")
        {
            CHECK(Bs_t::pow2hi(0b00000000) == 0b00000000);
            CHECK(Bs_t::pow2hi(0b00000001) == 0b00000001);
            CHECK(Bs_t::pow2hi(0b10000000) == 0b10000000);
            CHECK(Bs_t::pow2hi(0b11111111) == 0b00000000);
            CHECK(Bs_t::pow2hi(0b01010101) == 0b10000000);
        }

        TEST_CASE("pow2lo(Value_t v)")
        {
            CHECK(Bs_t::pow2lo(0b00000000) == 0b00000000);
            CHECK(Bs_t::pow2lo(0b00000001) == 0b00000001);
            CHECK(Bs_t::pow2lo(0b10000000) == 0b10000000);
            CHECK(Bs_t::pow2lo(0b11111111) == 0b10000000);
            CHECK(Bs_t::pow2lo(0b01010101) == 0b01000000);
        }

        TEST_CASE("cnt1(Value_t v)")
        {
            CHECK(Bs_t::cnt1(0b00000000) == 0);
            CHECK(Bs_t::cnt1(0b11111111) == 8);
            CHECK(Bs_t::cnt1(0b10101010) == 4);
        }

        TEST_CASE("cnt0(Value_t v)")
        {
            CHECK(Bs_t::cnt0(0b00000000) == 8);
            CHECK(Bs_t::cnt0(0b11111111) == 0);
            CHECK(Bs_t::cnt0(0b10101010) == 4);
        }

        TEST_CASE("cnttr0(Value_t v)")
        {
            CHECK(Bs_t::cnttr0(0b00000000) == 8);
            CHECK(Bs_t::cnttr0(0b00000001) == 0);
            CHECK(Bs_t::cnttr0(0b10000000) == 7);
            CHECK(Bs_t::cnttr0(0b11111111) == 0);
            CHECK(Bs_t::cnttr0(0b00101000) == 3);
        }

        TEST_CASE("cntld0(Value_t v)")
        {
            CHECK(Bs_t::cntld0(0b00000000) == 8);
            CHECK(Bs_t::cntld0(0b00000001) == 7);
            CHECK(Bs_t::cntld0(0b10000000) == 0);
            CHECK(Bs_t::cntld0(0b11111111) == 0);
            CHECK(Bs_t::cntld0(0b00101000) == 2);
        }

        TEST_CASE("cnttr1(Value_t v)")
        {
            CHECK(Bs_t::cnttr1(0b00000000) == 0);
            CHECK(Bs_t::cnttr1(0b00000001) == 1);
            CHECK(Bs_t::cnttr1(0b10000000) == 0);
            CHECK(Bs_t::cnttr1(0b11111111) == 8);
            CHECK(Bs_t::cnttr1(0b11101011) == 2);
        }

        TEST_CASE("cntld1(Value_t v)")
        {
            CHECK(Bs_t::cntld1(0b00000000) == 0);
            CHECK(Bs_t::cntld1(0b00000001) == 0);
            CHECK(Bs_t::cntld1(0b10000000) == 1);
            CHECK(Bs_t::cntld1(0b11111111) == 8);
            CHECK(Bs_t::cntld1(0b11101011) == 3);
        }

        TEST_CASE("fndtr1(Value_t v)")
        {
            CHECK(Bs_t::fndtr1(0b00000000) == 8);
            CHECK(Bs_t::fndtr1(0b00000001) == 0);
            CHECK(Bs_t::fndtr1(0b10000000) == 7);
            CHECK(Bs_t::fndtr1(0b11111111) == 0);
            CHECK(Bs_t::fndtr1(0b00101000) == 3);
        }

        TEST_CASE("fndld1(Value_t v)")
        {
            CHECK(Bs_t::fndld1(0b00000000) == 8);
            CHECK(Bs_t::fndld1(0b00000001) == 0);
            CHECK(Bs_t::fndld1(0b10000000) == 7);
            CHECK(Bs_t::fndld1(0b11111111) == 7);
            CHECK(Bs_t::fndld1(0b00101000) == 5);
        }

        TEST_CASE("fndtr0(Value_t v)")
        {
            CHECK(Bs_t::fndtr0(0b00000000) == 0);
            CHECK(Bs_t::fndtr0(0b00000001) == 1);
            CHECK(Bs_t::fndtr0(0b10000000) == 0);
            CHECK(Bs_t::fndtr0(0b11111111) == 8);
            CHECK(Bs_t::fndtr0(0b11010111) == 3);
        }

        TEST_CASE("fndld0(Value_t v)")
        {
            CHECK(Bs_t::fndld0(0b00000000) == 7);
            CHECK(Bs_t::fndld0(0b00000001) == 7);
            CHECK(Bs_t::fndld0(0b10000000) == 6);
            CHECK(Bs_t::fndld0(0b11111111) == 8);
            CHECK(Bs_t::fndld0(0b11010111) == 5);
        }
    }

}














//***********************************************************************/



//Change to 0 for tests.
#if 0

TEST_CASE("Testing Codec_4bit")
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



#endif //if 0



#endif
