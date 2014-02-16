#include "rpi_lib/rpi.h"
#include "peripheralsaddr.h"
#include "mydef.h"

int main()
{
	rpi_init();

	// set GPIO16 for output
	*(volatile uint32 *)GPFSEL1 = 0x01 << (3 * 6);

	// set Lo for GPIO16
	*(volatile uint32 *)GPCLR0 = 0x01 << 16;

	while (1);
	
	return 0;
}
