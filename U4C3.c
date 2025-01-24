#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

#include "ws2818b.pio.h"

#include "includes/funcoesMatriz.h"
#include "includes/teclado.h"
#include "includes/convertePixels.h"

#include "animacoes/teste.h"

#define MATRIX_ROWS 5
#define MATRIX_COLS 5
#define MATRIX_DEPTH 3

void a1();
void a2(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);

// Funções obrigatórias
void acendeAzulTotal(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]);   

int main() {
    npLED_t leds[LED_COUNT];
    int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH];

    stdio_init_all(); 
    keypad_init();

    matrizInit(LED_PIN, leds);

    while (true) {

        char key = keypad_read();
       
        if (key == '1') {
            printf("Você pressionou 1\n"); // implementação da animação 1
            a1(16, leds, rgb_matrix);
        } else if (key == '2') {
            a2(leds, rgb_matrix);
            printf("Você pressionou 2\n"); // implementação da animação 2
        } else if (key == '3') {
            printf("Você pressionou 3\n"); // implementação da animação 3
        } else if (key == '4') {
            printf("Você pressionou 4\n"); // implementação da animação 4
        } else if (key == '5') {
            printf("Você pressionou 5\n"); // implementação da animação 5
        } else if (key == '6') {
            printf("Você pressionou 6\n"); // implementação da animação 6
        } else if (key == '7') {
            printf("Você pressionou 7\n"); // implementação da animação 7
        } else if (key == '8') {
            printf("Você pressionou 8\n"); // implementação da animação 8
        } else if (key == '9') {
            printf("Você pressionou 9\n"); // implementação da animação 9
        } else if (key == '0') {
            printf("Você pressionou 0\n"); // implementação da animação 10
        } else if (key == 'A') {
            printf("Você pressionou A\n"); // implementação da animação 11
        } else if (key == 'B') {
            acendeAzulTotal(leds, rgb_matrix);
            printf("Você pressionou B\n"); // implementação da animação 12
        } else if (key == 'C') {
            printf("Você pressionou C\n"); // implementação da animação 13
        } else if (key == 'D') {
            printf("Você pressionou D\n"); // implementação da animação 14
        } else if (key == '*') {
            printf("Você pressionou *\n"); // implementação da animação 15
        } else if (key == '#') {
            printf("Você pressionou #\n"); // implementação da animação 16
        } else {
            printf("Tecla não reconhecida\n"); // implementação da animação 17
        }

        sleep_ms(500);
    }
 
}


// Na estrutura da função a1, o parâmetro frames é o número de frames na animação, definida na hora da criação do array animacao1.
void a1(int frames, npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
        for (int j = 0; j < frames; j++) {
            convertARGBtoMatriz(animacao1[j], rgb_matrix);
            spriteWirite(rgb_matrix, leds);
            matrizWrite(leds); 
            sleep_ms(100); // Define a velocidade da animação
        }
        turnOffLEDs(leds); // Adicione trun off após o loop interno para desligar a matriz
}


void a2(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    // Ligar linha por linha
    for (int linha = 0; linha < MATRIX_ROWS; linha++) {
        
        for (int col = 0; col < MATRIX_COLS; col++) {
            rgb_matrix[linha][col][0] = 255; // R
            rgb_matrix[linha][col][1] = 0;   // G
            rgb_matrix[linha][col][2] = 0;   // B
        }
        spriteWirite(rgb_matrix, leds);
        matrizWrite(leds); 
        sleep_ms(500); // Pausa para visualizar a linha acendendo
    }

    // Desligar linha por linha
    for (int linha = 0; linha < MATRIX_ROWS; linha++) {
        
        for (int col = 0; col < MATRIX_COLS; col++) {
            rgb_matrix[linha][col][0] = 0; // R
            rgb_matrix[linha][col][1] = 0; // G
            rgb_matrix[linha][col][2] = 0; // B
        }
        spriteWirite(rgb_matrix, leds);
        matrizWrite(leds); 
        sleep_ms(500); // Pausa para visualizar a linha apagando
    }
}

void acendeAzulTotal(npLED_t leds[], int rgb_matrix[MATRIX_ROWS][MATRIX_COLS][MATRIX_DEPTH]) {
    
    for (int linha = 0; linha < MATRIX_ROWS; linha++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            rgb_matrix[linha][col][0] = 0;   
            rgb_matrix[linha][col][1] = 0;   
            rgb_matrix[linha][col][2] = 255; // B (azul, 100% intensidade)
        }
    }
    // Atualiza os LEDs com a matriz configurada
    spriteWirite(rgb_matrix, leds);
    matrizWrite(leds); 
}