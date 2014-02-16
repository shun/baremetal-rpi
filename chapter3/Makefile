CROSS=arm-unknown-eabi-

CC=$(CROSS)gcc
LD=$(CROSS)ld
OBJCOPY=$(CROSS)objcopy

STARTUP=startup.o
OBJS=main.o

# RPI lib
OBJS+=	rpi_lib/rpi_init.o \
		rpi_lib/bss/clearbss.o

CFLAGS=		-mfloat-abi=hard \
			-mlittle-endian
CFLAGS+=	-nostdinc \
			-fno-builtin
CFLAGS+=	-O2

INCDIR=		-I./

#####################################
all:	rpi-micon.img

rpi-micon.elf:	$(STARTUP) $(OBJS)
	$(LD) -static -nostdlib -T rpiMicon.lds $^ `$(CC) -print-libgcc-file-name` -o $@

.SUFFIXES:		.elf .img

.elf.img:
			$(OBJCOPY) -O binary $< $@

.c.o:
			$(CC) $(INCDIR) $(CFLAGS) -c $< -o $@

.S.o:
			$(CC) $(INCDIR) $(CFLAGS) -c $< -o $@

clean::
			$(RM) -f *.o *.img *.elf */*.o */*/*.o
			$(RM) -f tags *~

tags::
			ctags *.[chS]

