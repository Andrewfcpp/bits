//    Author: Andrey Fyodorov (Andrew)
//    Mail:   andfjod@yahoo.com
//    Date:   2024, January, 14

#ifndef BITPARAMS_H
#define BITPARAMS_H

#include <cstddef>
#include <cstdint>
#include <utility>



/*Integral type static parameters.*/
template<typename T>
class Bitparams
{
public:
    static_assert(std::is_integral<T>::value, "Error! Wrong type.");
    static constexpr T NUM_0 = static_cast<T>(0u);
    static constexpr T NUM_1 = static_cast<T>(1u);
    static constexpr T NUM_8 = static_cast<T>(8u);
    static constexpr T MASK_NIBBLE = static_cast<T>(0x0Fu);
    static constexpr T MASK_BYTE   = static_cast<T>(0xFFu);

    using Value_t = T;
    using Size_t = std::size_t;
    using Self_t = Bitparams;

    /*Type size in bytes.
    Example: uint32 = 4. */
    static constexpr Size_t NUM_BYTES = sizeof(Size_t);

    /*Type size in bits.
    Example: uint32_t = 32. */
    static constexpr Size_t NUM_BITS = NUM_BYTES * NUM_8;

    /*Make mask from NUM_BITS.
    Example: uint8_t = 0b00000111, range 0 to 7 bits.*/
    static constexpr Size_t NUM_BITS_MASK = NUM_BITS - NUM_1;

    /*Less significant bit number.
    Always 0. */
    static constexpr Size_t NUM_LSB = NUM_0;

    /*Most significant bit number.
    Example: uint32 = 31 bit.*/
    static constexpr Size_t NUM_MSB = NUM_BITS - NUM_1;

    static constexpr bool IS_8BIT  = (NUM_BYTES == static_cast<Size_t>(1u));
    static constexpr bool IS_16BIT = (NUM_BYTES == static_cast<Size_t>(2u));
    static constexpr bool IS_32BIT = (NUM_BYTES == static_cast<Size_t>(4u));
    static constexpr bool IS_64BIT = (NUM_BYTES == static_cast<Size_t>(8u));

    /*Mask all bits.
    Example: uint8 = 0b11111111. */
    static constexpr Value_t MASK_ALL = (~NUM_0);

    /*Less significant bit value.
    Always = 1. */
    static constexpr Value_t VALUE_LSB = NUM_1;

    /*Most significant bit value.
    Example: uint8 = 128. */
    static constexpr Value_t VALUE_MSB = ~(MASK_ALL >> 1u); //~(~NUM_0 >> 1u); //NUM_1 << NUM_MSB;

    /*Mask all but not less significant bit.
    Example: uint8 = 0b11111110. */
    static constexpr Value_t MASK_LSB = ~VALUE_LSB;

    /*Mask all but not most significant bit.
    Example: uint8 = 0b01111111. */
    static constexpr Value_t MASK_MSB = ~VALUE_MSB;


//Suppress warning C4333 '>>': right shift by too large amount, data loss
#pragma warning(push)
#pragma warning(disable: 4333)
    static constexpr Value_t MASK_LSB_0x0F = MASK_NIBBLE;
    static constexpr Value_t MASK_MSB_0xF0 = ~(MASK_ALL >> 4u);
    static constexpr Value_t MASK_LSB_0xFF = MASK_BYTE;
    static constexpr Value_t MASK_MSB_0xFF = IS_8BIT ? MASK_BYTE : ~(MASK_LSB_0xFF >> 8u);
#pragma warning(pop)



    /*Test if any bit is set to 1.*/
    static constexpr bool is_set_any(const Value_t value) noexcept
    {
        return value > NUM_0;
    }

    /*Test if all bit is set to 1.*/
    static constexpr bool is_set_all(const Value_t value) noexcept
    {
        return value == MASK_ALL;
    }

    /*Test if less significant bit is set to 1.*/
    static constexpr bool is_set_lsb(const Value_t value) noexcept
    {
        return (value & VALUE_LSB) != NUM_0;
    }

    /*Test if most significant bit is set to 1.*/
    static constexpr bool is_set_msb(const Value_t value) noexcept
    {
        return (value & VALUE_MSB) != NUM_0;
    }

    /*Test if any bits is 0.*/
    static constexpr bool is_clear_any(const Value_t value) noexcept
    {
        return value < MASK_ALL;
    }

    /*Test if all bits is 0.*/
    static constexpr bool is_clear_all(const Value_t value) noexcept
    {
        return value == NUM_0;
    }

    /*Test if less significant bit is 0.*/
    static constexpr bool is_clear_lsb(const Value_t value) noexcept
    {
        return (value & VALUE_LSB) == NUM_0;
    }

    /*Test if most significant bit is 0.*/
    static constexpr bool is_clear_msb(const Value_t value) noexcept
    {
        return (value & VALUE_MSB) == NUM_0;
    }

    /*Test if bit position is valid. */
    static constexpr bool is_valid_pos(const Size_t pos) noexcept
    {
        return pos < NUM_BITS;
    }

    /*Test if bit position is invalid. */
    static constexpr bool is_invalid_pos(const Size_t pos) noexcept
    {
        return pos >= NUM_BITS;
    }

    static constexpr bool is_even(const Value_t value) noexcept
    {
        return (value & static_cast<Value_t>(1));
    }

    static constexpr bool is_odd(const Value_t value) noexcept
    {
        return !(value & static_cast<Value_t>(1));
    }

    /*Bit value.
    pos = 0, returns 0b00000001 = 1
    pos = 4, returns 0b00010000 = 16 */
    static constexpr Value_t bit_value(const Size_t pos) noexcept
    {
        return NUM_1 << (pos & NUM_BITS_MASK);
    }

    /*Mask all but not bit pos.
    pos = 0, returns 0b11111110
    pos = 4, returns 0b11101111 */
    static constexpr Value_t bit_mask(const Size_t pos) noexcept
    {
        return ~(bit_value(pos));
    }

};



#endif