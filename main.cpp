
#include "tests/tests.h"

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <utility>

namespace A
{
    namespace
    {
        template<typename U> using enable_if_arithmetic_t = std::enable_if_t<std::is_arithmetic<U>::value>;
        template<typename U> using enable_if_integral_t = std::enable_if_t<std::is_integral<U>::value>;
        template<typename U> using enable_if_unsigned_t = std::enable_if_t<std::is_unsigned<U>::value>;
        template<typename U> using enable_if_signed_t = std::enable_if_t<std::is_signed<U>::value>;
    }

    //template<typename T, typename = enable_if_integral_t<T>>
    class B
    {
    public:
        template<typename U, typename = enable_if_integral_t<U>>
        static inline constexpr int get() { return 1; }
    };

    void test()
    {
        constexpr auto x = B::get<int>();
    }
}

int main(/*int argc, char** argv*/)
{
    std::cout << "Hello!" << '\n' << '\n';

    auto x = fav::Bithelpers::find_trail_one<std::uint64_t>(0x0000F00000000000ull);
    std::cout << '\n' << x << '\n';
    //x = fav::Bithelpers::pow2_lowest<std::uint64_t>(0x0000000000030000ull);
    //std::cout << '\n' << x << '\n';


    //Run all tests.
    DOCTEST_RUN;
    std::cout << '\n' << '\n';



    std::cout << '\n' << '\n' << "Bye, bye!" << '\n' << '\n';
    system("pause 0"); //std::cin.get();
    return 0;
}