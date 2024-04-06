//    Author: Andrewfcpp
//    Git: https://github.com/Andrewfcpp
//    Date:   2024, April, 6


#ifdef _MSC_VER
#pragma once
#endif

#ifndef BITCODEC_H
#define BITCODEC_H

//#include <cstddef>
//#include <cstdint>
//#include <utility>



namespace fav
{

    //***********************************************************************/
    //Codec 4 bit.
    //***********************************************************************/



    /*Codec_4bit could be used to decode/encode nibbled values.
    Codec_4bit<value_type>::decode(value) example:
    uint8  0x01               -> 0x01
    uint16 0x0102             -> 0x0012
    uint32 0x01020304         -> 0x00001234
    uint64 0x0102030405060708 -> 0x0000000012345678.

    Codec_4bit<value_type>::encode(value) example:
    uint8  0x01               -> 0x01             
    uint16 0x0012             -> 0x0102           
    uint32 0x00001234         -> 0x01020304        
    uint64 0x0000000012345678 -> 0x0102030405060708.

    Using example:
    using Value_t = std::uint32_t;
    using Codec_t = Codec_4bit<Value_t>;
    Value_t a1 = 0x01020304u;
    a1 = Codec_t::decode(a1); //a1 = 0x00001234u;
    a1 = Codec_t::encode(a1); //a1 = 0x01020304u*/
    template<typename T>
    class Codec_4bit
    {
    public:
        static_assert(std::is_unsigned<T>::value, "Error! Use unsigned type.");

        using Value_t = T;
        using Size_t = std::size_t;

        static Value_t decode(Value_t value) noexcept
        {
            if (is_small_value(value)) { return value; }
            return process<true>(value);
        }

        static Value_t encode(Value_t value) noexcept
        {
            if (is_small_value(value)) { return value; }
            return process<false>(value);
        }

    private:
        static constexpr Value_t NUM_0 = 0u;
        static constexpr Size_t  NUM_BYTES = sizeof(Value_t);
        static constexpr Size_t  NUM_BITS = NUM_BYTES * static_cast<Size_t>(8u);
        static constexpr Value_t MASK_ALL = ~NUM_0;
        static constexpr bool    IS_8BIT = (NUM_BYTES == 1u);
        static constexpr Value_t MASK_ENCODED = static_cast<Value_t>(0x0F0F0F0F0F0F0F0FULL);
        static constexpr Value_t MASK_DECODED = MASK_ALL >> (NUM_BITS / 2u);
        static constexpr Value_t MASK_BYTE = static_cast<Value_t>(0x0Fu);

        static inline constexpr bool is_small_value(Value_t value) noexcept
        {
            return value <= MASK_BYTE;
        }

        /*Implementation.
        Decode mode: is_mode_decode = true
        Encode mode: is_mode_decode = false.*/
        template<bool is_mode_decode>
        static Value_t process(Value_t value) noexcept
        {
            static constexpr Value_t MASK_VALUE = (is_mode_decode ? MASK_ENCODED : MASK_DECODED);
            static constexpr Size_t  SHIFT_A = (is_mode_decode ? 8u : 4u);
            static constexpr Size_t  SHIFT_B = (is_mode_decode ? 4u : 8u);

            //Remove unused bits.
            value &= MASK_VALUE;

            Value_t result = 0u;
            Size_t shift_counter = 0u;
            Value_t value_copy = 0u;

            //Calculate value. Number of iterations <= NUM_BYTES.
            while (value > 0u)
            {
                value_copy = value;
                value_copy &= MASK_BYTE;
                value_copy <<= shift_counter;
                result |= value_copy;
                value >>= SHIFT_A;
                shift_counter += SHIFT_B;
            }

            return result;
        }
    };//Codec_4bit



    //***********************************************************************/
    //Codec 7 bit.
    //***********************************************************************/



    /*Codec_7bit could be used to decode/encode MIDI values.
    Codec_7bit<value_type>::decode(value) example:
    uint8  0x7F               -> 0x7F
    uint16 0x7F7F             -> 0x3FFF
    uint32 0x7F7F7F7F         -> 0x0FFFFFFF
    uint64 0x7F7F7F7F7F7F7F7F -> 0x00FFFFFFFFFFFFFF

    Codec_7bit<value_type>::encode(value) example:
    uint8  0x7F               -> 0x7F
    uint16 0x3FFF             -> 0x7F7F
    uint32 0x0FFFFFFF         -> 0x7F7F7F7F
    uint64 0x00FFFFFFFFFFFFFF -> 0x7F7F7F7F7F7F7F7F

    Using example:
    using Value_t = std::uint32_t;
    using Codec_t = Codec_7bit<Value_t>;
    Value_t a1 = 0x7F7F7F7Fu;
    a1 = Codec_t::decode(a1); //a1 = 0x0FFFFFFFu;
    a1 = Codec_t::encode(a1); //a1 = 0x7F7F7F7F*/
    template<typename T>
    class Codec_7bit
    {
    public:
        static_assert(std::is_unsigned<T>::value, "Error! Use unsigned type.");

