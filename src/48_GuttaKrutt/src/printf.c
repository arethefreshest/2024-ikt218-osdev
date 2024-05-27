#include "libc/stdarg.h"
#include "libc/stdint.h"
#include "libc/stdio.h"
#include "monitor.h"

//extern void terminal_write(const char* str);

int printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

//Buffer størrelse til stringen, dette vi være maks størrelse
    char buffer[1024];
    char* str = buffer;

    // Kpoierer format stringen til bufferen
    while (*format) {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c': {
                char c = va_arg(args, int);
                *str++ = c;
                break;
            }
            case 'd': {
                int num = va_arg(args, int);
                char temp[10];
                int i = 0;
                if (num < 0)
                {
                    *str++ = '-';
                    num = -num;
                }
                if (num == 0)
                {
                    *str++ = '0';
                } else {
                    while (num > 0)
                    {
                        temp[i++] = (char) ('0' + (num % 10));
                        num /= 10;
                    }
                    while (i > 0)
                    {
                        *str++ = temp[--i];
                    }
                }
                break;
            }
            case 's': {
                char* s = va_arg(args, char*);
                while (*s)
                {
                    *str++ = *s++;
                }
                break;
            }
            case 'x': {
                unsigned int num = va_arg(args, unsigned int);
                char temp[8];
                int i = 0;
                if (num == 0) {
                    *str++ = '0';
                } else {
                    while (num > 0)
                    {
                        int rem = num % 16;
                        temp[i++] = (char) (rem < 10 ? '0' + rem : 'a' + (rem - 10));
                        num /= 16;
                    }
                    while (i > 0) {
                        *str++ = temp[--i];
                    }
                }
                break;
            }
            default:
                *str++ = '%';
                *str++ = *format;
                break;
            }
        } else {
            *str++ = *format;
        }
        format++;
    }
    *str = '\0'; // Null-terminate the string

    // Skriver ut stringen til terminalen fra bufferen
    terminal_write(buffer);

    va_end(args);
    return 0;
}
