#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/stdbool.h"
#include <multiboot2.h>
#include "descriptor_tables.h"  // Inkluderer header file for gdt filen



struct multiboot_info {
    uint32_t size;
    uint32_t reserved;
    struct multiboot_tag *first;
};

int kernel_main();

int main(uint32_t magic, struct multiboot_info* mb_info_addr) {

//Initialiserer gdt man lagde tidligere
init_gdt();

printf("Hello World\n"); // Printer ut Hello World

    // Call cpp kernel_main (defined in kernel.cpp)
    return kernel_main();
}

