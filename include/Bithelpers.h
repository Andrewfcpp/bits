//    Author: Andrey Fyodorov (Andrew)
//    Mail:   andfjod@yahoo.com
//    Date:   2024, January, 14

#ifndef BITHELPERS_H
#define BITHELPERS_H



#include <cstddef>
#include <cstdint>
#include <utility>
#include "Bitparams.h"



/*Misc bit twiddling functions.*/
class Bithelpers
{
private:
    template<typename U> using enable_if_integral_t = std::enable_if_t<std::is_integral<U>::value>;
    template<typename U> using enable_if_unsigned_t = std::enable_if_t<std::is_unsigned<U>::value>;
    template<typename U> using enable_if_signed_t = std::enable_if_t<std::is_signed<U>::value>;
public:
    //using size_type = std::size_t;
    using Size_t = std::size_t;



    /*Boolean NOT, invert all bits.
    0b11110101 value
    0b00001010 result */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static constexpr T bits_invert(const T v) noexcept { return ~v; }

    /*Boolean AND
    0b10101010 value a
    0b00110011 value b
    0b00100010 result */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static constexpr T bits_and(const T a, const T b) noexcept { return a & b; }

    /*Boolean OR
    0b10101010 value a
    0b00110011 value b
    0b10111011 result */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static constexpr T bits_or(const T a, const T b) noexcept { return a | b; }

    /*Boolean XOR
    0b10101010 value a
    0b00110011 value b
    0b10011001 result */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static constexpr T bits_xor(const T a, const T b) noexcept { return a ^ b; }



    //************************************************************************/
    


    /*Reverse bits
    0b11110101 value
    0b10101111 return*/
    template<typename T, typename = enable_if_unsigned_t<T>>
    static T reverse(T) noexcept
    {
        static_assert(0, "Error! Not implemented.");
        return{};
    }

    template<>
    static std::uint8_t reverse(std::uint8_t v) noexcept
    {
        using Value_t = std::uint8_t;
        using Bp_t = Bitparams<Value_t>;
        if (Bp_t::is_clear_all(v)) { return 0u; }
        if (Bp_t::is_set_all(v)) { return Bp_t::MASK_ALL; }

        v = ((v >> 1) & 0x55u) | ((v << 1) & 0xAAu);
        v = ((v >> 2) & 0x33u) | ((v << 2) & 0xCCu);
        v = ((v >> 4) & 0x0Fu) | ((v << 4) & 0xF0u);
        return v;
    }

    template<>
    static std::uint16_t reverse(std::uint16_t v) noexcept
    {
        using Value_t = std::uint16_t;
        using Bp_t = Bitparams<Value_t>;
        if (Bp_t::is_clear_all(v)) { return 0u; }
        if (Bp_t::is_set_all(v)) { return Bp_t::MASK_ALL; }

        v = ((v >> 1) & 0x5555u) | ((v << 1) & 0xAAAAu);
        v = ((v >> 2) & 0x3333u) | ((v << 2) & 0xCCCCu);
        v = ((v >> 4) & 0x0F0Fu) | ((v << 4) & 0xF0F0u);
        v = ((v >> 8) & 0x00FFu) | ((v << 8) & 0xFF00u);
        return v;
    }

    template<>
    static std::uint32_t reverse(std::uint32_t v) noexcept
    {
        using Value_t = std::uint32_t;
        using Bp_t = Bitparams<Value_t>;
        if (Bp_t::is_clear_all(v)) { return 0u; }
        if (Bp_t::is_set_all(v)) { return Bp_t::MASK_ALL; }

        v = ((v >> 1)  & 0x55555555u) | ((v << 1)  & 0xAAAAAAAAu);
        v = ((v >> 2)  & 0x33333333u) | ((v << 2)  & 0xCCCCCCCCu);
        v = ((v >> 4)  & 0x0F0F0F0Fu) | ((v << 4)  & 0xF0F0F0F0u);
        v = ((v >> 8)  & 0x00FF00FFu) | ((v << 8)  & 0xFF00FF00u);
        v = ((v >> 16) & 0x0000FFFFu) | ((v << 16) & 0xFFFF0000u);
        return v;
    }

