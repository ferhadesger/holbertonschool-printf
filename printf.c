#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int _printf(const char *format, ...) {
    va_list args;
    int x = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == '\0')
                break;
            if (*format == 'c') {
                int c = va_arg(args, int);
                write(1, &c, 1);
                x++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                if (s == NULL) {
                    write(1, "(null)", 6);
                    x += 6;
                } else {
                    while (*s != '\0') {
                        write(1, s, 1);
                        s++;
                        x++;
                    }
                }
            } else if (*format == '%') {
                write(1, "%", 1);
                x++;
            } else if (*format == 'd' || *format == 'i') {
                long n = va_arg(args, long);
                if (n == INT_MIN) {
                    write(1, "-2147483648", 11);
                    x += 11;
                } else {
                    char buffer[1024];
                    int i = 0;
                    if (n < 0) {
                        write(1, "-", 1);
                        x++;
                        n = -n;
                    }
                    if (n == 0) {
                        buffer[i++] = '0';
                    } else {
                        while (n != 0) {
                            buffer[i++] = '0' + (n % 10);
                            n /= 10;
                        }
                    }
                    while (i > 0) {
                        write(1, &buffer[--i], 1);
                        x++;
                    }
                }
            } else {
                write(1, "%", 1);
                write(1, format, 1);
                x += 2;
            }
        } else {
            write(1, format, 1);
            x++;
        }
        format++;
    }

    va_end(args);
    return x;
}

