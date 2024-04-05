
#ifdef _MSC_VER
#pragma once
#endif

#ifndef BITMANIP_H
#define BITMANIP_H

//#include <cstddef>
//#include <cstdint>
//#include <utility>
//#include "Bitparams.h"



namespace fav
{
    //Bit manipulation functions.
    template<typename T>
    class Bitmanip
    {
    private:
        static constexpr T NUM_0 = static_cast<T>(0u);
        static constexpr T NUM_1 = static_cast<T>(1u);

    public:
        static_assert(std::is_arithmetic<T>::value, "Error! Wrong type. Use arithmetic type.");
        static_assert(!std::is_same<T, bool>::value, "Error! Boolean type not supported.");

        using Value_t = T;
        using Size_t = std::size_t;
        using Bp_t = Bitparams<Value_t>;
        using Self_t = Bitmanip;



        /*Boolean NOT, invert all bits.
        0b11110101 value
        0b00001010 result */
        static inline constexpr Value_t bits_invert(Value_t v) noexcept { return ~v; }

        /*Boolean AND.
        0b10101010 value a
        0b00110011 value b
        0b00100010 result */
        static inline constexpr Value_t bits_and(Value_t a, Value_t b) noexcept { return a & b; }

        /*Boolean OR.
        0b10101010 value a
        0b00110011 value b
        0b10111011 result */
        static inline constexpr Value_t bits_or(Value_t a, Value_t b) noexcept { return a | b; }

        /*Boolean XOR.
        0b10101010 value a
        0b00110011 value b
        0b10011001 result */
        static inline constexpr Value_t bits_xor(Value_t a, Value_t b) noexcept { return a ^ b; }



        //***********************************************************************/
        //Getter
        //***********************************************************************/



        /**Get single bit state at position. Returns 0 or 1.*/
        static Value_t get_bit(Value_t v, Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid(bitnum)) { return v; }
            v &= (NUM_1 << bitnum);
            v >>= bitnum;
            return v;
        }

        /**Get less significant bit state. Returns 0 or 1.*/
        static inline constexpr Value_t get_bit_ls(Value_t v) noexcept
        {
            return v & Bp_t::BIT_VALUE_LS;
        }

        /**Get most significant bit state. Returns 0 or 1.*/
        static inline constexpr Value_t get_bit_ms(Value_t v) noexcept
        {
            return (v & Bp_t::BIT_VALUE_MS) >> Bp_t::NUM_BIT_MS;
        }

        /*Get masked bits. Same as and(mask).
        0b10101010 value
        0b00111100 mask
        0b00101000 result */
        static inline constexpr Value_t get_masked(Value_t v, Value_t mask) noexcept
        {
            return v & mask;
        }

        /*Bit value.
        bitnum = 0, returns 0b00000001 = 1
        bitnum = 4, returns 0b00010000 = 16
        returns 0b00000000 if bitnum >= NUM_BITS */
        static inline constexpr Value_t get_bit_value(Size_t bitnum) noexcept
        {
            return is_valid(bitnum) ? (NUM_1 << bitnum) : NUM_0;
        }

        /*Mask all but not bitnum.
        bitnum = 0, returns 0b11111110
        bitnum = 4, returns 0b11101111 
        returns 0b11111111 if bitnum >= NUM_BITS */
        static inline constexpr Value_t get_bit_mask(Size_t bitnum) noexcept
        {
            return ~(get_bit_value(bitnum));
        }



        //***********************************************************************/
        //Setter
        //***********************************************************************/



        /*Set all to 1.
        0b01010101 value
        0b11111111 result.*/
        static inline constexpr Value_t set_all(Value_t v) noexcept
        {
            return Bp_t::MASK_ALL;
        }

