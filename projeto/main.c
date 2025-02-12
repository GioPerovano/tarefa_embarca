#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

#define PINO_SERVOMOTOR 22
#define PINO_LED 12

int pwm_servomotor_slice;
int pwm_led_slice;

void configurar_pwm() {
    printf("****************INÍCIO DO PROGRAMA****************\n");
    
    // Configurar o pino do servomotor para PWM
    gpio_set_function(PINO_SERVOMOTOR, GPIO_FUNC_PWM);
    pwm_servomotor_slice = pwm_gpio_to_slice_num(PINO_SERVOMOTOR);
    pwm_set_clkdiv(pwm_servomotor_slice, 125.0f); // Frequência de 50Hz
    pwm_set_wrap(pwm_servomotor_slice, 2500); // Período ajustado para 50Hz com clkdiv 125
    pwm_set_enabled(pwm_servomotor_slice, true);
    printf("Servomotor configurado no slice %d.\n", pwm_servomotor_slice);
    
    // Configurar o LED para PWM
    gpio_set_function(PINO_LED, GPIO_FUNC_PWM);
    pwm_led_slice = pwm_gpio_to_slice_num(PINO_LED);
    pwm_set_wrap(pwm_led_slice, 255); // PWM de 8 bits para controle de brilho do LED
    pwm_set_enabled(pwm_led_slice, true);
    printf("LED configurado no slice %d.\n\n", pwm_led_slice);
}

void mover_servomotor_para_posicao(int angulo) {
    int largura_pulso = 500 + (angulo * (2400 - 500)) / 180; // Mapeamento do ângulo para largura de pulso
    pwm_set_gpio_level(PINO_SERVOMOTOR, largura_pulso);
}

void ajustar_brilho_led(int angulo) {
    int brilho = (angulo * 255) / 180; // Mapeia o ângulo 0°-180° para intensidade 0-255
    pwm_set_gpio_level(PINO_LED, brilho);
}

int main() {
    stdio_init_all();
    configurar_pwm();
    
    printf("INICIANDO O CONTROLE DO SERVOMOTOR E AJUSTANDO O BRILHO DO LED...\n\n");
    
    while (true) {
        // Movendo o servomotor para 180 graus
        printf("Movendo servomotor para a posição de 180° por 5 segundos!\n");
        mover_servomotor_para_posicao(180);
        ajustar_brilho_led(180);
        sleep_ms(5000); // Pausa por 5 segundos

        // Movendo o servomotor para 90 graus
        printf("Movendo servomotor para a posição de 90° por 5 segundos!\n");
        mover_servomotor_para_posicao(90);
        ajustar_brilho_led(90);
        sleep_ms(5000);

        // Movendo o servomotor para 0 graus
        printf("Movendo servomotor para a posição de 0° por 5 segundos!\n");
        mover_servomotor_para_posicao(0);
        ajustar_brilho_led(0);
        sleep_ms(5000);

        // Realizando varredura suave do servomotor de 0° a 180° e de volta
        printf("Realizando varredura suave do servomotor de 0° a 180°...\n");
        for (int angulo = 0; angulo <= 180; angulo += 5) {
            mover_servomotor_para_posicao(angulo);
            ajustar_brilho_led(angulo);
            sleep_ms(20); // Intervalo de 20ms para movimento suave
        }
        for (int angulo = 180; angulo >= 0; angulo -= 5) {
            mover_servomotor_para_posicao(angulo);
            ajustar_brilho_led(angulo);
            sleep_ms(20); // Intervalo de 20ms para movimento suave
        }
    }
}
