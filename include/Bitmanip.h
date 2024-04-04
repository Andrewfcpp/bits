
#ifdef _MSC_VER
#pragma once
#endif

#ifndef BITMANIP_H
#define BITMANIP_H



namespace fav
{
    //Bit manipulation.
    template<typename T = std::uint32_t>
    class Bitmanip
    {
    private:
        static constexpr T NUM_0 = static_cast<T>(0u);
        static constexpr T NUM_1 = static_cast<T>(1u);

    public:
        static_assert(std::is_arithmetic<T>::value, "Error! Wrong type. Use arithmetic type.");
        static_assert(!std::is_same<T, bool>::value, "Error! Boolean type not supported.");

        using Value_t = T
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

        /**Swap a <->b values. */
        static void swap(Value_t& a, Value_t& b) noexcept
        {
            std::swap(a, b);
        }

        static inline constexpr bool to_bool(Value_t v) noexcept
        {
            //return static_cast<bool>(v));
            return v != NUM_0;
        }



        //***********************************************************************/

        //Getter

        //***********************************************************************/



        /**Get single bit state at position. Returns 0 or 1.*/
        static Value_t get_bit(Value_t v, Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid_bitnum(bitnum)) { return v; }
            //Value_t res = NUM_1 << bitnum;
            //res &= v;
            //res >>= bitnum;
            //return res;
            v &= (NUM_1 << bitnum);
            v >>= bitnum;
            return v;
        }

        /**Get less significant bit state.*/
        static inline constexpr Value_t get_lsbit(Value_t v) noexcept
        {
            return v & Bp_t::VALUE_LSBIT;
        }

        /**Get most significant bit state.*/
        static inline constexpr Value_t get_msbit(Value_t v) noexcept
        {
            return (v & Bp_t::VALUE_MSBIT) >> Bp_t::NUM_MSBIT;
        }

        /*Get masked bits. Same as and(mask).
        0b10101010 value
        0b00111100 mask
        0b00101000 result */
        static inline constexpr Value_t get_masked(Value_t v, Value_t mask) noexcept
        {
            return v & mask;
        }

        //***********************************************************************/

        //Setter

        //***********************************************************************/



        /*Set all to 1.
        0b01010101 value
        0b11111111 result.*/
        static inline constexpr Value_t set_all(Value_t v) noexcept { return Bp_t::MASK_ALL; }

