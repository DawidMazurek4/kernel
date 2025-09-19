#include "stdint.h"
#include "util.h"
#include "interrupts/idt.h"
#include "printf.h"
#include "keyboard.h"
void initKeyboard(){
    irq_install_handler(1,&keyboardHandler);
}

void keyboardHandler(struct InterruptRegisters *regs){
    char scanCode = inPortB(0x60) & 0x7F; // pressed key
    char press = inPortB(0x60) & 0x80; // down up

    printf("%i \n", scanCode);

}