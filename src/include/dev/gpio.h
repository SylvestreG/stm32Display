#ifndef __GPIO_H__
#define __GPIO_H__

#include <sys/types.h>

#pragma pack(push,1)
struct gpio_reg {
	volatile uint32_t mode;
	volatile uint32_t output_type;
	volatile uint32_t output_speed;
	volatile uint32_t pull_up_down;
	volatile uint32_t input_data;
	volatile uint32_t output_data;
	volatile uint32_t bit_set_reset;
	volatile uint32_t config_lock;
	volatile uint32_t alternate_fn_high;
	volatile uint32_t bit_reset;
};
#pragma pack(pop)

typedef enum {
	GpioBankA,
	GpioBankB,
	GpioBankC,
	GpioBankD,
	GpioBankE,
	GpioBankH,
	GpioBankF,
	GpioBankG
} gpio_bank;

typedef enum {
	GpioInput,
	GpioOutput
} gpio_mode;

void gpio_set_mode(gpio_bank, uint8_t pin, gpio_mode);
void gpio_set_value(gpio_bank, uint8_t pin, bool);
//bool gpio_get_value(gpio_bank, uint8_t pin);

#endif /* __GPIO_H__ */
