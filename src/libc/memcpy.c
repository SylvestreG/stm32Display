#include <types.h>

void
memcpy(void *dest, void *src, size_t len)
{
    for (size_t i = 0; i < len; i++) {
      ((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
    }
}
