
#ifdef _MSC_VER
#pragma once
#endif

#ifndef BITHELPERS_H
#define BITHELPERS_H

//#include <cstddef>
//#include <cstdint>
//#include <utility>
//#include "Bitmanip.h"



namespace fav
{
    /*Misc unsigned int bit twiddling functions.*/
    class Bithelpers
    {
    private:
        template<typename T> using enable_if_arithmetic_t = std::enable_if_t<std::is_arithmetic<T>::value>;
        template<typename T> using enable_if_integral_t = std::enable_if_t<std::is_integral<T>::value>;
        template<typename T> using enable_if_unsigned_t = std::enable_if_t<std::is_unsigned<T>::value>;
        template<typename T> using enable_if_signed_t = std::enable_if_t<std::is_signed<T>::value>;
    public:
        using Size_t = std::size_t;



        //***********************************************************************/
        //Reverse
        //***********************************************************************/


        /*Reverse bits.
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
            using Bm_t = Bitmanip<std::uint8_t>;
            if (Bm_t::is_clear_all(v)) { return v; }
            if (Bm_t::is_set_all(v)) { return v; }

            v = ((v >> 1) & 0x55u) | ((v << 1) & 0xAAu);
            v = ((v >> 2) & 0x33u) | ((v << 2) & 0xCCu);
            v = ((v >> 4) & 0x0Fu) | ((v << 4) & 0xF0u);
            return v;
        }

        template<>
        static std::uint16_t reverse(std::uint16_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint16_t>;
            if (Bm_t::is_clear_all(v)) { return v; }
            if (Bm_t::is_set_all(v)) { return v; }

            v = ((v >> 1) & 0x5555u) | ((v << 1) & 0xAAAAu);
            v = ((v >> 2) & 0x3333u) | ((v << 2) & 0xCCCCu);
            v = ((v >> 4) & 0x0F0Fu) | ((v << 4) & 0xF0F0u);
            v = ((v >> 8) & 0x00FFu) | ((v << 8) & 0xFF00u);
            return v;
        }

        template<>
        static std::uint32_t reverse(std::uint32_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint32_t>;
            if (Bm_t::is_clear_all(v)) { return v; }
            if (Bm_t::is_set_all(v)) { return v; }

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
            using Bm_t = Bitmanip<std::uint64_t>;
            if (Bm_t::is_clear_all(v)) { return v; }
            if (Bm_t::is_set_all(v)) { return v; }

            v = ((v >> 1)  & 0x5555555555555555ull) | ((v << 1)  & 0xAAAAAAAAAAAAAAAAull);
            v = ((v >> 2)  & 0x3333333333333333ull) | ((v << 2)  & 0xCCCCCCCCCCCCCCCCull);
            v = ((v >> 4)  & 0x0F0F0F0F0F0F0F0Full) | ((v << 4)  & 0xF0F0F0F0F0F0F0F0ull);
            v = ((v >> 8)  & 0x00FF00FF00FF00FFull) | ((v << 8)  & 0xFF00FF00FF00FF00ull);
            v = ((v >> 16) & 0x0000FFFF0000FFFFull) | ((v << 16) & 0xFFFF0000FFFF0000ull);
            v = ((v >> 32) & 0x00000000FFFFFFFFull) | ((v << 32) & 0xFFFFFFFF00000000ull);
            return v;
        }



        //***********************************************************************/
        //Mask
        //***********************************************************************/



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
        //Count
        //***********************************************************************/



        /*Population count. Count number of ones in value.
        0b00000000 returns 0
        0b10101010 returns 4
        0b11111111 returns 8 */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t count_pop(T) noexcept
        {
            static_assert(0, "Error! Not implemented.");
            return 0u;
        }

        template<>
        static Size_t count_pop(std::uint8_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint8_t>;
            using Bp_t = Bitparams<std::uint8_t>;
            if (Bm_t::is_clear_all(v)) { return 0u; }
            if (Bm_t::is_set_all(v)) { return Bp_t::NUM_BITS; }

            v -= (v >> 1) & 0x55u;
            v = ((v >> 2) & 0x33u) + (v & 0x33u);
            v = (((v >> 4) + v) & 0x0Fu) * 0x01u;
            return static_cast<Size_t>(v);
        }

