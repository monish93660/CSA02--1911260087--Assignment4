#include <stdio.h>
#include "shared.h"
int main(void) {
    printf("extern tokens: %d %d %d\\n",
           next_shared_token(),next_shared_token(),next_shared_token());
    return 0;
}