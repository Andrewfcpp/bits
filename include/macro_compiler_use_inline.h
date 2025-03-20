#ifdef _MSC_VER
#pragma once
#endif

#ifndef MACRO_COMPILER_USE_INLINE_H
#define MACRO_COMPILER_USE_INLINE_H



/** Attribute for compiler depend force inline functions.
    Enable inline:  #define COMPILER_USE_INLINE
    Disable inline: #undef COMPILER_USE_INLINE
    Example:
    use_inline bool return_true() { return true; }
*/
#ifdef COMPILER_USE_INLINE

#if defined(__clang__)
#define use_inline inline __attribute__((always_inline))

#elif defined(__GNUG__)
#define use_inline inline __attribute__((always_inline))

#elif defined(_MSC_VER)
#define use_inline __forceinline

#else
#error Unknown compiler.

#endif

#else //COMPILER_USE_INLINE

#define use_inline

#endif //COMPILER_USE_INLINE



#endif //MACRO_COMPILER_USE_INLINE_H
