#include "libc/stdarg.h"
#include "libc/stdint.h"
#include "libc/stdio.h"
#include "monitor.h"

extern void terminal_write(const char* str);

int printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

//Buffer størrelse til stringen, dette vi være maks størrelse
    char buffer[1024];
    char* str = buffer;

    // Kpoierer format stringen til bufferen
    while (*format) {
        *str++ = *format++;
    }
    *str = '\0'; // Null-terminate the string

//skriver ut stringen til terminalen fra bufferen
    terminal_write(buffer);

    va_end(args);
    return 0;
}
