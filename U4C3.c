#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "ws2818b.pio.h"

#include "includes/teclado.h"
#include "includes/renderizarFrame.h"

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 7

// Definição de pixel GRB
struct pixel_t {
  uint8_t G, R, B; // Três valores de 8-bits compõem um pixel.
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t; // Mudança de nome de "struct pixel_t" para "npLED_t" por clareza.

npLED_t leds[LED_COUNT];

PIO np_pio;
uint sm;


// Inicializa a matriz de LEDs.
void matrizInit(uint pin) {

  uint offset = pio_add_program(pio0, &ws2818b_program);
  np_pio = pio0;

  sm = pio_claim_unused_sm(np_pio, false);
  if (sm < 0) {
    np_pio = pio1;
    sm = pio_claim_unused_sm(np_pio, true); 
  }

  ws2818b_program_init(np_pio, sm, offset, pin, 800000.f);

  for (uint i = 0; i < LED_COUNT; ++i) {
    leds[i].R = 0;
    leds[i].G = 0;
    leds[i].B = 0;
  }
}

// Define pixel na matriz de LEDs.
void setMatrizLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b) {
  leds[index].R = r;
  leds[index].G = g;
  leds[index].B = b;
}

// Limpa a matriz de LEDs.
void npClear() {
  for (uint i = 0; i < LED_COUNT; ++i)
    setMatrizLED(i, 0, 0, 0);
}

// Escreve o buffer de pixels na matriz.    
void npWrite() {
  for (uint i = 0; i < LED_COUNT; ++i) {
    pio_sm_put_blocking(np_pio, sm, leds[i].G);
    pio_sm_put_blocking(np_pio, sm, leds[i].R);
    pio_sm_put_blocking(np_pio, sm, leds[i].B);
  }
  sleep_us(100); 
}

int main() {
    stdio_init_all(); 
    keypad_init();

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
