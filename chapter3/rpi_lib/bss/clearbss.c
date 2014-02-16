#include "mydef.h"

void clearBss()
{
	extern void * __bss_start;
	extern void * __bss_end;

	uint32 *p;
	uint32 *start = (uint32 *)&__bss_start;
	uint32 *end = (uint32 *)&__bss_end;

	for (p = start; p < end; p++)
	{
		*p = 0x00;
	}
}
