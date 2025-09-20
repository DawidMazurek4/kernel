#include "vga.h"
#include "gdt.h"
#include "interrupts/idt.h"
#include "timer.h"
#include "keyboard.h"
#include "printf.h"
#include "multiboot.h"
void kmain(uint32_t magic, struct multiboot_info* bootInfo);
void kmain(uint32_t magic, struct multiboot_info* bootInfo){
    initGdt();
    // print("it is wodddrking");
    initIdt();
    initTimer();
    initKeyboard();
    // initMemory(bootInfo);
    for(;;);
}