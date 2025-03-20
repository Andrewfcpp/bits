#ifdef _MSC_VER
#pragma once
#endif

#ifndef BITS_H
#define BITS_H

#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "macro_compiler_use_inline.h"



namespace //private
{
    template<typename T>
    constexpr bool IS_TYPE_VALID = std::is_integral<T>::value && !std::is_same<T, bool>::value;
}

// Constant bit params.
template<typename T = std::uint32_t>
class Bitparams
{
public:
    static_assert(IS_TYPE_VALID<T>, "Error! Wrong type.");
    using Value_t = T;
    using Size_t = std::size_t;

    static constexpr Value_t VAL_0 = static_cast<Value_t>(0);
    static constexpr Value_t VAL_1 = static_cast<Value_t>(1);

    // Type size in bytes.
    // Example: uint32 = 4.
    static constexpr Size_t NBYTES = sizeof(Value_t);

    static constexpr bool IS_NBYTES_1 = (NBYTES == 1);
    static constexpr bool IS_NBYTES_2 = (NBYTES == 2);
    static constexpr bool IS_NBYTES_4 = (NBYTES == 4);
    static constexpr bool IS_NBYTES_8 = (NBYTES == 8);

    // Type size in bits.
    // Example: uint32 = 32.
    static constexpr Size_t NBITS = NBYTES * 8;

    // Less significant bit number.
    // Always = 0.
    static constexpr Size_t NLSB = 0;

    // Most significant bit number.
    // Example: uint32 = 31.
    static constexpr Size_t NMSB = NBITS - 1;

    // Number of bits.
    static constexpr Size_t NBITS_8  = 8;
    static constexpr Size_t NBITS_16 = 16;
    static constexpr Size_t NBITS_32 = 32;
    static constexpr Size_t NBITS_64 = 64;

    // Is Number of bits equal.
    static constexpr bool IS_NBITSEQ_8  = (NBITS == NBITS_8);
    static constexpr bool IS_NBITSEQ_16 = (NBITS == NBITS_16);
    static constexpr bool IS_NBITSEQ_32 = (NBITS == NBITS_32);
    static constexpr bool IS_NBITSEQ_64 = (NBITS == NBITS_64);

    // Is Number of bits greater.
    static constexpr bool IS_NBITSGR_8  = (NBITS > NBITS_8);
    static constexpr bool IS_NBITSGR_16 = (NBITS > NBITS_16);
    static constexpr bool IS_NBITSGR_32 = (NBITS > NBITS_32);

    // Is Number of bits less.
    static constexpr bool IS_NBITSLE_16 = (NBITS < NBITS_16);
    static constexpr bool IS_NBITSLE_32 = (NBITS < NBITS_32);
    static constexpr bool IS_NBITSLE_64 = (NBITS < NBITS_64);

    // Mask for bit numbers.
    // Example: uint8 = 0b00000111, 0 - 7 bit range.
    static constexpr Size_t MSK_NBITS = NMSB;

    // Value of all bits clear.
    // Always = 0.
    static constexpr Value_t CLR_ALL = static_cast<Value_t>(0);

    // Value of all bits set.
    // Example: uint8 = 0b11111111
    static constexpr Value_t SET_ALL = static_cast<Value_t>(~CLR_ALL);

    // Value of less significant bit set.
    // Always = 1.
    static constexpr Value_t SET_LSB = static_cast<Value_t>(1);

    // Inverted value of less significant bit set.
    // Example: uint8 = 0b11111110
    static constexpr Value_t SET_LSBI = static_cast<Value_t>(~SET_LSB);

    // Value of most significant bit set.
    // Example: uint8 = 0b10000000
    static constexpr Value_t SET_MSB = static_cast<Value_t>(SET_LSB << NMSB);

    // Inverted value of most significant bit set.
    // Example: uint8 = 0b01111111
    static constexpr Value_t SET_MSBI = static_cast<Value_t>(~SET_MSB);

};



//***********************************************************************/

// Bit number utils.
template<typename T = std::uint32_t>
class Bitnum
{
public:
    static_assert(IS_TYPE_VALID<T>, "Error! Wrong type.");
    using Value_t = T;
    using Size_t = std::size_t;
    using Bp_t = Bitparams<Value_t>;

