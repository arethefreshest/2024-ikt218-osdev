#include "common.h"
#include "monitor.h"
#include "input.h"
#include "libc/stdio.h"
#include "interrupts.h"

// ISR for keyboard
void keyboard_isr(registers_t* regs, void* ctx) {
    uint8_t scancode = inb(0x60);
    char ascii = scancode_to_ascii(&scancode);
    if (ascii) {
        printf("%c", ascii);
    }
}

// Initialize the keyboard
void init_keyboard() {
    register_irq_handler(IRQ1, keyboard_isr, NULL);
}