        template<>
        static Size_t count_pop(std::uint16_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint16_t>;
            using Bp_t = Bitparams<std::uint16_t>;
            if (Bm_t::is_clear_all(v)) { return 0u; }
            if (Bm_t::is_set_all(v)) { return Bp_t::NUM_BITS; }

            v -= (v >> 1) & 0x5555u;
            v = ((v >> 2) & 0x3333u) + (v & 0x3333u);
            v = ((((v >> 4) + v) & 0x0F0Fu) * 0x0101u) >> 8;
            return static_cast<Size_t>(v);
        }

        template<>
        static Size_t count_pop(std::uint32_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint32_t>;
            using Bp_t = Bitparams<std::uint32_t>;
            if (Bm_t::is_clear_all(v)) { return 0u; }
            if (Bm_t::is_set_all(v)) { return Bp_t::NUM_BITS; }

            v -= (v >> 1) & 0x55555555u;
            v = ((v >> 2) & 0x33333333u) + (v & 0x33333333u);
            v = ((((v >> 4) + v) & 0x0F0F0F0Fu) * 0x01010101u) >> 24;
            return static_cast<Size_t>(v);
        }

        template<>
        static Size_t count_pop(std::uint64_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint64_t>;
            using Bp_t = Bitparams<std::uint64_t>;
            if (Bm_t::is_clear_all(v)) { return 0ull; }
            if (Bm_t::is_set_all(v)) { return Bp_t::NUM_BITS; }

            v -= (v >> 1) & 0x5555555555555555ull;
            v = ((v >> 2) & 0x3333333333333333ull) + (v & 0x3333333333333333ull);
            v = ((((v >> 4) + v) & 0x0F0F0F0F0F0F0F0Full) * 0x0101010101010101ull) >> 56;
            return static_cast<Size_t>(v);
        }



        //***********************************************************************/



        /*Count number of zeros.
        0b00000000 returns 8
        0b10101010 returns 4
        0b11111111 returns 0 */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t count_zeros(T v) noexcept
        {
            return Bitparams<T>::NUM_BITS - count_pop<T>(v);
        }

        /*Count number of leading zeros.
        0b00000000 returns 8
        0b00001100 returns 4
        0b11111111 returns 0 */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t count_lead_zeros(T v) noexcept
        {
            v = mask_for<T>(v);
            v = ~v;
            return count_pop<T>(v);
        }



        /*Count number of trailing zeros.
        0b00000000 returns 8
        0b00101000 returns 3
        0b11111111 returns 0 */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t count_trail_zeros(T) noexcept
        {
            static_assert(0, "Error! Not implemented.");
            return 0u;
        }

        template<>
        static Size_t count_trail_zeros(std::uint8_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint8_t>;
            using Bp_t = Bitparams<std::uint8_t>;
            Size_t c = Bp_t::NUM_BITS;
            if (Bm_t::is_clear_all(v)) { return c; }
            if (Bm_t::is_set_all(v)) { return 0u; }

            v &= (0u - v);
            if (v) { --c; }
            if (v & 0x0Fu) { c -= 4u; }
            if (v & 0x33u) { c -= 2u; }
            if (v & 0x55u) { c -= 1u; }
            return c;
        }

        template<>
        static Size_t count_trail_zeros(std::uint16_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint16_t>;
            using Bp_t = Bitparams<std::uint16_t>;
            Size_t c = Bp_t::NUM_BITS;
            if (Bm_t::is_clear_all(v)) { return c; }
            if (Bm_t::is_set_all(v)) { return 0u; }

            v &= (0u - v);
            if (v) { --c; }
            if (v & 0x00FFu) { c -= 8u; }
            if (v & 0x0F0Fu) { c -= 4u; }
            if (v & 0x3333u) { c -= 2u; }
            if (v & 0x5555u) { c -= 1u; }
            return c;
        }