    // Get bit number difference.
    // Example: uint8,
    // nbitsdiff(3) == 5, (8bits - 3)
    use_inline static constexpr Size_t nbitsdiff(Size_t bitnum) noexcept { return Bp_t::NBITS - bitnum; }

    // Get reversed bit number. 
    // Example: uint8,
    // reverse(0) == 7.
    use_inline static constexpr Size_t reverse(Size_t bitnum) noexcept { return Bp_t::NMSB - bitnum; }

    // Clamp bitnum.
    // Example: uint8,
    // if bitnum > 7, return 7, else bitnum.
    use_inline static constexpr Size_t clamp(Size_t bitnum) noexcept { return bitnum > Bp_t::NMSB ? Bp_t::NMSB : bitnum; }

    // Advance, bitnum % NUM_BITS.
    // Example: uint8,
    // advance(12) == 4, (12 % 8).
    use_inline static constexpr Size_t advance(Size_t bitnum) noexcept { return bitnum & Bp_t::MSK_NBITS; }

    use_inline static constexpr bool is_valid(Size_t bitnum) noexcept { return bitnum < Bp_t::NBITS; }

    use_inline static constexpr bool is_invalid(Size_t bitnum) noexcept { return bitnum >= Bp_t::NBITS; }

    use_inline static constexpr bool is_lsb(Size_t bitnum) noexcept { return bitnum == Bp_t::NLSB; }

    use_inline static constexpr bool is_msb(Size_t bitnum) noexcept { return bitnum == Bp_t::NMSB; }

};



//***********************************************************************/

//Single bit operations.
template<typename T = std::uint32_t>
class Bitops
{
public:
    static_assert(IS_TYPE_VALID<T>, "Error! Wrong type.");
    using Value_t = T;
    using Size_t = std::size_t;
    using Bp_t = Bitparams<Value_t>;

    static constexpr Value_t VAL_0 = static_cast<Value_t>(0);
    static constexpr Value_t VAL_1 = static_cast<Value_t>(1);

    // Get bit mask.
    // Example: uint8,
    // msk(3) == 0b00001000.
    use_inline static constexpr Value_t msk(Size_t bitnum) noexcept { return VAL_1 << bitnum; }

    // Get inverted bit mask.
    // Example: uint8,
    // mski(3) == 0b11110111.
    use_inline static constexpr Value_t mski(Size_t bitnum) noexcept { return ~msk(bitnum); }

    // Get trailing bits mask.
    // Example: uint8,
    // msktr(3) == 0b00000111.
    use_inline static constexpr Value_t msktr(Size_t bitnum) noexcept { return msk(bitnum) - 1; }

    // Get leading bits mask.
    // Example: uint8,
    // mskld(3) == 0b11111000.
    use_inline static constexpr Value_t mskld(Size_t bitnum) noexcept { return ~msktr(bitnum); }

    // Get bit value, or 0.
    // Example: uint8,
    // get(0b10101010, 3) == 0b00001000.
    use_inline static constexpr Value_t get(Value_t v, Size_t bitnum) noexcept { return v & msk(bitnum); }

    // Get bit value inverted.
    // Example: uint8,
    // geti(0b10101010, 3) == 0b11110111.
    use_inline static constexpr Value_t geti(Value_t v, Size_t bitnum) noexcept { return ~get(v, bitnum); }

    // Set bit in value.
    // Example: uint8,
    // set(0b01010101, 3) == 0b01011101.
    use_inline static constexpr Value_t set(Value_t v, Size_t bitnum) noexcept { return v | msk(bitnum); }

    // Clear bit in value.
    // Example: uint8,
    // clr(0b10101010, 3) == 0b10100010
    use_inline static constexpr Value_t clr(Value_t v, Size_t bitnum) noexcept { return v & mski(bitnum); }

    // Toggle bit in value.
    // Example: uint8,
    // tgl(0b10101010, 3) == 0b10100010.
    // tgl(0b10100010, 3) == 0b10101010.
    use_inline static constexpr Value_t tgl(Value_t v, Size_t bitnum) noexcept { return v ^ msk(bitnum); }

