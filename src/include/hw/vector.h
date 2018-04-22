#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <types.h>

#define NB_IRQ		20

struct cortex_m3_vector {
	uint32_t sp;
	void (*reset)(void);
	void (*nmi)(void);
	void (*hardfault)(void);
	void (*memfault)(void);
	void (*busfault)(void);
	void (*usagefault)(void);
	uint32_t reserved[5];
	uint32_t svcall;
	uint32_t debug[2];
	uint32_t pendsv;
	uint32_t systick;
	uint32_t irq[NB_IRQ];
};

#endif /* __VECTOR_H__ */
