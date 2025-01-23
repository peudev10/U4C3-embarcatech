#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "ws2818b.pio.h"

#include "includes/teclado.h"
#include "includes/funcoesMatriz.h"

npLED_t leds[LED_COUNT];

int main() {
    stdio_init_all(); 
    keypad_init();

    matrizInit(LED_PIN, leds);
    setMatrizLED(22, 255, 0, 0, leds);
    sleep_ms(200);
    npWrite(leds);



    while (true) {
       char key = keypad_read();
       
        if (key == '1') {
            printf("Você pressionou 1\n"); // implementação da funcionalidade 1
        } else if (key == '2') {
            printf("Você pressionou 2\n"); // implementação da funcionalidade 2
        } else if (key == '3') {
            printf("Você pressionou 3\n"); // implementação da funcionalidade 3
        } else if (key == '4') {
            printf("Você pressionou 4\n"); // implementação da funcionalidade 4
        } else if (key == '5') {
            printf("Você pressionou 5\n"); // implementação da funcionalidade 5
        } else if (key == '6') {
            printf("Você pressionou 6\n"); // implementação da funcionalidade 6
        } else if (key == '7') {
            printf("Você pressionou 7\n"); // implementação da funcionalidade 7
        } else if (key == '8') {
            printf("Você pressionou 8\n"); // implementação da funcionalidade 8
        } else if (key == '9') {
            printf("Você pressionou 9\n"); // implementação da funcionalidade 9
        } else if (key == '0') {
            printf("Você pressionou 0\n"); // implementação da funcionalidade 10
        } else if (key == 'A') {
            printf("Você pressionou A\n"); // implementação da funcionalidade 11
        } else if (key == 'B') {
            printf("Você pressionou B\n"); // implementação da funcionalidade 12
        } else if (key == 'C') {
            printf("Você pressionou C\n"); // implementação da funcionalidade 13
        } else if (key == 'D') {
            printf("Você pressionou D\n"); // implementação da funcionalidade 14
        } else if (key == '*') {
            printf("Você pressionou *\n"); // implementação da funcionalidade 15
        } else if (key == '#') {
            printf("Você pressionou #\n"); // implementação da funcionalidade 16
        } else {
            printf("Tecla não reconhecida\n"); // implementação da funcionalidade 17
        }
    }
}
