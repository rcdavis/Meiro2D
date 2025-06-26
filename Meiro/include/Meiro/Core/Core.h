#pragma once

typedef unsigned int uint32;
typedef int int32;

typedef float f32;
typedef double f64;

#if MEIRO_ASSERTS_ENABLED
#   include <cassert>
#   define MEIRO_ASSERT(x, ...) if(!(x)) {MEIRO_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); assert(x);}
#   define MEIRO_CORE_ASSERT(x, ...) if(!(x)) {MEIRO_CORE_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); assert(x);}
#else
#   define MEIRO_ASSERT(x, ...) ;
#   define MEIRO_CORE_ASSERT(x, ...) ;
#endif

#define BIT(x) (1 << (x))
