
extern "C"{
    #include "libc/system.h"
    #include "common.h"
    #include "interrupts.h"
    #include "input.h"
}

extern "C" int kernel_main(void);
int kernel_main(){

    
    // Set up interrupt handlers
    register_interrupt_handler(3, [](registers_t* regs, void* context) {
        printf("Interrupt 3 - OK\n");
    }, NULL);

    register_interrupt_handler(4, [](registers_t* regs, void* context) {
        printf("Interrupt 4 - OK\n");
    }, NULL);

    register_interrupt_handler(14, [](registers_t* regs, void* context) {
        uint32_t faulting_address;
        __asm__ __volatile__("mov %%cr2, %0" : "=r" (faulting_address));

        int32_t present = !(regs->err_code & 0x1); // Page not present
        int32_t rw = regs->err_code & 0x2;           // Write operation?
        int32_t us = regs->err_code & 0x4;           // Processor was in user-mode?
        int32_t reserved = regs->err_code & 0x8;     // Overwritten CPU-reserved bits of page entry?
        int32_t id = regs->err_code & 0x10;          // Caused by an instruction fetch?

        printf("Page fault! ("); 
        if (present)
            printf("present");
        if (rw)
            printf("read-only");
        if (us)
            printf("user-mode");
        if (reserved)
            printf("reserved");
        printf(")\n\n");
    }, NULL);

    // Trigger interrupts to test the handlers
    asm volatile("int $0x3");
    asm volatile("int $0x4");

    // Enable interrupts
    asm volatile("sti");

    // Register IRQ handler for keyboard (IRQ1)
    register_irq_handler(IRQ1, [](registers_t*, void*) {
        // Read from the keyboard
        unsigned char scancode = inb(0x60);
        char f = scancode_to_ascii(&scancode);

        // Print the character
        printf("%c", f);

        // Acknowledge the IRQ
        asm volatile("cli");
    }, NULL);

    // Main loop
    printf("Kernel main loop\n");
    while (true)
    {
        // Kernel main tasks
    }
    //  This part of the code will never be reached
    printf("Done!!!\n");
    return 0;
}