        /*Set single bit at position to 1.
        0b10101010 value, bitnum = 0
        0b10101011 result. */
        static inline Value_t set_bit(Value_t v, Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid_bitnum(bitnum)) { return v; }
            return v | (NUM_1 << bitnum);
        }

        /*Set single bit at position to 0 or 1.
        0b10101011 value, bitnum = 0, state = 0
        0b10101010 result. */
        static Value_t set_bit_state(Value_t v, Size_t bitnum, Value_t state) noexcept
        {
            if (Bp_t::is_invalid_bitnum(bitnum)) { return v; }
            state &= NUM_1;
            if(state) { v = set_bit(v, bitnum); }
            else { v =  clear_bit(v, bitnum); }
            return v;
        }

        /*Set less significant bit to 1.
        0b10101010 value
        0b10101011 result.*/
        static inline constexpr Value_t set_lsbit(Value_t v) noexcept
        {
            return v | Bp_t::VALUE_LSBIT;
        }

        /*Set most significant bit to 1.
        0b01010101 value
        0b11010101 result.*/
        static inline constexpr Value_t set_msbit(Value_t v) noexcept
        {
            return v | Bp_t::VALUE_MSBIT;
        }

        /*Set masked bits.
        0b10101010 value
        0b00111100 mask
        0b10111110 result */
        static inline constexpr Value_t set_masked(Value_t v, Value_t mask) noexcept {  return v |= mask; }

        //***********************************************************************/

        /*Toggle single bit.
        bitnum = 0
        0b10101010 value
        0b10101011 result
        0b10101010 repeat. */
        static inline void toggle_bit(Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid_bitnum(bitnum)) { return v; }
            return v ^ (NUM_1 << bitnum);
        }

        /*Toggle masked bits. Same as xor(mask).
        0b10101010 value
        0b00001111 mask
        0b10100101 result
        0b10101010 repeat. */
        static inline constexpr Value_t toggle_masked(Value_t mask) noexcept
        {
            return v ^ mask;
        }

        //***********************************************************************/

        /*Isolate single bit.
        0b10101010 value, bitnum = 1
        0b00000010 result. */
        static inline Value_t isolate_bit(Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid_bitnum(bitnum)) { return v; }
            return v & (NUM_1 << bitnum);
        }

        /*Isolate masked bits. Same as and(mask).
        0b10101010 value
        0b00001111 mask
        0b00001010 result. */
        static inline constexpr Value_t isolate_masked(Value_t mask) noexcept
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
        0b00101010 result. */
        static inline Value_t clear_bit(Value_t v, Size_t bitnum) noexcept
        {
            if (Bp_t::is_invalid_bitnum(bitnum)) { return v; }
            v &= (~(NUM_1 << bitnum));
            return v;
        }

        /*Clear less significant bit.
        0b01010101 value
        0b11010100 result.*/
        static inline constexpr  Value_t clear_lsbit(Value_t v) noexcept
        {
            return v & Bp_t::VALUE_LSBIT;
        }

        /*Clear most significant bit.
        0b10101010 value
        0b00101011 result.*/
        static inline constexpr  Value_t clear_msbit(Value_t v) noexcept
        {
            return v & Bp_t::VALUE_MSBIT;
        }


        /*Clear masked bits.
        0b10101010 value
        0b00111100 mask
        0b10000010 result. */
        static inline constexpr Value_t clear_mask(Value_t v, Value_t mask) noexcept
        {
            return (v & (~mask));
        }



        //***********************************************************************/

        //Fill

        //***********************************************************************/




        //***********************************************************************/

        //Conditional

        //***********************************************************************/



    };//Bitmanip

}//fav



#if 0
/*Class for bit manipulations.*/
template<typename T>
class Bitman
{
private:
    static_assert(std::is_integral<T>::value, "Error! Wrong type.");
    //static_assert(std::is_unsigned<T>::value, "Error! Integral type only.");
    static constexpr T NUM_0 = static_cast<T>(0u);
    static constexpr T NUM_1 = static_cast<T>(1u);

public:
    using value_type = T;
    using size_type = std::size_t;
    using Self_t = Bitman;
    using Param_t = Bitparams<value_type>;

public:

    /*Get single bit state at position.
    Returns 0 or 1.*/
    inline value_type get_bit(size_type pos) const noexcept
    {
        pos &= Param_t::NUM_BITS_MASK;
        value_type res = NUM_1 << pos;
        res &= bits;
        res >>= pos;
        return pos;
    }

    inline value_type get_bits() const noexcept
    {
        return bits;
    }

    inline void set_bits(const value_type value) noexcept
    {
        bits = value;
    }

    /*Set single bit at position to 1.
    0b10101010 value, pos = 0
    0b10101011 result. */
    inline void set_bit(size_type pos) noexcept
    {
        pos &= Param_t::NUM_BITS_MASK;
        bits |= (NUM_1 << pos);
    }

    /*Set single bit at position to 0 or 1.
    0b10101011 value, pos = 0, on = 0
    0b10101010 result. */
    void set_bit(size_type pos, value_type on) noexcept
    {
        pos &= Param_t::NUM_BITS_MASK;
        on &= Param_t::VALUE_LSB;
        if(on) { set_bit(pos); }
        else { clear(pos); }
    }

    /*Set masked bits.
    0b10101010 value
    0b00111100 mask
    0b10111110 result */
    inline void set_mask(const value_type mask) noexcept
    {
        bits |= mask;
    }

    /*Set less significant bit to 1.
    0b10101010 value
    0b10101011 result.*/
    inline void set_lsb() noexcept
    {
        bits |= Param_t::VALUE_LSB;
    }

    /*Set most significant bit to 1.
    0b01010101 value
    0b11010101 result.*/
    inline void set_msb() noexcept
    {
        bits |= Param_t::VALUE_MSB;
    }

