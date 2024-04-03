
#ifdef _MSC_VER
#pragma once
#endif

#ifndef ASSERT_MSG_H
#define ASSERT_MSG_H

#include <cstddef>
#include <cstdint>
#include <iostream>



#ifndef NDEBUG //Debug mode

//Assert immediately.
// if (1 == 0) { ASSERT_FALSE; }
#define ASSERT_FALSE __assert_expr_msg("", false, __FILE__, __LINE__, "ASSERT_FALSE")

// ASSERT_EXPR(1 == 0)
#define ASSERT_EXPR(expr) __assert_expr_msg(#expr, expr, __FILE__, __LINE__, "EXPRESSION ERROR")

// ASSERT_EXPR_MSG(1 == 0, "Not equal!")
#define ASSERT_EXPR_MSG(expr, msg) __assert_expr_msg(#expr, expr, __FILE__, __LINE__, msg)

//For functions that returns boolean true
// ASSERT_FN(is_empty())
#define ASSERT_FN(fn) __assert_expr_msg(#fn, !fn, __FILE__, __LINE__, "TRUE")

//For functions that returns boolean true
// ASSERT_FN(is_empty(), "Array is empty!")
#define ASSERT_FN_MSG(fn, msg) __assert_expr_msg(#fn, !fn, __FILE__, __LINE__, msg)

#else //Release mode
#define ASSERT_FALSE                /*NOTHING*/
#define ASSERT_EXPR(Expr)           /*NOTHING*/
#define ASSERT_EXPR_MSG(Expr, Msg)  /*NOTHING*/
#define ASSERT_FN(fn)               /*NOTHING*/
#define ASSERT_FN_MSG(fn, msg)      /*NOTHING*/
#endif //NDEBUG

void __assert_expr_msg(const char* expr_str, bool expr, const char* file, int line, const char* msg = "")
{
    if (!expr)
    {
        std::cerr << '\n'
                  << "Assert failed: " << msg << '\n'
                  << "Expected:      " << expr_str << '\n'
                  << "Line:          " << line << '\n'
                  << "Source:        " << file << '\n' <<'\n';

        __debugbreak(); //abort();

    }
}

#endif