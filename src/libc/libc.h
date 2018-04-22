#ifndef __LIBC_H__
#define __LIBC_H__

#include <types.h>

#ifdef __cplusplus
extern "C" {
#endif

void malloc_init(void);
void *malloc(size_t len);
void free(void *addr);

size_t strlen(const char *str);
void memset(void *dest, char c, size_t size);
void memcpy(void *dest, void *src, size_t len);

#ifdef __cplusplus
};
#endif

#endif //__LIBC_H__