    //***********************************************************************/

    // Test if set.
    use_inline static constexpr bool is_set(Value_t v, Size_t bitnum) noexcept { return get(v, bitnum) != VAL_0; }
    use_inline static constexpr bool is_setlsb(Value_t v) noexcept { return get(v, Bp_t::NLSB) != VAL_0; }
    use_inline static constexpr bool is_setmsb(Value_t v) noexcept { return get(v, Bp_t::NMSB) != VAL_0; }
    use_inline static constexpr bool is_setall(Value_t v) noexcept { return v == Bp_t::SET_ALL; }
    use_inline static constexpr bool is_setany(Value_t v) noexcept { return v != Bp_t::CLR_ALL; }

    // Test if clear.
    use_inline static constexpr bool is_clr(Value_t v, Size_t bitnum) noexcept { return get(v, bitnum) == VAL_0; }
    use_inline static constexpr bool is_clrlsb(Value_t v) noexcept { return get(v, Bp_t::NLSB) == VAL_0; }
    use_inline static constexpr bool is_clrmsb(Value_t v) noexcept { return get(v, Bp_t::NMSB) == VAL_0; }
    use_inline static constexpr bool is_clrall(Value_t v) noexcept { return v == Bp_t::CLR_ALL; }
    use_inline static constexpr bool is_clrany(Value_t v) noexcept { return v < Bp_t::SET_ALL; }

    //***********************************************************************/

    // Clamp value to state 0 or 1. if(x != 0) return 1, else return 0.
    use_inline static constexpr Value_t tost(Value_t v) noexcept { return static_cast<Value_t>(v != VAL_0); }

    // Get bit state 0 or 1.
    // Example: uint8,
    // stget(0b10101010, 3) == 1.
    use_inline static constexpr Value_t stget(Value_t v, Size_t bitnum) noexcept { return tost(get(v, bitnum)); }

    // Set bit to state 0 or 1. State > 0 = 1.
    // Example: uint8,
    // stset(0b10101010, 3, 0) == 0b10100010.
    use_inline static constexpr Value_t stset(Value_t v, Size_t bitnum, Value_t state) noexcept { return state == VAL_0 ? clr(v, bitnum) : set(v, bitnum); }

    //***********************************************************************/

    // Shift left, same as bitwise operator <<
    // Example: uint8,
    // shl(0b00011000, 2) == 0b01100000.
    use_inline static constexpr Value_t shl(Value_t v, Size_t numbits) noexcept { return v << numbits; }

    // Shift right, same as bitwise operator >>
    // Example: uint8,
    // shl(0b00011000, 2) == 0b00000110.
    use_inline static constexpr Value_t shr(Value_t v, Size_t numbits) noexcept { return v >> numbits; }

    // Rotate left.
    // Example: uint8,
    // rol(0b11000010, 2) == 0b00001011.
    use_inline static constexpr Value_t rol(Value_t v, Size_t numbits) noexcept { return (v << numbits) | (v >> (Bp_t::NBITS - numbits)); }

    // Rotate right.
    // Example: uint8,
    // ror(0b11000010, 2) == 0b10110000.
    use_inline static constexpr Value_t ror(Value_t v, Size_t numbits) noexcept { return (v >> numbits) | (v << (Bp_t::NBITS - numbits)); }

    // Invert all bits.
    // Example: uint8,
    // inv(0b10101111) == 0b01010000.
    use_inline static constexpr Value_t inv(Value_t v) noexcept { return ~v; }


    //***********************************************************************/
    
    // Copy bit state from source to target.
    /*use_inline*/ static constexpr Value_t copy(Value_t v, Size_t bitnum_src, Size_t bitnum_tgt) noexcept
    {
        Value_t st = stget(v, bitnum_src);
        v = stset(v, bitnum_tgt, st);
        return v;
    }

    // Swap bit state between a and b.
    /*use_inline*/ static constexpr Value_t swap(Value_t v, Size_t bitnum_a, Size_t bitnum_b) noexcept
    {
        Value_t st_a = stget(v, bitnum_a);
        Value_t st_b = stget(v, bitnum_b);
        v = stset(v, bitnum_a, st_b);
        v = stset(v, bitnum_b, st_a);
        return v;
    }

