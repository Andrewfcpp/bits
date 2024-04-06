
#ifdef _MSC_VER
#pragma once
#endif

#ifndef BITPARAMS_H
#define BITPARAMS_H

//#include <cstddef>
//#include <cstdint>
//#include <type_traits>
//#include <utility>



namespace fav
{
    /*Static constexpr arithmetic type parameters.*/
    template<typename T>
    class Bitparams
    {
    private:
        static_assert(std::is_arithmetic<T>::value, "Error! Wrong type. Use arithmetic type.");
        //static_assert(!std::is_same<T, bool>::value, "Error! Boolean type not supported.");

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

        static constexpr Size_t NUM_BYTES_1 = 1u;
        static constexpr Size_t NUM_BYTES_2 = 2u;
        static constexpr Size_t NUM_BYTES_4 = 4u;
        static constexpr Size_t NUM_BYTES_8 = 8u;

        static constexpr Size_t NUM_BITS_4  = 4u;
        static constexpr Size_t NUM_BITS_8  = 8u;
        static constexpr Size_t NUM_BITS_16 = 16u;
        static constexpr Size_t NUM_BITS_24 = 24u;
        static constexpr Size_t NUM_BITS_32 = 32u;
        static constexpr Size_t NUM_BITS_64 = 64u;

        /*Type size in bytes.
        Example: uint32 = 4. */
        static constexpr Size_t NUM_BYTES = sizeof(Value_t);

        /*Type size in bits.
        Example: uint32_t = 32. */
        static constexpr Size_t NUM_BITS = NUM_BYTES * NUM_BITS_8;

        /*Type half size in bits.
        Example: uint32_t = 16. */
        static constexpr Size_t NUM_BITS_HALF = NUM_BITS >> 1u;

        /*Type quarter size in bits.
        Example: uint32_t = 16. */
        static constexpr Size_t NUM_BITS_QUART = NUM_BITS >> 2u;

        /*Less significant bit number. Always 0. */
        static constexpr Size_t BIT_NUM_LS = NUM_0;

        /*Most significant bit number.
        Example: uint32 = 31.*/
        static constexpr Size_t BIT_NUM_MS = NUM_BITS - 1u;

        /*Half most significant bit number.
        Example: uint32 = 15.*/
        static constexpr Size_t BIT_NUM_MS_HALF = BIT_NUM_MS >> 1u;

        /*Quarter most significant bit number.
        Example: uint32 = 7.*/
        static constexpr Size_t BIT_NUM_MS_QUART = BIT_NUM_MS >> 2u;

        /*Less significant bit value. Always = 1. */
        static constexpr Value_t BIT_VALUE_LS = NUM_1;

        /*Most significant bit value.
        Example: uint8 = 128. */
        static constexpr Value_t BIT_VALUE_MS = NUM_1 << BIT_NUM_MS;

        /*All bits set to 1.
        Example: uint8 = 0b11111111. */
        static constexpr Value_t MASK_ALL = ~NUM_0;

        /*Mask from NUM_BITS.
        Example: uint8_t = 0b00000111, range 0 to 7 bits.*/
        static constexpr Value_t MASK_NUM_BITS = BIT_NUM_MS;

        /*Mask all but not less significant bit.
        Example: uint8 = 0b11111110. */
        static constexpr Value_t MASK_BIT_LS = ~BIT_VALUE_LS;

        /*Mask all but not most significant bit.
        Example: uint8 = 0b01111111. */
        static constexpr Value_t MASK_BIT_MS = ~BIT_VALUE_MS;

        /*Mask less significant byte with 0x0F.*/
        static constexpr Value_t MASK_BYTE_LS_0x0F = NUM_0F;

        /*Mask most significant byte with 0x0F.*/
        static constexpr Value_t MASK_BYTE_MS_0xF0 = NUM_0F << (NUM_BITS - NUM_BITS_4);

        /*Mask less significant byte with 0xFF.*/
        static constexpr Value_t MASK_BYTE_LS_0xFF = NUM_FF;

        /*Mask most significant byte with 0xFF.*/
        static constexpr Value_t MASK_BYTE_MS_0xFF = NUM_FF << (NUM_BITS - NUM_BITS_8);

        static constexpr bool IS_NUM_BYTES_1 = (NUM_BYTES == NUM_BYTES_1);
        static constexpr bool IS_NUM_BYTES_2 = (NUM_BYTES == NUM_BYTES_2);
        static constexpr bool IS_NUM_BYTES_4 = (NUM_BYTES == NUM_BYTES_4);
        static constexpr bool IS_NUM_BYTES_8 = (NUM_BYTES == NUM_BYTES_8);

        static constexpr bool IS_NUM_BITS_8  = (NUM_BITS == NUM_BITS_8);
        static constexpr bool IS_NUM_BITS_16 = (NUM_BITS == NUM_BITS_16);
        static constexpr bool IS_NUM_BITS_32 = (NUM_BITS == NUM_BITS_32);
        static constexpr bool IS_NUM_BITS_64 = (NUM_BITS == NUM_BITS_64);

        static constexpr bool IS_TYPE_ARITHMETIC = std::is_arithmetic<T>::value;
        static constexpr bool IS_TYPE_UNSIGNED   = std::is_unsigned<T>::value;
        static constexpr bool IS_TYPE_SIGNED     = std::is_signed<T>::value;
        static constexpr bool IS_TYPE_FLOATING   = std::is_floating_point<T>::value;

    };//Bitparams



}//fav



#endif