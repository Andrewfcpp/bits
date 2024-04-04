
#ifdef _MSC_VER
#pragma once
#endif

#ifndef BITPARAMS_H
#define BITPARAMS_H



namespace fav
{
    /*Static constexpr type parameters.*/
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
        static constexpr Size_t NUM_BIT_LS = NUM_0;

        /*Most significant bit number.
        Example: uint32 = 31 bit.*/
        static constexpr Size_t NUM_BIT_MS = NUM_BITS - NUM_1;

        /*Less significant bit value. Always = 1. */
        static constexpr Value_t VALUE_BIT_LS = NUM_1;

        /*Most significant bit value.
        Example: uint8 = 128. */
        static constexpr Value_t VALUE_BIT_MS = NUM_1 << (NUM_BITS - 1u);

        /*Mask all but not less significant bit.
        Example: uint8 = 0b11111110. */
        static constexpr Value_t MASK_BIT_LS = ~VALUE_BIT_LS;

        /*Mask all but not most significant bit.
        Example: uint8 = 0b01111111. */
        static constexpr Value_t MASK_BIT_MS = ~VALUE_BIT_MS;

        static constexpr bool IS_8BIT  = (NUM_BYTES == 1u);
        static constexpr bool IS_16BIT = (NUM_BYTES == 2u);
        static constexpr bool IS_32BIT = (NUM_BYTES == 4u);
        static constexpr bool IS_64BIT = (NUM_BYTES == 8u);

        static constexpr Value_t MASK_BYTE_LS_0x0F = NUM_0F;
        static constexpr Value_t MASK_BYTE_MS_0xF0 = NUM_0F << (NUM_BITS - 4u);
        static constexpr Value_t MASK_BYTE_LS_0xFF = NUM_FF;
        static constexpr Value_t MASK_BYTE_MS_0xFF = NUM_FF << (NUM_BITS - 8u);

    };//Bitparams



}//fav



#endif