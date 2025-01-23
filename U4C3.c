#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "ws2818b.pio.h"

#include "includes/teclado.h"



int main()
{
    stdio_init_all(); 
    keypad_init();

    while (true) {
       char key = keypad_read();
        if (key != 0) {
            printf("Key pressed: %c\n", key);
        }
        sleep_ms(50);
    }
}
