#ifndef SD_UTILS
#define SD_UTILS
#include <stdlib.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

extern unsigned char valueinarray(unsigned val, const unsigned *arr, size_t arr_s);

#endif