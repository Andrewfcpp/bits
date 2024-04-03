
#ifdef _MSC_VER
#pragma once
#endif

#ifndef BITPARAMS_H
#define BITPARAMS_H

#include <cstddef>
#include <cstdint>
#include <utility>

namespace fav
{
    /*Static type parameters and helpers.*/
    template<typename T>
    class Bitparams
    {
    private:
        static_assert(std::is_arithmetic<T>::value, "Error! Wrong type. Use arithmetic type.");
        static_assert(!std::is_same<T, bool>::value, "Error! Boolean type not supported.");

        static constexpr T NUM_0  = static_cast<T>(0u);
        static constexpr T NUM_1  = static_cast<T>(1u);
        static constexpr T NUM_2  = static_cast<T>(2u);
        static constexpr T NUM_4  = static_cast<T>(4u);
        static constexpr T NUM_8  = static_cast<T>(8u);
        static constexpr T NUM_0F = static_cast<T>(0x0Fu);
        static constexpr T NUM_FF = static_cast<T>(0xFFu);

    public:
        using Value_t = T;
        using Size_t = std::size_t;
        using Self_t = Bitparams;

        /*Type size in bytes.
        Example: uint32 = 4. */
        static constexpr Size_t NUM_BYTES = sizeof(Value_t);

        /*Type size in bits.
        Example: uint32_t = 32. */
        static constexpr Size_t NUM_BITS = NUM_BYTES * 8u;

        /*Mask all bits.
        Example: uint8 = 0b11111111. */
        static constexpr Value_t MASK_ALL = ~NUM_0;

        /*Make mask from NUM_BITS.
        Example: uint8_t = 0b00000111, range 0 to 7 bits.*/
        static constexpr Size_t MASK_NUM_BITS = NUM_BITS - NUM_1;

        /*Less significant bit number. Always 0. */
        static constexpr Size_t NUM_LSBIT = NUM_0;

        /*Most significant bit number.
        Example: uint32 = 31 bit.*/
        static constexpr Size_t NUM_MSBIT = NUM_BITS - NUM_1;

        /*Less significant bit value. Always = 1. */
        static constexpr Value_t VALUE_LSBIT = NUM_1;

        /*Most significant bit value.
        Example: uint8 = 128. */
        static constexpr Value_t VALUE_MSBIT = NUM_1 << (NUM_BITS - 1u);

        /*Mask all but not less significant bit.
        Example: uint8 = 0b11111110. */
        static constexpr Value_t MASK_LSBIT = ~VALUE_LSBIT;

        /*Mask all but not most significant bit.
        Example: uint8 = 0b01111111. */
        static constexpr Value_t MASK_MSBIT = ~VALUE_MSBIT;

        static constexpr bool IS_8BIT  = (NUM_BYTES == 1u);
        static constexpr bool IS_16BIT = (NUM_BYTES == 2u);
        static constexpr bool IS_32BIT = (NUM_BYTES == 4u);
        static constexpr bool IS_64BIT = (NUM_BYTES == 8u);

        static constexpr Value_t MASK_LSBYTE_0x0F = NUM_0F;
        static constexpr Value_t MASK_MSBYTE_0xF0 = NUM_0F << (NUM_BITS - 4u);
        static constexpr Value_t MASK_LSBYTE_0xFF = NUM_FF;
        static constexpr Value_t MASK_MSBYTE_0xFF = NUM_FF << (NUM_BITS - 8u);



        /*Test if any bit is set to 1.*/
        static inline constexpr bool is_set_any(Value_t value) noexcept
        {
            return value > NUM_0;
        }

        /*Test if all bit is set to 1.*/
        static inline constexpr bool is_set_all(Value_t value) noexcept
        {
            return value == MASK_ALL;
        }

        /*Test if less significant bit is set to 1.*/
        static inline constexpr bool is_set_lsbit(Value_t value) noexcept
        {
            return (value & VALUE_LSBIT) != NUM_0;
        }

        /*Test if most significant bit is set to 1.*/
        static inline constexpr bool is_set_msbit(Value_t value) noexcept
        {
            return (value & VALUE_MSBIT) != NUM_0;
        }

        /*Test if any bits is 0.*/
        static inline constexpr bool is_clear_any(Value_t value) noexcept
        {
            return value < MASK_ALL;
        }

        /*Test if all bits is 0.*/
        static inline constexpr bool is_clear_all(Value_t value) noexcept
        {
            return value == NUM_0;
        }

        /*Test if less significant bit is 0.*/
        static inline constexpr bool is_clear_lsbit(Value_t value) noexcept
        {
            return (value & VALUE_LSBIT) == NUM_0;
        }

        /*Test if most significant bit is 0.*/
        static inline constexpr bool is_clear_msbit(Value_t value) noexcept
        {
            return (value & VALUE_MSBIT) == NUM_0;
        }

        /*Test if bitnum is valid. */
        static inline constexpr bool is_valid_bitnum(Size_t bitnum) noexcept
        {
            return bitnum < NUM_BITS;
        }

        /*Test if bitnum is invalid. */
        static inline constexpr bool is_invalid_bitnum(Size_t bitnum) noexcept
        {
            return bitnum >= NUM_BITS;
        }

        static inline constexpr bool is_odd(Value_t value) noexcept
        {
            return static_cast<bool>(value & NUM_1);
        }

        static inline constexpr bool is_even(Value_t value) noexcept
        {
            return !is_odd(value);
        }

        /*Bit value.
        bitnum = 0, returns 0b00000001 = 1
        bitnum = 4, returns 0b00010000 = 16
        returns 0x00 if bitnum >= NUM_BITS */
        static inline constexpr Value_t bit_value(Size_t bitnum) noexcept
        {
            return is_valid_bitnum(bitnum) ? (NUM_1 << bitnum) : NUM_0;
        }

        /*Mask all but not bitnum.
        bitnum = 0, returns 0b11111110
        bitnum = 4, returns 0b11101111 
        returns 0xFF if bitnum >= NUM_BITS */
        static inline constexpr Value_t bit_mask(Size_t bitnum) noexcept
        {
            return ~(bit_value(bitnum));
        }



    };//Bitparams



}//fav



#endif