    template<>
    static std::uint64_t reverse(std::uint64_t v) noexcept
    {
        using Value_t = std::uint64_t;
        using Bp_t = Bitparams<Value_t>;
        if (Bp_t::is_clear_all(v)) { return 0ULL; }
        if (Bp_t::is_set_all(v)) { return Bp_t::MASK_ALL; }

        v = ((v >> 1)  & 0x5555555555555555ULL) | ((v << 1)  & 0xAAAAAAAAAAAAAAAAULL);
        v = ((v >> 2)  & 0x3333333333333333ULL) | ((v << 2)  & 0xCCCCCCCCCCCCCCCCULL);
        v = ((v >> 4)  & 0x0F0F0F0F0F0F0F0FULL) | ((v << 4)  & 0xF0F0F0F0F0F0F0F0ULL);
        v = ((v >> 8)  & 0x00FF00FF00FF00FFULL) | ((v << 8)  & 0xFF00FF00FF00FF00ULL);
        v = ((v >> 16) & 0x0000FFFF0000FFFFULL) | ((v << 16) & 0xFFFF0000FFFF0000ULL);
        v = ((v >> 32) & 0x00000000FFFFFFFFULL) | ((v << 32) & 0xFFFFFFFF00000000ULL);
        return v;
    }



    //***********************************************************************/



    //min_mask
    /*Returns closest mask for value.*/
    template<typename T, typename = enable_if_unsigned_t<T>>
    static T mask_for(T) noexcept
    {
        static_assert(0, "Error! Not implemented.");
        return{};
    }

    template<>
    static std::uint8_t mask_for(std::uint8_t v) noexcept
    {
        v |= (v >> 1);
        v |= (v >> 2);
        v |= (v >> 4);
        return v;
    }

    template<>
    static std::uint16_t mask_for(std::uint16_t v) noexcept
    {
        v |= (v >> 1);
        v |= (v >> 2);
        v |= (v >> 4);
        v |= (v >> 8);
        return v;
    }
    
    template<>
    static std::uint32_t mask_for(std::uint32_t v) noexcept
    {
        v |= (v >> 1);
        v |= (v >> 2);
        v |= (v >> 4);
        v |= (v >> 8);
        v |= (v >> 16);
        return v;
    }

    template<>
    static std::uint64_t mask_for(std::uint64_t v) noexcept
    {
        v |= (v >> 1);
        v |= (v >> 2);
        v |= (v >> 4);
        v |= (v >> 8);
        v |= (v >> 16);
        v |= (v >> 32);
        return v;
    }



    //***********************************************************************/



    /*Count number of ones in value.
    0b00000000 returns 0
    0b10101010 returns 4
    0b11111111 returns 8 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static Size_t pop_count(T) noexcept
    {
        static_assert(0, "Error! Not implemented.");
        return 0u;
    }

    template<>
    static Size_t pop_count(std::uint8_t v) noexcept
    {
        using Value_t = std::uint8_t;
        using Bp_t = Bitparams<Value_t>;
        if (Bp_t::is_clear_all(v)) { return 0u; }
        if (Bp_t::is_set_all(v)) { return Bp_t::NUM_BITS; }

        v -= (v >> 1) & 0x55u;
        v = ((v >> 2) & 0x33u) + (v & 0x33u);
        v = (((v >> 4) + v) & 0x0Fu) * 0x01u;
        return static_cast<Size_t>(v);
    }

    template<>
    static Size_t pop_count(std::uint16_t v) noexcept
    {
        using Value_t = std::uint16_t;
        using Bp_t = Bitparams<Value_t>;
        if (Bp_t::is_clear_all(v)) { return 0u; }
        if (Bp_t::is_set_all(v)) { return Bp_t::NUM_BITS; }

        v -= (v >> 1) & 0x5555u;
        v = ((v >> 2) & 0x3333u) + (v & 0x3333u);
        v = ((((v >> 4) + v) & 0x0F0Fu) * 0x0101u) >> 8;
        return static_cast<Size_t>(v);
    }

    template<>
    static Size_t pop_count(std::uint32_t v) noexcept
    {
        using Value_t = std::uint32_t;
        using Bp_t = Bitparams<Value_t>;
        if (Bp_t::is_clear_all(v)) { return 0u; }
        if (Bp_t::is_set_all(v)) { return Bp_t::NUM_BITS; }

        v -= (v >> 1) & 0x55555555u;
        v = ((v >> 2) & 0x33333333u) + (v & 0x33333333u);
        v = ((((v >> 4) + v) & 0x0F0F0F0Fu) * 0x01010101u) >> 24;
        return static_cast<Size_t>(v);
    }

    template<>
    static Size_t pop_count(std::uint64_t v) noexcept
    {
        using Value_t = std::uint64_t;
        using Bp_t = Bitparams<Value_t>;
        if (Bp_t::is_clear_all(v)) { return 0ULL; }
        if (Bp_t::is_set_all(v)) { return Bp_t::NUM_BITS; }

        v -= (v >> 1) & 0x5555555555555555ULL;
        v = ((v >> 2) & 0x3333333333333333ULL) + (v & 0x3333333333333333ULL);
        v = ((((v >> 4) + v) & 0x0F0F0F0F0F0F0F0FULL) * 0x0101010101010101ULL) >> 56;
        return static_cast<Size_t>(v);
    }



    //***********************************************************************/



