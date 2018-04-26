#ifndef __GPIO_H__
#define __GPIO_H__

#include <types.h>

struct gpio_reg;

namespace stm32
{
	class Gpio {
		public:
			typedef enum {
				GpioBankA,
				GpioBankB,
				GpioBankC,
				GpioBankD,
				GpioBankE,
				GpioBankH,
				GpioBankF,
				GpioBankG
			}GpioBank;

			typedef enum {
				GpioInput,
				GpioOutput
			}GpioMode;

		private:
			struct gpio_reg *_bankRegisters;
			Gpio::GpioBank _bank;

		public:
			Gpio(Gpio::GpioBank bank);
			~Gpio(void);

			void set_mode(uint8_t io, Gpio::GpioMode mode);
			void set_value(uint8_t io, bool highLevel);
	};
};

#endif /* __GPIO_H__ */
