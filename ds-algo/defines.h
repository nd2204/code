#ifndef DEFINES_H
#define DEFINES_H

/** @brief Static assertion */
#if (defined(__clang__) || defined(__GNUC__)) && !defined(__cplusplus)
    #define STATIC_ASSERT _Static_assert
#else
    #define STATIC_ASSERT static_assert
#endif

typedef signed char         i8;
typedef signed short        i16;
typedef signed int          i32;
typedef signed long long    i64;

typedef unsigned char         u8;
typedef unsigned short        u16;
typedef unsigned int          u32;
typedef unsigned long long    u64;

typedef float   f32;
typedef double  f64;

typedef unsigned char       b8;

#define TRUE 1
#define FALSE 0

STATIC_ASSERT(sizeof(i8) == 1,  "Kich thuoc cua kieu signed char != 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "Kich thuoc cua kieu signed short != 2 byte");
STATIC_ASSERT(sizeof(i32) == 4, "Kich thuoc cua kieu signed char != 4 byte");
STATIC_ASSERT(sizeof(i64) == 8, "Kich thuoc cua kieu signed long long != 8 byte");

STATIC_ASSERT(sizeof(u8) == 1,  "Kich thuoc cua kieu unsigned char != 1 bytes");
STATIC_ASSERT(sizeof(u16) == 2, "Kich thuoc cua kieu unsigned short != 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "Kich thuoc cua kieu unsigned char != 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "Kich thuoc cua kieu unsigned long long != 8 bytes");

#endif // !DEFINES_H