    /*Count number of zeros.
    0b00000000 returns 8
    0b10101010 returns 4
    0b11111111 returns 0 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static Size_t count_zero(T v) noexcept
    {
        return Bitparams<T>::NUM_BITS - pop_count<T>(v);
    }

    /*Count number of leading zeros.
    0b00000000 returns 8
    0b00001100 returns 4
    0b11111111 returns 0 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static Size_t count_lead_zero(T v) noexcept
    {
        v = mask_for<T>(v);
        ~v;
        return pop_count<T>(v);
    }



    /*Count number of trailing zeros.
    0b00000000 returns 8
    0b00101000 returns 3
    0b11111111 returns 0 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static Size_t count_trail_zero(T) noexcept
    {
        static_assert(0, "Error! Not implemented.");
        return 0u;
    }

    template<>
    static Size_t count_trail_zero(std::uint8_t v) noexcept
    {
        using Value_t = std::uint8_t;
        using Bp_t = Bitparams<Value_t>;
        Size_t c = Bp_t::NUM_BITS;
        if (Bp_t::is_clear_all(v)) { return c; }
        if (Bp_t::is_set_all(v)) { return 0u; }

        v &= (0u - v);
        if (v) { --c; }
        if (v & 0x0Fu) { c -= 4u; }
        if (v & 0x33u) { c -= 2u; }
        if (v & 0x55u) { c -= 1u; }
        return c;
    }

    template<>
    static Size_t count_trail_zero(std::uint16_t v) noexcept
    {
        using Value_t = std::uint16_t;
        using Bp_t = Bitparams<Value_t>;
        Size_t c = Bp_t::NUM_BITS;
        if (Bp_t::is_clear_all(v)) { return c; }
        if (Bp_t::is_set_all(v)) { return 0u; }

        v &= (0u - v);
        if (v) { --c; }
        if (v & 0x00FFu) { c -= 8u; }
        if (v & 0x0F0Fu) { c -= 4u; }
        if (v & 0x3333u) { c -= 2u; }
        if (v & 0x5555u) { c -= 1u; }
        return c;
    }

    template<>
    static Size_t count_trail_zero(std::uint32_t v) noexcept
    {
        using Value_t = std::uint32_t;
        using Bp_t = Bitparams<Value_t>;
        Size_t c = Bp_t::NUM_BITS;
        if (Bp_t::is_clear_all(v)) { return c; }
        if (Bp_t::is_set_all(v)) { return 0u; }

        v &= (0u - v);
        if (v) { --c; }
        if (v & 0x0000FFFFu) { c -= 16u; }
        if (v & 0x00FF00FFu) { c -= 8u; }
        if (v & 0x0F0F0F0Fu) { c -= 4u; }
        if (v & 0x33333333u) { c -= 2u; }
        if (v & 0x55555555u) { c -= 1u; }
        return c;
    }

    template<>
    static Size_t count_trail_zero(std::uint64_t v) noexcept
    {
        using Value_t = std::uint64_t;
        using Bp_t = Bitparams<Value_t>;
        Size_t c = Bp_t::NUM_BITS;
        if (Bp_t::is_clear_all(v)) { return c; }
        if (Bp_t::is_set_all(v)) { return 0ULL; }

        v &= (0ULL - v);
        if (v) { --c; }
        if (v & 0x00000000FFFFFFFFULL) { c -= 32u; }
        if (v & 0x0000FFFF0000FFFFULL) { c -= 16u; }
        if (v & 0x00FF00FF00FF00FFULL) { c -= 8u; }
        if (v & 0x0F0F0F0F0F0F0F0FULL) { c -= 4u; }
        if (v & 0x3333333333333333ULL) { c -= 2u; }
        if (v & 0x5555555555555555ULL) { c -= 1u; }
        return c;
    }



    //***********************************************************************/



