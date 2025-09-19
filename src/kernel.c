#include "vga.h"
#include "gdt.h"
#include "interrupts/idt.h"
#include "timer.h"
#include "keyboard.h"
void kmain(void);
void kmain(void){
    initGdt();
    print("it is wodddrking");
    initIdt();
    // initTimer();
    initKeyboard();
    for(;;);
}