    // Remove bit from value.
    // Example: uint8,
    // remove(0b10101010, 3) == 0b01010010.
    /*use_inline*/ static constexpr Value_t remove(Value_t v, Size_t bitnum) noexcept
    {
        Value_t vtr = msktr(bitnum);
        Value_t vld = ~vtr;
        vtr &= v;
        vld &= v;
        vld >>= 1;
        return vld | vtr;
    }

};



//***********************************************************************/

// Masked bits operations.
template<typename T = std::uint32_t>
class Bitmask
{
public:
    static_assert(IS_TYPE_VALID<T>, "Error! Wrong type.");
    using Value_t = T;
    using Size_t = std::size_t;
    using Bp_t = Bitparams<Value_t>;

    // Return value of masked bits.
    // Example: uint8,
    // get(0b10101010, 0b00111100) == 0b00101000.
    use_inline static constexpr Value_t get(Value_t v, Value_t mask) noexcept { return v & mask; }

    // Return value of masked bits set.
    // Example: uint8,
    // set(0b10101010, 0b00111100) == 0b10111110.
    use_inline static constexpr Value_t set(Value_t v, Value_t mask) noexcept { return v | mask; }

    // Return value of masked bits clear.
    // Example: uint8,
    // clr(0b10101010, 0b00111100) == 0b10000010.
    use_inline static constexpr Value_t clr(Value_t v, Value_t mask) noexcept { return v & (~mask); }

    // Return value of masked bits inverted.
    // Example: uint8,
    // tgl(0b10101010, 0b00111100) == 0b10010110.
    use_inline static constexpr Value_t tgl(Value_t v, Value_t mask) noexcept { return v ^ mask; }

    // Test masked bits.
    use_inline static constexpr bool is_setall(Value_t v, Value_t mask) noexcept { return get(v, mask) == mask; }
    use_inline static constexpr bool is_setany(Value_t v, Value_t mask) noexcept { return get(v, mask) != Bp_t::CLR_ALL; }
    use_inline static constexpr bool is_clrall(Value_t v, Value_t mask) noexcept { return get(v, mask) == Bp_t::CLR_ALL; }
    use_inline static constexpr bool is_clrany(Value_t v, Value_t mask) noexcept { return get(v, mask) < mask; }

};



//***********************************************************************/

//numbits = how many bits to fill.
template<typename T = std::uint32_t>
class Bitfill
{
public:
    static_assert(IS_TYPE_VALID<T>, "Error! Wrong type.");
    using Value_t = T;
    using Size_t = std::size_t;
    using Bp_t = Bitparams<Value_t>;
    using Bn_t = Bitnum<Value_t>;

    // Get trailing bits set to 0.
    // Example: uint8,
    // lsb0(3) == 0b11111000.
    use_inline static constexpr Value_t tr0(Size_t numbits) noexcept { return Bp_t::SET_ALL << numbits; }

    // Get trailing bits set to 1.
    // Example: uint8,
    // lsb1(3) == 0b00000111.
    use_inline static constexpr Value_t tr1(Size_t numbits) noexcept { return ~tr0(numbits); }

    // Get lead bits set to 0.
    // Example: uint8,
    // msb0(3) == 0b00011111.
    use_inline static constexpr Value_t ld0(Size_t numbits) noexcept { return Bp_t::SET_ALL >> numbits; }

    // Get lead bits set to 1.
    // Example: uint8,
    // msb1(3) == 0b11100000.
    use_inline static constexpr Value_t ld1(Size_t numbits) noexcept { return ~ld0(numbits); }

    // Get range of bits set to 0.
    // Example: uint8,
    // range0(6, 1) == 0b10000001.
    use_inline static constexpr Value_t rng0(Size_t from_msb, Size_t to_lsb) noexcept
    {
        from_msb = Bn_t::reverse(from_msb);
        return ld1(from_msb) | tr1(to_lsb);
    }

    // Get range of bits set to 1.
    // Example: uint8,
    // range1(6, 1) == 0b01111110.
    use_inline static constexpr Value_t rng1(Size_t from_msb, Size_t to_lsb) noexcept
    {
        return ~rng0(from_msb, to_lsb);
    }

};