        /*Set bit at bitnum to 1.
        0b10101010 value, bitnum = 0
        0b10101011 result.
        returns unchanged value if bitnum is invalid.*/
        static inline Value_t set_bit(Value_t v, Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid(bitnum)) { return v; }
            return v | (NUM_1 << bitnum);
        }

        /*Set single bit at position to 0 or 1.
        0b10101011 value, bitnum = 0, state = 0
        0b10101010 result.
        returns unchanged value if bitnum is invalid.*/
        static Value_t set_bit_state(Value_t v, Size_t bitnum, Value_t state) noexcept
        {
            if (Bp_t::is_invalid(bitnum)) { return v; }
            state &= NUM_1;
            if(state) { v = set_bit(v, bitnum); }
            else { v =  clear_bit(v, bitnum); }
            return v;
        }

        /*Set less significant bit to 1.
        0b10101010 value
        0b10101011 result.*/
        static inline constexpr Value_t set_bit_ls(Value_t v) noexcept
        {
            return v | Bp_t::BIT_VALUE_LS;
        }

        /*Set most significant bit to 1.
        0b01010101 value
        0b11010101 result.*/
        static inline constexpr Value_t set_bit_ms(Value_t v) noexcept
        {
            return v | Bp_t::BIT_VALUE_MS;
        }

        /*Set masked bits.
        0b10101010 value
        0b00111100 mask
        0b10111110 result */
        static inline constexpr Value_t set_masked(Value_t v, Value_t mask) noexcept
        {
            return v |= mask;
        }



        //***********************************************************************/
        //Toggle
        //***********************************************************************/


        /*Toggle single bit.
        bitnum = 0
        0b10101010 value
        0b10101011 result
        0b10101010 repeat.
        returns unchanged value if bitnum is invalid.*/
        static inline Value_t toggle_bit(Value_t v, Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid(bitnum)) { return v; }
            return v ^ (NUM_1 << bitnum);
        }

        /*Toggle less significant bit.
        0b10101010 value
        0b10101011 result
        0b10101010 repeat.*/
        static inline constexpr Value_t toggle_bit_ls(Value_t v) noexcept
        {
            return v ^ Bp_t::BIT_VALUE_LS;
        }

        /*Toggle most significant bit.
        0b01010101 value
        0b11010101 result
        0b01010101 repeat.*/
        static inline constexpr Value_t toggle_bit_ms(Value_t v) noexcept
        {
            return v ^ Bp_t::BIT_VALUE_MS;
        }

        /*Toggle masked bits. Same as xor(mask).
        0b10101010 value
        0b00001111 mask
        0b10100101 result
        0b10101010 repeat. */
        static inline constexpr Value_t toggle_masked(Value_t v, Value_t mask) noexcept
        {
            return v ^ mask;
        }

        //***********************************************************************/
        //Isolate
        //***********************************************************************/



        /*Isolate single bit.
        0b10101010 value, bitnum = 1
        0b00000010 result.
        returns unchanged value if bitnum is invalid.*/
        static inline Value_t isolate_bit(Value_t v, Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid(bitnum)) { return v; }
            return v & (NUM_1 << bitnum);
        }

        static inline constexpr Value_t isolate_bit_ls(Value_t v) noexcept
        {
            return v & Bp_t::BIT_VALUE_LS;
        }

        static inline constexpr Value_t isolate_bit_ms(Value_t v) noexcept
        {
            return v & Bp_t::BIT_VALUE_MS;
        }

        /*Isolate masked bits. Same as and(mask).
        0b10101010 value
        0b00001111 mask
        0b00001010 result. */
        static inline constexpr Value_t isolate_masked(Value_t v, Value_t mask) noexcept
        {
            return v & mask;
        }



        //***********************************************************************/
        //Clear
        //***********************************************************************/



        /*Clear all to 0.
        0b10101010 value
        0b00000000 result.*/
        static inline constexpr Value_t clear_all(Value_t v) noexcept { v = NUM_0; }

        /*Clear single bit to 0.
        0b10101010 value, bitnum = 7
        0b00101010 result.
        returns unchanged value if bitnum is invalid.*/
        static inline Value_t clear_bit(Value_t v, Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid(bitnum)) { return v; }
            v &= (~(NUM_1 << bitnum));
            return v;
        }

        /*Clear less significant bit.
        0b01010101 value
        0b11010100 result.*/
        static inline constexpr  Value_t clear_bit_ls(Value_t v) noexcept
        {
            return v & Bp_t::BIT_VALUE_LS;
        }

        /*Clear most significant bit.
        0b10101010 value
        0b00101011 result.*/
        static inline constexpr  Value_t clear_bit_ms(Value_t v) noexcept
        {
            return v & Bp_t::BIT_VALUE_MS;
        }


        /*Clear masked bits.
        0b10101010 value
        0b00111100 mask
        0b10000010 result. */
        static inline constexpr Value_t clear_mask(Value_t v, Value_t mask) noexcept
        {
            return v & (~mask);
        }



        //***********************************************************************/
        //Conditional
        //***********************************************************************/



        /*Test if any bit is set to 1.*/
        static inline constexpr bool is_set_any(Value_t value) noexcept
        {
            return value > NUM_0;
        }

        /*Test if all bit is set to 1.*/
        static inline constexpr bool is_set_all(Value_t value) noexcept
        {
            return value == Bp_t::MASK_ALL;
        }

        /*Test if less significant bit is set to 1.*/
        static inline constexpr bool is_set_ls(Value_t value) noexcept
        {
            return (value & Bp_t::BIT_VALUE_LS) != NUM_0;
        }

        /*Test if most significant bit is set to 1.*/
        static inline constexpr bool is_set_ms(Value_t value) noexcept
        {
            return (value & Bp_t::BIT_VALUE_MS) != NUM_0;
        }



        //***********************************************************************/



        /*Test if any bits is 0.*/
        static inline constexpr bool is_clear_any(Value_t value) noexcept
        {
            return value < Bp_t::MASK_ALL;
        }

        /*Test if all bits is 0.*/
        static inline constexpr bool is_clear_all(Value_t value) noexcept
        {
            return value == NUM_0;
        }

        /*Test if less significant bit is 0.*/
        static inline constexpr bool is_clear_ls(Value_t value) noexcept
        {
            return (value & Bp_t::BIT_VALUE_LS) == NUM_0;
        }

        /*Test if most significant bit is 0.*/
        static inline constexpr bool is_clear_ms(Value_t value) noexcept
        {
            return (value & Bp_t::BIT_VALUE_MS) == NUM_0;
        }



        //***********************************************************************/



        /*Test if bitnum is valid. */
        static inline constexpr bool is_valid(Size_t bitnum) noexcept
        {
            return bitnum < Bp_t::NUM_BITS;
        }

        /*Test if bitnum is invalid. */
        static inline constexpr bool is_invalid(Size_t bitnum) noexcept
        {
            return bitnum >= Bp_t::NUM_BITS;
        }

        /*Test if bitnum is less significant. */
        static inline constexpr bool is_ls(Size_t bitnum) noexcept
        {
            return bitnum == Bp_t::BIT_NUM_LS;
        }

        /*Test if bitnum is most significant. */
        static inline constexpr bool is_ms(Size_t bitnum) noexcept
        {
            return bitnum == Bp_t::BIT_NUM_MS;
        }



        //***********************************************************************/



        static inline constexpr bool is_odd(Value_t value) noexcept
        {
            return (value & NUM_1) == NUM_0 ? false : true;
        }

        static inline constexpr bool is_even(Value_t value) noexcept
        {
            return !is_odd(value);
        }



        //***********************************************************************/
        //Special
        //***********************************************************************/



        /*Swap a <->b values. */
        static void swap(Value_t& a, Value_t& b) noexcept
        {
            std::swap(a, b);
        }

        /*Convert value to boolean.*/
        static inline constexpr bool to_bool(Value_t v) noexcept
        {
            return v != NUM_0;
        }

        /*Advance bitnum. bitnum %= NUM_BITS.*/
        static inline constexpr Size_t advance(Size_t bitnum) noexcept
        {
            return bitnum & Bp_t::MASK_NUM_BITS;
        }



    };//Bitmanip

}//fav



#endif