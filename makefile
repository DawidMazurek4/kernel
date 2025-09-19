gcc = /usr/opt/cross/bin/i686-elf-gcc
flags = -ffreestanding -Wall -Wextra -g -O2

all: clean kernel boot image

clean:
	rm -f *.o

kernel:
	$(gcc) $(flags) -c src/kernel.c -o kernel.o
	$(gcc) $(flags) -c src/vga.c -o vga.o
	$(gcc) $(flags) -c src/gdt.c -o gdt.o
	$(gcc) $(flags) -c src/util.c -o util.o
	$(gcc) $(flags) -c src/interrupts/idt.c -o idt.o
	$(gcc) $(flags) -c src/timer.c -o timer.o
	$(gcc) $(flags) -c src/keyboard.c -o keyboard.o
	

boot:
	nasm -f elf32 src/boot.s -o boot.o
	nasm -f elf32 src/gdt.s -o gdts.o
	nasm -f elf32 src/interrupts/idt.s -o idts.o

image:
	ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o vga.o gdt.o gdts.o util.o idt.o idts.o timer.o keyboard.o
	mv kernel cwlos/boot/kernel
	grub-mkrescue -o kernel.iso cwlos/
	rm *.o