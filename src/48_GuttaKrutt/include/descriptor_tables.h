#ifndef DESCRIPTOR_TABLES_H
#define DESCRIPTOR_TABLES_H

#include "libc/system.h"    


// Number of GDT entries
#define GDT_ENTRIES 5

// GDT entry structure
struct gdt_entry_t {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

// GDT pointer structure
struct gdt_ptr_t {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

// GDT functions
void init_gdt();
void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);

// External declarations for the assembly functions
extern void gdt_flush(uint32_t gdt_ptr);
// extern void idt_flush(uint32_t idt_ptr);

static struct gdt_entry_t gdt[GDT_ENTRIES];
static struct gdt_ptr_t gdt_ptr;

#endif // DESCRIPTOR_TABLES_H



