#include <stdlib.h>
#include "utils.h"

unsigned char valueinarray(unsigned val, const unsigned *arr, size_t arr_s) {
    for (size_t i = 0; i < arr_s; ++i) {
        if (val == arr[i])
            return 0;
    }
    return 1;
}