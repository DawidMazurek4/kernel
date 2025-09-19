#include "vga.h"
#include "stdint.h"
#include "printf.h"



void printf(const char* fmt, ...){
    int* argp = (int*) &fmt;
    int state = PRINTF_STATE_START;
    int length = PRINTF_LENGTH_START;
    int radix = 10;
    int sign = 0;

    argp++;
    while(*fmt){
        switch(state){
        case PRINTF_STATE_START:
            if (*fmt == '%'){
                state = PRINTF_STATE_SPEC;
            }
            else{
                print(*fmt);
            }
            break;
        
        case PRINTF_STATE_SPEC:
            PRINTF_STATE_SPEC_:
                switch(*fmt){
                    case 'c':
                        print((char)*argp);
                        argp++;
                        break;
                    case 's':
                        print(*(const char *)argp);
                        break;
                    case '%':
                        print('%');
                        break;
                    case 'i':
                        radix = 10;
                        sign = true;
                        print_int(*(const char*)argp);
                        
                        
                        break;
                    default:
                        break;
                }
            state = PRINTF_STATE_START;
            length = PRINTF_LENGTH_START;
            radix = 10;
            sign = false;
            break;
            }
        fmt++;
    }
}

void print_int(int value) {
    char buffer[12]; // Enough for 32-bit int
    int i = 0;
    int negative = 0;

    if (value == 0) {
        print('0');
        return;
    }

    if (value < 0) {
        negative = 1;
        value = -value;
    }

    // Convert number to string in reverse
    while (value > 0) {
        buffer[i++] = (value % 10) + '0';
        value /= 10;
    }

    if (negative) {
        buffer[i++] = '-';
    }

    // Print in reverse
    while (i--) {
        print(buffer[i]);
    }
}
    