    /*Set all to 1.
    0b01010101 value
    0b11111111 result.*/
    inline void set_all() noexcept
    {
        bits = Param_t::MASK_ALL;
    }

    /*Clear single bit to 0.
    0b10101010 value, pos = 7
    0b00101010 result. */
    inline void clear(size_type pos) noexcept
    {
        pos &= Param_t::NUM_BITS_MASK;
        bits &= (~(NUM_1 << pos));
    }

    /*Clear masked bits.
    0b10101010 value
    0b00111100 mask
    0b10000010 result. */
    inline void clear_mask(const value_type mask) noexcept
    {
        bits &= (~mask);
    }

    /*Clear less significant bit.
    0b01010101 value
    0b11010100 result.*/
    inline void clear_lsb() noexcept
    {
        bits &= Param_t::MASK_LSB;
    }

    /*Clear most significant bit.
    0b10101010 value
    0b00101011 result.*/
    inline void clear_msb() noexcept
    {
        bits &= Param_t::MASK_MSB;
    }

    /*Clear all to 0.
    0b10101010 value
    0b00000000 result.*/
    inline void clear_all() noexcept
    {
        bits = NUM_0;
    }

    /*Bitwise AND.
    0b10101010 value
    0b00001111 mask
    0b00000101 result. */
    inline void use_and(const value_type mask) noexcept
    {
        bits &= mask;
    }

    /*Bitwise OR.
    0b10101010 value
    0b00001111 mask
    0b00001111 result. */
    inline void use_or(const value_type mask) noexcept
    {
        bits |= mask;
    }

    /*Bitwise XOR.
    0b10101010 value
    0b00001111 mask
    0b00000101 result. */
    inline void use_xor(const value_type mask) noexcept
    {
        bits ^= mask;
    }

    /*Bitwise inversion.
    0b10101010 value
    0b01010101 result. */
    inline void use_inverse() noexcept
    {
        bits = ~bits;
    }

    /*Toggle single bit.
    pos = 0
    0b10101010 value
    0b10101011 result
    0b10101010 repeat. */
    inline void toggle(size_type pos) noexcept
    {
        pos &= Param_t::NUM_BITS_MASK;
        bits ^= (NUM_1 << pos);
    }

    /*Toggle masked bits. Same as set_xor(mask).
    0b10101010 value
    0b00001111 mask
    0b10100101 result
    0b10101010 repeat. */
    inline void toggle_masked(const value_type mask) noexcept
    {
        bits ^= mask;
    }

    /*Isolate single bit.
    0b10101010 value, pos = 1
    0b00000010 result. */
    void isolate(size_type pos) noexcept
    {
        pos &= Param_t::NUM_BITS_MASK;
        bits &= (NUM_1 << pos);
    }

    /*Isolate masked bits. Same as set_and(mask).
    0b10101010 value
    0b00001111 mask
    0b00001010 result. */
    inline void isolate_masked(const value_type mask) noexcept
    {
        bits &= mask;
    }

    /*Fill less significant bits by 1.
    0b10101010 value
    0b00001000 pos = 3 inclusive
    0b10101111 result.*/
    void fill_lsb_1(size_type pos) noexcept //TODO fill_lsb_1
    {
        pos &= Param_t::NUM_BITS_MASK;
        //if (pos == NUM_0) { bits = NUM_1; return; }

        value_type res = NUM_1;
        res <<= pos;
        value_type tmp = res;
        --res;
        res |= tmp;
        bits |= res;
    }

    /*Fill most significant bits by 1.
    0b10101010 value
    0b00001000 pos = 3 inclusive,
    0b11111010 result.*/
    void fill_msb_1(size_type pos) noexcept //TODO fill_msb_1
    {
        pos &= Param_t::NUM_BITS_MASK;
        //if (pos == NUM_0) { bits = Param_t::MASK_ALL; return; }

        value_type res = NUM_1;
        res << pos;
        --res;
        res = ~res;
        bits |= res;
    }

    /*Fill less significant bits by 0.
    0b10101010 value
    0b00001000 pos = 3 inclusive,
    0b10100000 result.*/
    void fill_lsb_0(size_type pos) noexcept //TODO fill_lsb_0
    {
        //pos &= Param_t::NUM_BITS_MASK;
        //value_type res = Param_t::MASK_ALL;
        //res <<= pos;
        //res &= bits;
        //bits = res;
    }

