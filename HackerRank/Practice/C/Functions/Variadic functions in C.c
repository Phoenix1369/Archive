#include <stdarg.h>
#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int val = 0;
    for (int i = 0; i < count; ++i) {
        int cur = va_arg(args, int);
        val += cur;
    }
    va_end(args);
    return val;
}

int min(int count, ...) {
    va_list args;
    va_start(args, count);

    int val = MAX_ELEMENT;
    for (int i = 0; i < count; ++i) {
        int cur = va_arg(args, int);
        val = (cur < val) ? cur : val;
    }
    va_end(args);
    return val;
}

int max(int count, ...) {
    va_list args;
    va_start(args, count);

    int val = MIN_ELEMENT;
    for (int i = 0; i < count; ++i) {
        int cur = va_arg(args, int);
        val = (cur > val) ? cur : val;
    }
    va_end(args);
    return val;
}
