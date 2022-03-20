#include <stdio.h>
#include "pico/stdlib.h"


int main() {
    stdio_init_all();

    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);

    while(1) {
        gpio_put(25, 1);
        printf("LED ON!\n");
        sleep_ms(500);

        gpio_put(25, 0);
        printf("LED OFF!\n");
        sleep_ms(500);
    }
}