//***********************************************************************/

// Special functions.
template<typename T = std::uint32_t>
class Bitspec
{
public:
    static_assert(IS_TYPE_VALID<T>, "Error! Wrong type.");
    using Value_t = T;
    using Size_t = std::size_t;
    using Bp_t = Bitparams<Value_t>;

    static constexpr Value_t VAL_0 = static_cast<Value_t>(0);
    static constexpr Value_t VAL_1 = static_cast<Value_t>(1);

    static constexpr Size_t NBITS = sizeof(Value_t) * 8;
    static constexpr Size_t NMSB = NBITS - 1;

    static constexpr Value_t CLR_ALL = static_cast<Value_t>(0);
    static constexpr Value_t SET_ALL = static_cast<Value_t>(~CLR_ALL);

    // Return true if value is power of 2.
    use_inline static constexpr bool is_pow2(Value_t v) noexcept
    {
        return (v & (v - VAL_1)) == VAL_0;
    }

    // Closest mask for value.
    // Example: uint8,
    // 0b01010101 value,
    // 0b01111111 return.
    // mask(0b01010101) == 0b01111111.
    use_inline static constexpr Value_t mask(Value_t v) noexcept
    {
        v |= (v >> 1);
        v |= (v >> 2);
        v |= (v >> 4);
        if constexpr (NBITS > 8)  v |= (v >> 8);
        if constexpr (NBITS > 16) v |= (v >> 16);
        if constexpr (NBITS > 32) v |= (v >> 32);
        return v;
    }

    // Swap byte order.
    // uint8 swapped by 4 bits (nibbles).
    // Example: uint8, swap(0x1Au) == 0xA1u.
    // Example: uint32, swap(0x12345678u) == 0x78563412u.
    use_inline static constexpr Value_t swap(Value_t v) noexcept
    {
        constexpr Value_t arr[4] = {
            static_cast<Value_t>(0xFF00FF00FF00FF00ull), static_cast<Value_t>(0x00FF00FF00FF00FFull),
            static_cast<Value_t>(0xFFFF0000FFFF0000ull), static_cast<Value_t>(0x0000FFFF0000FFFFull)
        };

        if constexpr (NBITS == 8)  v = (v << 4) | (v >> 4);

        if constexpr (NBITS == 16) v = (v << 8) | (v >> 8);

        if constexpr (NBITS == 32)
        {
            v = ((v << 8) & arr[0]) | ((v >> 8) & arr[1]);
            v = (v << 16) | (v >> 16);
        }

        if constexpr (NBITS == 64)
        {
            v = ((v << 8) & arr[0]) | ((v >> 8) & arr[1]);
            v = ((v << 16) & arr[2]) | ((v >> 16) & arr[3]);
            v = (v << 32) | (v >> 32);
        }

        return v;
    }

    // Reverse bits.
    // Example: uint8,
    // reverse(0b11110101) == 0b10101111.
    use_inline static constexpr Value_t reverse(Value_t v) noexcept
    {
        constexpr Value_t arr[12] = {
            static_cast<Value_t>(0x5555555555555555ull), static_cast<Value_t>(0xAAAAAAAAAAAAAAAAull),
            static_cast<Value_t>(0x3333333333333333ull), static_cast<Value_t>(0xCCCCCCCCCCCCCCCCull),
            static_cast<Value_t>(0x0F0F0F0F0F0F0F0Full), static_cast<Value_t>(0xF0F0F0F0F0F0F0F0ull),
            static_cast<Value_t>(0x00FF00FF00FF00FFull), static_cast<Value_t>(0xFF00FF00FF00FF00ull),
            static_cast<Value_t>(0x0000FFFF0000FFFFull), static_cast<Value_t>(0xFFFF0000FFFF0000ull),
            static_cast<Value_t>(0x00000000FFFFFFFFull), static_cast<Value_t>(0xFFFFFFFF00000000ull)
        };

        v = ((v >> 1) & arr[0]) | ((v << 1) & arr[1]);
        v = ((v >> 2) & arr[2]) | ((v << 2) & arr[3]);
        v = ((v >> 4) & arr[4]) | ((v << 4) & arr[5]);
        if constexpr (NBITS > 8)  v = ((v >> 8) & arr[6]) | ((v << 8) & arr[7]);
        if constexpr (NBITS > 16) v = ((v >> 16) & arr[8]) | ((v << 16) & arr[9]);
        if constexpr (NBITS > 32) v = ((v >> 32) & arr[10]) | ((v << 32) & arr[11]);
        return v;
    }

