@ startup
		.global _start
		.align
_start:
		// set the stack pointer for SVC mode
		ldr		r0,		=0x000000d3
		msr		cpsr,	r0
		ldr		sp,		=0x06400000

		// call main function
		bl		main

		// end
		b		.
