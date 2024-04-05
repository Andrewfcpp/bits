#ifdef _MSC_VER
#pragma once
#endif

#ifndef ENDIAN_H
#define ENDIAN_H

//#include <cstddef>
//#include <cstdint>



namespace fav
{
    /*Current platform endian type.*/
    class Endian
    {
    private:
        //41 42 43 44 = 'ABCD' hex ASCII code
        static constexpr std::uint32_t _ENDIAN_LITTLE{ 0x41424344u };

        //44 43 42 41 = 'DCBA' hex ASCII code
        static constexpr std::uint32_t _ENDIAN_BIG{ 0x44434241u };

        //Converts chars to uint32 on current platform
        static constexpr std::uint32_t _ENDIAN_CURRENT{ 'ABCD' };

    public:
        static constexpr bool IS_ENDIAN_LITTLE = (_ENDIAN_CURRENT == _ENDIAN_LITTLE);
        static constexpr bool IS_ENDIAN_BIG = (_ENDIAN_CURRENT == _ENDIAN_BIG);
        static constexpr bool IS_ENDIAN_UNKNOWN = (IS_ENDIAN_LITTLE == IS_ENDIAN_BIG);

        
        enum class EndianType : std::uint32_t { UNKNOWN, LITTLE, BIG };

        /*Get current platform endian type enum.*/
        static constexpr EndianType ENDIAN_TYPE = IS_ENDIAN_LITTLE ? EndianType::LITTLE : IS_ENDIAN_BIG ? EndianType::BIG : EndianType::UNKNOWN;

    };//Endian


}//fav



#endif