    // Round to highest power of 2.
    // pow2hi(0b01010101) == 0b10000000.
    use_inline static constexpr Value_t pow2hi(Value_t v) noexcept
    {
        --v;
        v = mask(v);
        return ++v;
    }

    // Round to lowest power of 2.
    // pow2lo(0b01010101) == 0b01000000.
    use_inline static constexpr Value_t pow2lo(Value_t v) noexcept
    {
        v = mask(v);
        return v - (v >> 1);
    }

    //***********************************************************************/

    // Count number of ones, known as population count. 
    // Example: uint8,
    // cnt1(0b00000000) == 0.
    // cnt1(0b10101010) == 4.
    // cnt1(0b11111111) == 8.
    use_inline static constexpr Size_t cnt1(Value_t v) noexcept
    {
        constexpr Value_t arr[4] = {
            static_cast<Value_t>(0x5555555555555555ull),
            static_cast<Value_t>(0x3333333333333333ull),
            static_cast<Value_t>(0x0F0F0F0F0F0F0F0Full),
            static_cast<Value_t>(0x0101010101010101ull)
        };

        v -= (v >> 1) & arr[0];
        v = ((v >> 2) & arr[1]) + (v & arr[1]);
        v = ((((v >> 4) + v) & arr[2]) * arr[3]);
        if constexpr (NBITS == 16) v >>= 8;
        if constexpr (NBITS == 32) v >>= 24;
        if constexpr (NBITS == 64) v >>= 56;
        return static_cast<Size_t>(v);
    }

    // Count number of zeros.
    // Example: uint8,
    // cnt0(0b00000000) == 8.
    // cnt0(0b10101010) == 4.
    // cnt0(0b11111111) == 0.
    use_inline static constexpr Size_t cnt0(Value_t v) noexcept
    {
        return NBITS - cnt1(v);
    }

    // Count number of trailing zeros.
    // Example: uint8,
    // cnttr0(0b00000000) == 8.
    // cnttr0(0b00101000) == 3.
    // cnttr0(0b11111111) == 0.
    use_inline static constexpr Size_t cnttr0(Value_t v) noexcept
    {
        constexpr Value_t arr[6] = {
            static_cast<Value_t>(0x00000000FFFFFFFFull),
            static_cast<Value_t>(0x0000FFFF0000FFFFull),
            static_cast<Value_t>(0x00FF00FF00FF00FFull),
            static_cast<Value_t>(0x0F0F0F0F0F0F0F0Full),
            static_cast<Value_t>(0x3333333333333333ull),
            static_cast<Value_t>(0x5555555555555555ull)
        };

        Size_t c = NBITS;
        v &= (0u - v);
        if (v) { --c; }
        if constexpr (NBITS > 32) if (v & arr[0]) { c -= 32u; }
        if constexpr (NBITS > 16) if (v & arr[1]) { c -= 16u; }
        if constexpr (NBITS > 8)  if (v & arr[2]) { c -= 8u; }
        if (v & arr[3]) { c -= 4u; }
        if (v & arr[4]) { c -= 2u; }
        if (v & arr[5]) { c -= 1u; }
        return c;
    }

    // Count number of leading zeros.
    // Example: uint8,
    // cntld0(0b00000000) == 8.
    // cntld0(0b00001100) == 4.
    // cntld0(0b11111111) == 0.
    use_inline static constexpr Size_t cntld0(Value_t v) noexcept
    {
        v = mask(v);
        return cnt1(~v);
    }

    // Count number of trailing ones.
    // Example: uint8,
    // cnttr1(0b11110011) == 2.
    use_inline static constexpr Size_t cnttr1(Value_t v) noexcept
    {
        return cnttr0(~v);
    }