        template<>
        static Size_t count_trail_zeros(std::uint32_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint32_t>;
            using Bp_t = Bitparams<std::uint32_t>;
            Size_t c = Bp_t::NUM_BITS;
            if (Bm_t::is_clear_all(v)) { return c; }
            if (Bm_t::is_set_all(v)) { return 0u; }

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
        static Size_t count_trail_zeros(std::uint64_t v) noexcept
        {
            using Bm_t = Bitmanip<std::uint64_t>;
            using Bp_t = Bitparams<std::uint64_t>;
            Size_t c = Bp_t::NUM_BITS;
            if (Bm_t::is_clear_all(v)) { return c; }
            if (Bm_t::is_set_all(v)) { return 0ull; }

            v &= (0ull - v); //v &= -signed(v);
            if (v) { --c; }
            if (v & 0x00000000FFFFFFFFull) { c -= 32u; }
            if (v & 0x0000FFFF0000FFFFull) { c -= 16u; }
            if (v & 0x00FF00FF00FF00FFull) { c -= 8u; }
            if (v & 0x0F0F0F0F0F0F0F0Full) { c -= 4u; }
            if (v & 0x3333333333333333ull) { c -= 2u; }
            if (v & 0x5555555555555555ull) { c -= 1u; }
            return c;
        }



        //***********************************************************************/



        /*Count number of leading ones.
        0b11110011 returns 4 */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t count_lead_ones(T v) noexcept
        {
            v = ~v;
            return count_lead_zeros<T>(v);
        }

        /*Count number of trailing ones.
        0b11110011 returns 2 */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t count_trail_ones(T v) noexcept
        {
            v = ~v;
            return count_trail_zeros<T>(v);
        }



        //***********************************************************************/
        //Power of 2
        //***********************************************************************/



        /*Round to highest power of 2. */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static T pow2_highest(T v) noexcept
        {
            --v;
            v = mask_for<T>(v);
            return ++v;
        }



        /*Round to lowest power of 2. */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static T pow2_lowest(T v) noexcept
        {
            v = mask_for<T>(v);
            return v - (v >> 1);
        }



        //***********************************************************************/
        //Isolate
        //***********************************************************************/



        /*Isolate lowest part of bits before bitnum.
        0b01010101 value
        0b00001000 bitnum = 3
        0b00000101 result
        returns 0 if bitnum >= NUM_BITS*/
        template<typename T, typename = enable_if_unsigned_t<T>>
        static T isolate_trail(T v, Size_t bitnum) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            if (Bm_t::is_invalid(bitnum)) { return 0u; }
            T mask = Bm_t::get_value(bitnum);
            --mask;
            v &= mask;
            return v;
        }

        /*Isolate highest part of bits after bitnum.
        0b10101010 value
        0b00001000 bitnum = 3
        0b10100000 result 
        returns 0 if bitnum >= NUM_BITS*/
        template<typename T, typename = enable_if_unsigned_t<T>>
        static T isolate_lead(T v, Size_t bitnum) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            if (Bm_t::is_invalid(bitnum)) { return 0u; }
            T mask = Bp_t::MASK_ALL;
            ++bitnum;
            mask <<= bitnum;
            v &= mask;
            return v;
        }

        /*Remove bit from value.
        0b10101010 value
        0b00001000 bitnum = 3
        0b01010010 result
        returns 0 if bitnum >= NUM_BITS*/
        template<typename T, typename = enable_if_unsigned_t<T>>
        static T remove_bit(T v, Size_t bitnum) noexcept
        {
            T a = isolate_trail<T>(v, bitnum);
            T b = isolate_lead<T>(v, bitnum);
            b >>= 1;
            v = a | b;
            return v;
        }



        //***********************************************************************/
        //Find
        //***********************************************************************/



        /*Find first lead bit that is set to 1.
        0b00000000 returns >= Bitparams<T>::NUM_BITS = wrong value, bit not found.
        0b00000001 returns 0
        0b00101000 returns 5
        0b11111111 returns 7 */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t find_lead_one(T v) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            if (Bm_t::is_clear_all(v)) { return Bp_t::NUM_BITS; }
            if (Bm_t::is_set_ms(v)) { return Bp_t::BIT_NUM_MS; }
            