    /*Fill less significant bits by 0.
    0b10101010 value
    0b00001000 pos = 3 inclusive,
    0b00000010 result.*/
    void fill_msb_0(size_type pos) noexcept //TODO fill_msb_0
    {
        //pos &= Param_t::NUM_BITS_MASK;
        //value_type res = Param_t::MASK_ALL;
        //res <<= pos;
        //res &= bits;
        //bits = res;
    }

    /*Test if bit pos is set to 1.*/
    inline bool is_set(size_type pos) const noexcept
    {
        pos &= Param_t::NUM_BITS_MASK;
        return (bits >> pos) & NUM_1;
    }

    /*Test if any bit is set to 1.*/
    inline bool is_set_any() const noexcept
    {
        return bits > NUM_0;
    }

    /*Test if all bit is set.*/
    inline bool is_set_all() const noexcept
    {
        return bits == Param_t::MASK_ALL;
    }

    /*Test if less significant bit is set.*/
    inline bool is_set_lsb() const noexcept
    {
        return (bits & Param_t::VALUE_LSB) != NUM_0;
    }

    /*Test if most significant bit is set.*/
    inline bool is_set_msb() const noexcept
    {
        return (bits & Param_t::VALUE_MSB) != NUM_0;
    }

    /*Test if bit pos is set to 0.*/
    inline bool is_clear(size_type pos) const noexcept
    {
        pos &= Param_t::NUM_BITS_MASK;
        return (bits & (NUM_1 << pos)) == NUM_0;
    }

    /*Test if any bit is clear.*/
    inline bool is_clear_any() const noexcept
    {
        return bits < Param_t::MASK_ALL;
    }

    /*Test if all bits is 0.*/
    inline bool is_clear_all() const noexcept
    {
        return bits == NUM_0;
    }

    /*Test if less significant bit is clear.*/
    inline bool is_clear_lsb() const noexcept
    {
        return (bits & Param_t::VALUE_LSB) == NUM_0;
    }

    /*Test if most significant bit is clear.*/
    inline bool is_clear_msb() const noexcept
    {
        return (bits & Param_t::VALUE_MSB) == NUM_0;
    }

    /*Cast to other type.*/
    template<typename Cast_t>
    Bitman<Cast_t> cast_to() const noexcept
    {
        static_assert(std::is_integral<Cast_t>::value, "Error! Wrong type.");
        return Bitman<Cast_t>{ static_cast<Cast_t>(bits) };
    }

private:
    value_type bits{};

    static constexpr void advance(size_type& pos) noexcept
    {
        pos &= Param_t::NUM_BITS_MASK;
    }
};



///** Fill less significant bits with 0.
//fill_0_lsb<std::uint8_t>(4) returns 0b11110000 */
//template<typename T>
//constexpr T fill_0_lsb(std::size_t num) noexcept
//{
//    return is_bit_valid<T>(num) ? (bit_mask<T> << num) : 0;
//}
//
//
//
///** Fill most significant bits with 0.
//fill_0_msb<std::uint8_t>(4) returns 0b00001111 */
//template<typename T>
//constexpr T fill_0_msb(std::size_t num) noexcept
//{
//    return is_bit_valid<T>(num) ? (bit_mask<T> >> num) : 0;
//}
//
//
//
///** Fill less significant bits with 1.
//fill_1_lsb<std::uint8_t>(4) returns 0b00001111 */
//template<typename T>
//constexpr T fill_1_lsb(std::size_t num) noexcept
//{
//    return is_bit_valid<T>(num) ? ~(bit_mask<T> << num) : 0;
//}
//
//
//
///** Fill most significant bits with 1.
//fill_1_msb<std::uint8_t>(4) returns 0b11110000 */
//template<typename T>
//constexpr T fill_1_msb(std::size_t num) noexcept
//{
//    return is_bit_valid<T>(num) ? ~(bit_mask<T> >> num) : 0;
//}

#endif // if 0

#endif