#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2818b.pio.h"

// Definição do número de LEDs e pino.
#define LED_COUNT 25
#define LED_PIN 7

// Definição de pixel GRB
struct pixel_t {
  uint8_t G, R, B; // Três valores de 8-bits compõem um pixel.
};
typedef struct pixel_t pixel_t;
typedef pixel_t npLED_t; // Mudança de nome de "struct pixel_t" para "npLED_t" por clareza.

PIO np_pio;
uint sm;


// Inicializa a matriz de LEDs.
void matrizInit(uint pin, npLED_t leds[]) {

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
void setMatrizLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b, npLED_t leds[]) {
  leds[index].R = r;
  leds[index].G = g;
  leds[index].B = b;
}

// Limpa a matriz de LEDs.
void npClear(npLED_t leds[]) {
  for (uint i = 0; i < LED_COUNT; ++i)
    setMatrizLED(i, 0, 0, 0, leds);
}

// Escreve o buffer de pixels na matriz.    
void npWrite(npLED_t leds[]) {
  for (uint i = 0; i < LED_COUNT; ++i) {
    pio_sm_put_blocking(np_pio, sm, leds[i].G);
    pio_sm_put_blocking(np_pio, sm, leds[i].R);
    pio_sm_put_blocking(np_pio, sm, leds[i].B);
  }
  sleep_us(100); 
}