    /*Count number of leading ones.
    0b11110011 returns 4 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static Size_t count_lead_one(T v) noexcept
    {
        v = ~v;
        return count_lead_zero<T>(v);
    }

    /*Count number of trailing ones.
    0b11110011 returns 2 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static Size_t count_trail_one(T v) noexcept
    {
        v = ~v;
        return count_trail_zero<T>(v);
    }



    //***********************************************************************/



    /*Round to highest power of 2 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static T pow2_highest(T v) noexcept
    {
        --v;
        v = mask_for<T>(v);
        return ++v;
    }



    /*Round to lowest power of 2 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static T pow2_lowest(T v) noexcept
    {
        v = mask_for<T>(v);
        return v - (v >> 1);
    }



    //***********************************************************************/



    /*Isolate lowest part of bits before pos.
    0b01010101 value
    0b00001000 pos = 3
    0b00000101 result */
    template<typename T>
    static T isolate_low(T value, Size_t pos) noexcept
    {
        using Bp_t = Bitparams<T>;
        pos &= Bp_t::NUM_BITS_MASK;

        T mask = Bp_t::bit_value(pos);
        --mask;
        value &= mask;
        return value;
    }

    /*Isolate highest part of bits after pos.
    0b10101010 value
    0b00001000 pos = 3
    0b10100000 result */
    template<typename T>
    static T isolate_high(T value, Size_t pos) noexcept
    {
        using Bp_t = Bitparams<T>;
        pos &= Bp_t::NUM_BITS_MASK;

        T mask = Bp_t::MASK_ALL;
        ++pos;
        mask <<= pos;
        value &= mask;
        return value;
    }

    /*Remove bit from value.
    0b10101010 value
    0b00001000 pos = 3
    0b01010010 result */
    template<typename T>
    static T remove_bit(T value, Size_t pos) noexcept
    {
        T a = isolate_low<T>(value, pos);
        T b = isolate_high<T>(value, pos);
        b >>= 1;
        value = a | b;
        return value;
    }



    //***********************************************************************/



    /** Find first lead bit that is set to 1
    0b00000000 returns 0xFFFF... = wrong value, bit not found.
    0b00000001 returns 0
    0b00101000 returns 5
    0b11111111 returns 7 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static Size_t find_lead_one(T v) noexcept
    {
        using Bp_t = Bitparams<T>;
        static constexpr T not_found = Bp_t::MASK_ALL;
        if (Bp_t::is_clear_all(v)) { return not_found; }
        if (Bp_t::is_set_msb(v)) { return Bp_t::NUM_MSB; }
        
        Size_t tmp = count_lead_zero<T>(v);
        ++tmp;
        tmp = Bp_t::NUM_BITS - tmp;
        return tmp;
    }



    /** Find first trail bit that is set to 1
    0b00000000 returns 0xFFFF... = wrong value, bit not found.
    0b00000001 returns 0
    0b00101000 returns 3
    0b11111111 returns 0 */
    template<typename T, typename = enable_if_unsigned_t<T>>
    static Size_t find_trail_one(T v) noexcept
    {
        using Bp_t = Bitparams<T>;
        static constexpr T not_found = Bp_t::MASK_ALL;
        if (Bp_t::is_clear_all(v)) { return not_found; }
        if (Bp_t::is_clear_lsb(v)) { return Bp_t::NUM_LSB; }
        return count_trail_zero<T>(v);
    }



    /** Find first lead bit that is set to 0
    0b00000000 returns 7
    0b11111110 returns 0
    0b11010111 returns 5
    0b11111111 returns 0xFFFF... = wrong value, bit not found. */
    template<typename T>
    static Size_t find_lead_zero(T v) noexcept
    {
        static_assert(0, "Error! Not implemented.");
        using Bp_t = Bitparams<T>;
        static constexpr T not_found = Bp_t::MASK_ALL;
        if (Bp_t::is_set_all()) { return not_found; }
        if (Bp_t::is_clear_msb()) { return Bp_t::NUM_MSB; }

        //TODO
    }



    /** Find first trail bit that is set to 0
    0b00000000 returns 7
    0b11111110 returns 0
    0b11010111 returns 3
    0b11111111 returns 0xFFFF... = wrong value, bit not found. */
    template<typename T>
    static Size_t find_trail_zero(T v) noexcept
    {
        static_assert(0, "Error! Not implemented.");
        using Bp_t = Bitparams<T>;
        static constexpr T not_found = Bp_t::MASK_ALL;
        if (Bp_t::is_clear_lsb(v)) { return Bp_t::NUM_LSB; }
        if (Bp_t::is_set_all(v)) { return not_found; }

        //TODO
    }

};



#endif