#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include <multiboot2.h>
#include "libc/system.h"
#include "descriptor_tables.h"  // Inkluderer header file for gdt filen
#include "common.h"
#include "monitor.h"

/*
#include "pit.h"
#include "interrupts.h"
#include memory/memory.h"
*/



struct multiboot_info {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};

int kernel_main();

// End of the kernel image, defined elsewhere.
extern uint32_t end;

int main(uint32_t magic, struct multiboot_info* mb_info_addr) {


monitor_initialize();


//Initialiserer gdt man lagde tidligere
init_gdt();

/*
// Initialiserer interrupt descriptor table (IDT)
init_idt();

// Initialiserer hardware interrupts
init_irq();

// Initialiserer kernelens minne manager ved å gi den en adresse til hvor kernelen slutter
init_kernel_memory(&end);

// Initialiserer paging for minnehåndtering
init_paging();

// Printer informasjon om minne
print_memory_layout();

// Initialiserer PIT (Programmable Interval Timer)
init_pit();
*/


printf("Hello World\n"); // Printer ut Hello World

// Call cpp kernel_main (defined in kernel.cpp)
return kernel_main();
}

