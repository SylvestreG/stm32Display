#ifndef __LIBKERN_H__
#define __LIBKERN_H__

#include <sys/libkern.h>

void memset(void *dst, void *src, size_t len);
void memcpy(void *dst, void *src, size_t len);
size_t strlen(const char *c);

#endif /* __LIBKERN_H__ */