            Size_t tmp = count_lead_zeros<T>(v);
            ++tmp;
            tmp = Bp_t::NUM_BITS - tmp;
            return tmp;
        }



        /*Find first trail bit that is set to 1.
        0b00000000 returns >= Bitparams<T>::NUM_BITS = wrong value, bit not found.
        0b00000001 returns 0
        0b00101000 returns 3
        0b11111111 returns 0 */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t find_trail_one(T v) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            if (Bm_t::is_clear_all(v)) { return Bp_t::NUM_BITS; }
            if (Bm_t::is_set_ls(v)) { return Bp_t::BIT_NUM_LS; }
            return count_trail_zeros<T>(v);
        }



        /*Find first lead bit that is set to 0.
        0b00000000 returns 7
        0b11111110 returns 0
        0b11010111 returns 5
        0b11111111 returns >= Bitparams<T>::NUM_BITS = wrong value, bit not found. */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t find_lead_zero(T v) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            if (Bm_t::is_set_all(v)) { return Bp_t::NUM_BITS; }
            if (Bm_t::is_clear_ms(v)) { return Bp_t::BIT_NUM_MS; }
            v = ~v;
            return Bp_t::BIT_NUM_MS - count_lead_zeros(v);
        }



        /*Find first trail bit that is set to 0.
        0b00000000 returns 7
        0b11111110 returns 0
        0b11010111 returns 3
        0b11111111 returns >= Bitparams<T>::NUM_BITS = wrong value, bit not found. */
        template<typename T, typename = enable_if_unsigned_t<T>>
        static Size_t find_trail_zero(T v) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            if (Bm_t::is_set_all(v)) { return Bp_t::NUM_BITS; }
            if (Bm_t::is_clear_ls(v)) { return Bp_t::BIT_NUM_LS; }
            v = ~v;
            return count_trail_zeros(v);
        }



        //***********************************************************************/
        //Fill
        //***********************************************************************/



        /*Set bitnum and all trailing bits.
        0b00000000 value
        0b00001000 bitnum = 3
        0b00001111 result.*/
        template<typename T, typename = enable_if_unsigned_t<T>>
        static T fill_trail_ones(T v, Size_t bitnum) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            if (Bm_t::is_invalid(bitnum)) { return Bp_t::MASK_ALL; }
            T mask = static_cast<T>(1u) << bitnum;
            mask = ((mask - 1u) | mask); //mask = mask_for<T>(mask);
            return v | mask;
        }

        /*Set bitnum and all leading bits.
        0b00000000 value
        0b00001000 bitnum = 3
        0b11111000 result.*/
        template<typename T, typename = enable_if_unsigned_t<T>>
        static T fill_lead_ones(T v, Size_t bitnum) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            if (Bm_t::is_invalid(bitnum)) { return v; }
            T mask = static_cast<T>(1u) << bitnum;
            --mask;
            mask = ~mask;
            return v | mask;
        }

        /*Clear bitnum and all trailing bits.
        0b11111111 value
        0b00001000 bitnum = 3,
        0b11110000 result.*/
        template<typename T, typename = enable_if_unsigned_t<T>>
        static T fill_trail_zeros(T v, Size_t bitnum) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            ++bitnum;
            if (Bm_t::is_invalid(bitnum)) { return static_cast<T>(0u); }
            T mask = Bp_t::MASK_ALL;
            mask <<= bitnum;
            return v & mask;
        }

        /*Clear bitnum and all leading bits.
        0b11111111 value
        0b00001000 bitnum = 3,
        0b00000111 result.*/
        template<typename T, typename = enable_if_unsigned_t<T>>
        static T fill_lead_zeros(T v, Size_t bitnum) noexcept
        {
            using Bm_t = Bitmanip<T>;
            using Bp_t = Bitparams<T>;
            if (Bm_t::is_invalid(bitnum)) { return v; }
            T mask = Bp_t::MASK_ALL;
            mask <<= bitnum;
            mask = ~mask;
            return v & mask;
        }



        //***********************************************************************/
        //Swap bytes
        //***********************************************************************/



        /*Swap byte order.*/
        template<typename T, typename = enable_if_integral_t<T>>
        static inline T swap(const T) noexcept
        {
            static_assert(0, "Error! Type not implemented.");
            return{};
        }

        /*Swap uint8_t byte order. Swapped by 4 bits.*/
        template<>
        static inline std::uint8_t swap(std::uint8_t n) noexcept
        {
            return (n << 4) | (n >> 4);
        }

        /*Swap uint16_t byte order.*/
        template<>
        static inline std::uint16_t swap(std::uint16_t n) noexcept
        {
            return (n << 8) | (n >> 8);
        }

        /*Swap uint32_t byte order.*/
        template<>
        static inline std::uint32_t swap(std::uint32_t n) noexcept
        {
            n = ((n << 8) & 0xFF00FF00u) | ((n >> 8) & 0x00FF00FFu);
            return (n << 16) | (n >> 16);
        }

        /*Swap uint64_t byte order.*/
        template<>
        static inline std::uint64_t swap(std::uint64_t n) noexcept
        {
            n = ((n << 8) & 0xFF00FF00FF00FF00ull) | ((n >> 8) & 0x00FF00FF00FF00FFull);
            n = ((n << 16) & 0xFFFF0000FFFF0000ull) | ((n >> 16) & 0x0000FFFF0000FFFFull);
            return (n << 32) | (n >> 32);
        }



    }; //Bithelpers

}//fav

#endif