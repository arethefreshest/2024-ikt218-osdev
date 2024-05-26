/*
#include "libc/stdarg.h"
#include "libc/stdint.h"
#include "libc/stdio.h"

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
*/
#include "libc/stdarg.h"
#include "libc/stdint.h"
#include "libc/stdio.h"
#include "monitor.h"

int printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    // Assuming a buffer size of 1024 is enough for our needs
    char buffer[1024];
    char* str = buffer;

    // Process the format string
    while (*format) {
        if (*format == '%' && *(format + 1) == 's') {
            format += 2;
            char* s = va_arg(args, char*);
            while (*s) {
                *str++ = *s++;
            }
        } else {
            *str++ = *format++;
        }
    }
    *str = '\0'; // Null-terminate the string

    // Write the string to the terminal
    monitor_writestring(buffer);

    va_end(args);
    return 0;
}