    // Count number of leading ones.
    // Example: uint8,
    // cntld1(0b11110011) == 4.
    use_inline static constexpr Size_t cntld1(Value_t v) noexcept
    {
        return cntld0(~v);
    }

    //***********************************************************************/

    // Find first trail bit that is set to 1.
    // Example: uint8,
    // findtr1(0b00000000) == 8. Bit not found, return == NUM_BITS.
    // findtr1(0b00000001) == 0.
    // findtr1(0b00101000) == 3.
    // findtr1(0b11111111) == 0.
    use_inline static constexpr Size_t fndtr1(Value_t v) noexcept
    {
        return cnttr0(v);
    }

    // Find first lead bit that is set to 1.
    // Example: uint8,
    // findld1(0b00000000) == 8. Bit not found, return == NUM_BITS.
    // findld1(0b00000001) == 0.
    // findld1(0b00101000) == 5.
    // findld1(0b11111111) == 7.
    use_inline static constexpr Size_t fndld1(Value_t v) noexcept
    {
        return v == CLR_ALL ? NBITS : NMSB - cntld0(v);
    }

    // Find first trail bit that is set to 0.
    // Example: uint8,
    // findtr0(0b11111111) == 8. Bit not found, return == NUM_BITS.
    // findtr0(0b00000000) == 0.
    // findtr0(0b11010111) == 3.
    use_inline static constexpr Size_t fndtr0(Value_t v) noexcept
    {
        return cnttr0(~v);
    }

    // Find first lead bit that is set to 0.
    // Example: uint8,
    // findld0(0b11111111) == 8. Bit not found, return == NUM_BITS.
    // findld0(0b00000000) == 7.
    // findld0(0b11010111) == 5.
    use_inline static constexpr Size_t fndld0(Value_t v) noexcept
    {
        return v == SET_ALL ? NBITS : NMSB - cntld0(~v);
    }

};



//***********************************************************************/

// Circular counter with fixed max limit depending on number of bits.
// num_bits must be in range min >1, max <=type bits count.
// Implemented operators ++, --.
// Example: Bitcounter<uint8, 4>
// count min = always 0
// count max = 0b00001111, 4 bits.
template<typename T, T num_bits>
class Bitcounter
{
public:
    static_assert(IS_TYPE_VALID<T>, "Error! Wrong type.");
    static_assert(num_bits > 1, "Error! Wrong min number of bits."); // Check min.
    static_assert(num_bits <= (sizeof(T) * 8), "Error! Wrong max number of bits."); // Check max.
    using Value_t = T;
    using Size_t = std::size_t;
    using Self_t = Bitcounter;

    static constexpr Value_t VAL_0 = static_cast<Value_t>(0);
    static constexpr Value_t VAL_1 = static_cast<Value_t>(1);

    static constexpr Value_t NUM_BITS = num_bits;
    static constexpr Value_t CNT_MIN = VAL_0;
    static constexpr Value_t CNT_MAX = (NUM_BITS - VAL_1) | NUM_BITS;
    static constexpr Value_t MASK_NBITS = CNT_MAX;

    Self_t& operator++ () noexcept
    {
        ++val;
        val &= MASK_NBITS;
        return *this;
    }

    Self_t operator++ (int) noexcept
    {
        Self_t tmp = *this;
        ++(*this);
        return tmp;
    }

    Self_t& operator-- () noexcept
    {
        --val;
        val &= MASK_NBITS;
        return *this;
    }

    Self_t operator-- (int) noexcept
    {
        Self_t tmp = *this;
        --(*this);
        return tmp;
    }

    // Getter.
    operator Value_t() const noexcept { return val; }

    // Returns value shifted left by numbits.
    Value_t getshl(Size_t numbits) const noexcept { return val << numbits; }

    Value_t get() const noexcept { return val; }
    void inc() noexcept { ++val; }
    void dec() noexcept { --val; }
    void reset() noexcept { val = CNT_MIN; }

    bool is_empty() const noexcept { return val == CNT_MIN; }
    bool is_full() const noexcept { return val == CNT_MAX; }

private:
    Value_t val{};
};


#endif