        using Value_t = T;
        using Size_t = std::size_t;

        static Value_t decode(Value_t value) noexcept
        {
            if (is_small_value(value)) { return value; }
            return process<true>(value);
        }

        static Value_t encode(Value_t value) noexcept
        {
            if (is_small_value(value)) { return value; }
            return process<false>(value);
        }

    private:
        static constexpr Value_t NUM_0 = 0u;
        static constexpr Size_t  NUM_BYTES = sizeof(Value_t);
        static constexpr Size_t  NUM_BITS = NUM_BYTES * 8u;
        static constexpr bool    IS_8BIT = NUM_BYTES == 1u;
        static constexpr Value_t MASK_ALL = ~NUM_0;
        static constexpr Value_t MASK_ENCODED = static_cast<Value_t>(0x7F7F7F7F7F7F7F7Full);
        static constexpr Value_t MASK_DECODED = MASK_ALL >> NUM_BYTES;
        static constexpr Value_t MASK_BYTE = static_cast<Value_t>(0x7Fu);
        
        static inline constexpr bool is_small_value(Value_t value) noexcept
        {
            return value <= MASK_BYTE;
        }

        /*Implementation.
        Decode mode: is_mode_decode = true
        Encode mode: is_mode_decode = false.*/
        template<bool is_mode_decode>
        static Value_t process(Value_t value) noexcept
        {
            static constexpr Value_t MASK_VALUE = (is_mode_decode ? MASK_ENCODED : MASK_DECODED);
            static constexpr Size_t  SHIFT_A = (is_mode_decode ? 8u : 7u);
            static constexpr Size_t  SHIFT_B = (is_mode_decode ? 7u : 8u);

            //Remove unused bits.
            value &= MASK_VALUE;

            Value_t result = 0u;
            Size_t shift_counter = 0u;
            Value_t value_copy = 0u;

            //Calculate value. Number of iterations <= NUM_BYTES.
            while (value > 0u)
            {
                value_copy = value;
                value_copy &= MASK_BYTE;
                value_copy <<= shift_counter;
                result |= value_copy;
                value >>= SHIFT_A;
                shift_counter += SHIFT_B;
            }

            return result;
        }
    };//Codec_7bit



    //***********************************************************************/
    //Codec BCD (Binary Coded Decimal).
    //***********************************************************************/



    /*Binary coded decimal converter.*/
    template<typename T>
    class Codec_bcd
    {
    public:
        static_assert(std::is_unsigned<T>::value, "Error! Use unsigned type.");

        using Value_t = T;
        using Size_t = std::size_t;

    private:
        static constexpr Size_t  NUM_BYTES = sizeof(Value_t);
        static constexpr Size_t  NUM_BITS = NUM_BYTES * static_cast<Size_t>(8u);
        static constexpr Value_t MASK_BYTE = static_cast<Value_t>(0x0Fu);
        static constexpr Value_t DECIMAL = static_cast<Value_t>(10u);
        static constexpr Value_t SHIFT = static_cast<Value_t>(4u);

        static inline constexpr bool is_small_value(Value_t value) noexcept
        {
            return value <= DECIMAL;
        }

    public:
        /*Convert BCD to decimal.*/
        static Value_t decode(Value_t value) noexcept
        {
            if (is_small_value(value)) { return value; }

            Value_t result = 0u;
            Value_t multiplier = 1u;
            Value_t value_copy = 0u;

            while (value > 0u)
            {
                value_copy = value;
                value_copy &= MASK_BYTE;
                value_copy *= multiplier;
                result += value_copy;
                multiplier *= DECIMAL;
                value >>= SHIFT;
            }

            return result;
        }

        /*Convert decimal to BCD.*/
        static Value_t encode(Value_t value) noexcept
        {
            if (is_small_value(value)) { return value; }

            Value_t result = 0u;
            Size_t shift_counter = 0u;
            Value_t value_copy = 0u;

            while (value > 0u)
            {
                value_copy = (value % DECIMAL);
                value_copy <<= shift_counter;
                result |= value_copy;
                shift_counter += SHIFT;
                value /= DECIMAL;
            }

            return result;
        }

    };//Codec_bcd



}//fav



#endif