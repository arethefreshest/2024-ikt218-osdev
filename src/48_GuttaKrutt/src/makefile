# Makefile for kernel

# Compiler and flags
CC = i686-elf-gcc
AS = i686-elf-as
LD = i686-elf-ld
CFLAGS = -Wall -Wextra -std=gnu99 -ffreestanding -O2 -nostdlib

# Directories
SRCDIR = src
BUILDDIR = build
INCDIR = include

# Files
KERNEL_BIN = kernel.bin
KERNEL_IMG = kernel.img
LINKER_SCRIPT = linker.ld

# Source and object files
C_SOURCES = $(wildcard $(SRCDIR)/*.c)
ASM_SOURCES = $(wildcard $(SRCDIR)/*.asm)
C_OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(C_SOURCES))
ASM_OBJECTS = $(patsubst $(SRCDIR)/%.asm, $(BUILDDIR)/%.o, $(ASM_SOURCES))

# Default target
all: $(KERNEL_BIN) $(KERNEL_IMG)

# Build kernel binary
$(KERNEL_BIN): $(C_OBJECTS) $(ASM_OBJECTS)
	$(LD) -o $@ -T $(LINKER_SCRIPT) $(C_OBJECTS) $(ASM_OBJECTS)

# Create kernel image
$(KERNEL_IMG): $(KERNEL_BIN)
	dd if=$(KERNEL_BIN) of=$@ bs=512 count=1

# Compile C source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# Assemble ASM source files
$(BUILDDIR)/%.o: $(SRCDIR)/%.asm
	$(AS) $< -o $@

# Clean up build files
clean:
	rm -f $(BUILDDIR)/*.o $(KERNEL_BIN) $(KERNEL_IMG)