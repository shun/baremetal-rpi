#include "rpi_lib/rpi.h"
#include "peripheralsaddr.h"
#include "mydef.h"

volatile uint64 get_systime()
{
	uint64 tm;
	uint32 chi, clo;

	chi = *(volatile uint32 *)SYST_CHI;
	clo = *(volatile uint32 *)SYST_CLO;

	if (chi != *(volatile uint32 *)SYST_CHI)
	{
		chi = *(volatile uint32 *)SYST_CHI;
		clo = *(volatile uint32 *)SYST_CLO;
	}

	tm = chi;
	tm = tm << 32;
	tm += clo;

	return tm;	
}

void delay_ms(uint32 delay)
{
	uint64 alermtime;
	alermtime = get_systime() + delay * 1000;
	while (get_systime() < alermtime);

	return;
}

int main()
{
	rpi_init();

	// init system timer
	*(volatile uint32 *)SYST_CHI = 0;
	*(volatile uint32 *)SYST_CLO = 0;
	
	// set GPIO16 for output
	*(volatile uint32 *)GPFSEL1 = 0x01 << (3 * 6);

	while (1)
	{
		delay_ms(1000);
		
		// set Lo for GPIO16
		*(volatile uint32 *)GPCLR0 = 0x01 << 16;
		delay_ms(500);
		
		// set Hi for GPIO16
		*(volatile uint32 *)GPSET0 = 0x01 << 16;
		delay_ms(500);

		// set Lo for GPIO16
		*(volatile uint32 *)GPCLR0 = 0x01 << 16;
		delay_ms(200);
		
		// set Hi for GPIO16
		*(volatile uint32 *)GPSET0 = 0x01 << 16;
		delay_ms(200);

		// set Lo for GPIO16
		*(volatile uint32 *)GPCLR0 = 0x01 << 16;
		delay_ms(200);
		
		// set Hi for GPIO16
		*(volatile uint32 *)GPSET0 = 0x01 << 16;
		delay_ms(200);

	}
	while (1);
	
	return 0;
}
