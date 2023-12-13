#include "lib.h"

#define LSR_RX_READY (1 << 0)
#define EOF 0

char *os_gets(char *s)
{
    int ch;
    char *p = s;

    while ((ch = os_getc()) != '\n' && ch != EOF) {
        if (ch == -1) {
            continue;
        }
        *s = (char) ch;
        s++;
    }

    *s = '\0';
    return p;
}

int os_getc(void)
{
    if (*UART_LSR & LSR_RX_READY) {
        return *UART_RHR == '\r' ? '\n' : *UART_RHR;
    } else {
        return -1;
    }
}

int os_putc(char ch)
{
    while ((*UART_LSR & UART_LSR_EMPTY_MASK) == 0)
        ;
    return *UART_THR = ch;
}

void os_puts(char *s)
{
    while (*s)
        os_putc(*s++);
}

int os_vsnprintf(char *out, size_t n, const char *s, va_list vl)
{
    int format = 0;
    int longarg = 0;
    size_t pos = 0;
    for (; *s; s++) {
        if (format) {
            switch (*s) {
            case 'l': {
                longarg = 1;
                break;
            }
            case 'p': {
                longarg = 1;
                if (out && pos < n) {
                    out[pos] = '0';
                }
                pos++;
                if (out && pos < n) {
                    out[pos] = 'x';
                }
                pos++;
            }
            case 'x': {
                long num = longarg ? va_arg(vl, long) : va_arg(vl, int);
                int hexdigits = 2 * (longarg ? sizeof(long) : sizeof(int)) - 1;
                for (int i = hexdigits; i >= 0; i--) {
                    int d = (num >> (4 * i)) & 0xF;
                    if (out && pos < n) {
                        out[pos] = (d < 10 ? '0' + d : 'a' + d - 10);
                    }
                    pos++;
                }
                longarg = 0;
                format = 0;
                break;
            }
            case 'd': {
                long num = longarg ? va_arg(vl, long) : va_arg(vl, int);
                if (num < 0) {
                    num = -num;
                    if (out && pos < n) {
                        out[pos] = '-';
                    }
                    pos++;
                }
                long digits = 1;
                for (long nn = num; nn /= 10; digits++)
                    ;
                for (int i = digits - 1; i >= 0; i--) {
                    if (out && pos + i < n) {
                        out[pos + i] = '0' + (num % 10);
                    }
                    num /= 10;
                }
                pos += digits;
                longarg = 0;
                format = 0;
                break;
            }
            case 's': {
                const char *s2 = va_arg(vl, const char *);
                while (*s2) {
                    if (out && pos < n) {
                        out[pos] = *s2;
                    }
                    pos++;
                    s2++;
                }
                longarg = 0;
                format = 0;
                break;
            }
            case 'c': {
                if (out && pos < n) {
                    out[pos] = (char) va_arg(vl, int);
                }
                pos++;
                longarg = 0;
                format = 0;
                break;
            }
            default:
                break;
            }
        } else if (*s == '%') {
            format = 1;
        } else {
            if (out && pos < n) {
                out[pos] = *s;
            }
            pos++;
        }
    }
    if (out && pos < n) {
        out[pos] = 0;
    } else if (out && n) {
        out[n - 1] = 0;
    }
    return pos;
}

static char out_buf[1000];  // buffer for lib_vprintf()

int os_vprintf(const char *s, va_list vl)
{
    int res = os_vsnprintf(NULL, -1, s, vl);
    if (res + 1 >= sizeof(out_buf)) {
        os_puts("error: lib_vprintf() output string size overflow\n");
        while (1) {
        }
    }
    os_vsnprintf(out_buf, res + 1, s, vl);
    os_puts(out_buf);
    return res;
}

int os_printf(const char *s, ...)
{
    int res = 0;
    va_list vl;
    va_start(vl, s);
    res = os_vprintf(s, vl);
    va_end(vl);
    return res;
}

//delay
void os_delay(volatile int num)
{
    num *= 50000;
    while(num--)
        ;
}