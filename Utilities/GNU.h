#pragma once

#if defined(__GNUG__)
#include <cmath>
#include <stdlib.h>
#endif

#if !defined(__APPLE__)
#include <malloc.h>
#endif

#if defined(__GNUG__)
#define _fpclass(x) std::fpclassify(x)
#define __forceinline __attribute__((always_inline))
#define _byteswap_ushort(x) __builtin_bswap16(x)
#define _byteswap_ulong(x) __builtin_bswap32(x)
#define _byteswap_uint64(x) __builtin_bswap64(x)
#define Sleep(x) usleep(x * 1000)
#define mkdir(x) mkdir(x, 0777)
#define INFINITE 0xFFFFFFFF
#define _CRT_ALIGN(x) __attribute__((aligned(x)))
#define InterlockedCompareExchange(ptr,new_val,old_val)  __sync_val_compare_and_swap(ptr,old_val,new_val)
#define InterlockedCompareExchange64(ptr,new_val,old_val)  __sync_val_compare_and_swap(ptr,old_val,new_val)
#if defined(__APPLE__)
// HACK - Relies on OS X's default alignment of 16 bytes.
// Not entirely sure if this is appropriate; posix_memalign
// would be better.
#define _aligned_malloc(size,alignment) malloc(size) 
#else
#define _aligned_malloc(size,alignment) memalign(alignment,size)
#endif
#define _aligned_free  free
#define DWORD int32_t
#endif

